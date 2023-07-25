#include "back_end.h"

namespace lidarslam{
BackEnd::BackEnd(const std::string &name, Channel<FrontEndOut> &channel_in)
    : Node(name), _input_channel(channel_in), _publish_global_signal(false)
{
    pub_global_map = this -> create_publisher<sensor_msgs::msg::PointCloud2>("/global_map", 1);

    // 线程
    _run_thread = std::thread(&BackEnd::run, this);
    _global_map_thread = std::thread(&BackEnd::publishGlobalMap, this);
}

BackEnd::~BackEnd(){
    _input_channel.send({});
    _run_thread.join();

    _publish_global_signal.send(false);
    _global_map_thread.join();
}

void BackEnd::publishGlobalMap(){
    while(rclcpp::ok()){
        bool ready;
        _publish_global_signal.receive(ready);
        if(ready){
            globalMtx.lock();
            std::vector<int> globalMapIndex;
            while(!queMap.empty()){
                globalMapIndex.push_back(queMap.front());
                queMap.pop();
            }
            globalMtx.unlock();

            // 将新帧插入
            for(size_t i = 0; i < globalMapIndex.size(); ++i){
                CloudTypePtr temp(new CloudType());
                transToGlobalMap(allCornerCloud[i], temp, keyFramePoses[i]);
                downsample(temp, downSampleGlobalMap);
                *globalMap += *temp;
            }

            if(pub_global_map -> get_subscription_count() == 0)
                continue;
            sensor_msgs::msg::PointCloud2 msg;
            pcl::toROSMsg(*globalMap, msg);
            msg.header.frame_id = "map";
            pub_global_map -> publish(msg);
        }
    }
}

void BackEnd::run(){
    static int _cycle_count = 0;
    while(rclcpp::ok()){
        FrontEndOut in;
        _input_channel.receive(in);

        mtx.lock();
        
        keyPointCorner = in.cornerLast;
        keyPointSurf = in.surfLast;
        scan2MapOptimization();
        saveKeyFramesAndFactor();

        mtx.unlock();

        //--------------------
        _cycle_count++;

        if((_cycle_count % 10) == 0){
            _publish_global_signal.send(true);
        }
    }
}

void BackEnd::saveKeyFramesAndFactor(){
    PointType currentPosPoint(t_w_last.x(), t_w_last.y(), t_w_last.z());
    
    // 噪声
    gtsam::Vector6 Vector6(6);
    Vector6 << 1e-6, 1e-6, 1e-6, 1e-8, 1e-8, 1e-6;
    auto priorNoise = gtsam::noiseModel::Diagonal::Variances(Vector6);
    auto odometryNoise = gtsam::noiseModel::Diagonal::Variances(Vector6);

    // 根据距离判断是否为关键帧
    bool saveThisKeyFrame = true;
    if(sqrt((previousPosPoint.x - currentPosPoint.x) *
            (previousPosPoint.x - currentPosPoint.x) +
            (previousPosPoint.y - currentPosPoint.y) *
            (previousPosPoint.y - currentPosPoint.y) +
            (previousPosPoint.z - currentPosPoint.z) *
            (previousPosPoint.z - currentPosPoint.z)) < 0.3){
        saveThisKeyFrame = false;
    }

    // 是关键帧或第一帧，则保存并更新
    if(saveThisKeyFrame == false && !keyFramePoses.empty()) return;

    previousPosPoint = currentPosPoint;

    // 更新gtsam graph
    // 是第一帧
    if(keyFramePoses.empty()){
        gtsamGraph.add(gtsam::PriorFactor<gtsam::Pose3>(
            0,
            gtsam::Pose3(gtsam::Rot3::Quaternion(q_w_last.w(), q_w_last.x(), q_w_last.y(), q_w_last.z()),
                            gtsam::Point3(t_w_last.x(), t_w_last.y(), t_w_last.z())),
            priorNoise));
        initialEstimate.insert(
            0,
            gtsam::Pose3(gtsam::Rot3::Quaternion(q_w_last.w(), q_w_last.x(), q_w_last.y(), q_w_last.z()),
                            gtsam::Point3(t_w_last.x(), t_w_last.y(), t_w_last.z())));
        q_keyframe_last = q_w_last;
        t_keyframe_last = t_w_last;
    }else{
        gtsam::Pose3 poseFrom = gtsam::Pose3(
            gtsam::Rot3::Quaternion(q_keyframe_last.w(), q_keyframe_last.x(), q_keyframe_last.y(), q_keyframe_last.z()),
            gtsam::Point3(t_keyframe_last.x(), t_keyframe_last.y(), t_keyframe_last.z()));
        gtsam::Pose3 poseTo = gtsam::Pose3(
            gtsam::Rot3::Quaternion(q_w_last.w(), q_w_last.x(), q_w_last.y(), q_w_last.z()),
            gtsam::Point3(t_w_last.x(), t_w_last.y(), t_w_last.z()));
        // 加入因子图中
        gtsamGraph.add(gtsam::BetweenFactor<gtsam::Pose3>(
            keyFramePoses.size() - 1, keyFramePoses.size(),
            poseFrom.between(poseTo), odometryNoise));
        initialEstimate.insert(
            keyFramePoses.size(),
            gtsam::Pose3(
                gtsam::Rot3::Quaternion(q_w_last.w(), q_w_last.x(), q_w_last.y(), q_w_last.z()),
                gtsam::Point3(t_w_last.x(), t_w_last.y(), t_w_last.z())));
    }

    // 更新isam
    isam -> update(gtsamGraph, initialEstimate);
    isam -> update();

    gtsamGraph.resize(0);
    initialEstimate.clear();

    // 保存关键帧
    gtsam::Pose3 latestEstimate;

    isamCurrentEstimate = isam -> calculateEstimate();
    latestEstimate = isamCurrentEstimate.at<gtsam::Pose3>(isamCurrentEstimate.size() - 1);

    

    // 更新变换矩阵
    if(keyFramePoses.size() > 1){
        q_w_last.w() = latestEstimate.rotation().toQuaternion().w();
        q_w_last.x() = latestEstimate.rotation().toQuaternion().x();
        q_w_last.y() = latestEstimate.rotation().toQuaternion().y();
        q_w_last.z() = latestEstimate.rotation().toQuaternion().z();
        t_w_last.x() = latestEstimate.translation().x();
        t_w_last.y() = latestEstimate.translation().y();
        t_w_last.z() = latestEstimate.translation().z();

        q_keyframe_last = q_w_last;
        t_keyframe_last = t_w_last;
    }
    pose thisPose;
    thisPose.q = q_w_last;
    thisPose.t = t_w_last;
    keyFramePoses.push_back(thisPose);

    
}

void BackEnd::downsample(CloudTypePtr cloud, pcl::VoxelGrid<PointType>::Ptr filter){
    CloudTypePtr temp(new CloudType());
    cloud -> swap(*temp);
    filter -> setInputCloud(temp);
    filter -> filter(*cloud);
}

void BackEnd::transToGlobalMap(CloudTypePtr cloud, CloudTypePtr temp, pose p){
    for(size_t i = 0; i < cloud -> size(); ++i){
        Eigen::Vector3d point{cloud -> points[i].x,
                              cloud -> points[i].y,
                              cloud -> points[i].z};
        point = p.q * point + p.t;
        PointType pointAft;
        temp -> push_back(pointAft);        
    }
}

} // namespace lidarslam