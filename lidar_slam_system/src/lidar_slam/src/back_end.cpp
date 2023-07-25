#include "back_end.h"

namespace lidarslam{
static double q_[4] = {0, 0, 0, 1};
static double t_[3] = {0, 0, 0};
BackEnd::BackEnd(const std::string &name, Channel<FrontEndOut> &channel_in)
    : Node(name), _input_channel(channel_in), _publish_global_signal(false),
    q_w_last(q_), t_w_last(t_)
{
    pub_global_map = this -> create_publisher<sensor_msgs::msg::PointCloud2>("/global_map", 1);

    // 线程
    _run_thread = std::thread(&BackEnd::run, this);
    _global_map_thread = std::thread(&BackEnd::publishGlobalMap, this);

    globalMap.reset(new CloudType());

    keyPointCorner.reset(new CloudType());
    keyPointSurf.reset(new CloudType());
    subMapCorner.reset(new CloudType());
    subMapSurf.reset(new CloudType());

    kdtreeCorner.reset(new pcl::KdTreeFLANN<PointType>());
    kdtreeSurf.reset(new pcl::KdTreeFLANN<PointType>());

    downSampleCorner.reset(new pcl::VoxelGrid<PointType>());
    downSampleCorner -> setLeafSize(0.2, 0.2, 0.2);
    downSampleSurf.reset(new pcl::VoxelGrid<PointType>());
    downSampleSurf -> setLeafSize(0.4, 0.4, 0.4);

    downSampleCornerFromMap.reset(new pcl::VoxelGrid<PointType>());
    downSampleCornerFromMap -> setLeafSize(0.4, 0.4, 0.4);
    downSampleSurfFromMap.reset(new pcl::VoxelGrid<PointType>());
    downSampleSurfFromMap -> setLeafSize(0.4, 0.4, 0.4);

    downSampleGlobalMap.reset(new pcl::VoxelGrid<PointType>());
    downSampleGlobalMap -> setLeafSize(1.0, 1.0, 1.0);

    segmentCloud.reset(new CloudType());
    groundCloud.reset(new CloudType());

    q_keyframe_last = Eigen::Quaterniond(1, 0, 0, 0);
    t_keyframe_last = Eigen::Vector3d(0, 0, 0);
    q_pre = Eigen::Quaterniond(1, 0, 0, 0);
    t_pre = Eigen::Vector3d(0, 0, 0);

    // 因子图
    gtsam::ISAM2Params parameters;
    parameters.relinearizeThreshold = 0.01;
    parameters.relinearizeSkip = 1;
    parameters.factorization = gtsam::ISAM2Params::QR;
    isam = new gtsam::ISAM2(parameters);

    previousPosPoint.x = 0;
    previousPosPoint.y = 0;
    previousPosPoint.z = 0;
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
                transToGlobalMap(allSegmentCloud[globalMapIndex[i]], temp, keyFramePoses[globalMapIndex[i]]);
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

        keyPointCorner = in.cornerLast;
        keyPointSurf = in.surfLast;
        segmentCloud = in.segment_cloud;
        odom = in.laserOdometry;
        extractSurroundingKeyFrames();
        scan2MapOptimization();
        saveKeyFramesAndFactor();

        //--------------------
        _cycle_count++;

        if((_cycle_count % 1) == 0){
            _publish_global_signal.send(true);
        }
    }
}

void BackEnd::extractSurroundingKeyFrames(){
    subMapCorner -> clear();
    subMapSurf -> clear();
    for(size_t i = 0; i < queCorner.size(); ++i){
        CloudTypePtr temp(new CloudType());
        transToGlobalMap(allCornerCloud[queCorner[i]], temp, keyFramePoses[queCorner[i]]);
        *subMapCorner += *temp;
    }
    for(size_t i = 0; i < queSurf.size(); ++i){
        CloudTypePtr temp(new CloudType());
        transToGlobalMap(allSurfCloud[queSurf[i]], temp, keyFramePoses[queSurf[i]]);
        *subMapSurf += *temp;
    }

    downsample(subMapCorner, downSampleCornerFromMap);
    downsample(subMapSurf, downSampleSurfFromMap);
}

void BackEnd::scan2MapOptimization(){
    // 转世界坐标系
    Eigen::Quaterniond q_cur{odom.pose.pose.orientation.w,
                             odom.pose.pose.orientation.x,
                             odom.pose.pose.orientation.y,
                             odom.pose.pose.orientation.z};
    Eigen::Vector3d t_cur{odom.pose.pose.position.x,
                          odom.pose.pose.position.y,
                          odom.pose.pose.position.z};
    
    Eigen::Vector3d t_odom = q_pre.inverse() * t_cur - t_pre;
    Eigen::Quaterniond q_odom = q_pre.inverse() * q_cur;

    t_w_last = t_w_last + q_w_last * t_odom;
    q_w_last = q_w_last * q_odom;

    q_pre = q_cur;
    t_pre = t_cur;

    RCLCPP_INFO(this -> get_logger(), "x:%f, y:%f, z:%f",
        t_w_last.x(), t_w_last.y(), t_w_last.z());

    auto transform = [&](const PointType &pi, PointType &po){
        Eigen::Vector3d p(pi.x, pi.y, pi.z);
        p = q_w_last * p + t_w_last;
        po.x = p.x();
        po.y = p.y();
        po.z = p.z();
        po.intensity = pi.intensity;
    };

    if(!keyFramePoses.empty()){
        kdtreeCorner -> setInputCloud(subMapCorner);
        kdtreeCorner -> setInputCloud(subMapSurf);

        int cornerNum = keyPointCorner -> size();
        int surfNum = keyPointSurf -> size();

        PointType pointSel;
        std::vector<int> pointSearchInd;
        std::vector<float> pointSearchSqDis;

        /*
        for(size_t opti_counter = 0; opti_counter < 4; ++opti_counter){
            ceres::LossFunction *loss_function = new ceres::HuberLoss(0.1);
            ceres::Problem::Options problem_options;

            ceres::Problem problem(problem_options);
            ceres::Manifold *q_manifold = new ceres::EigenQuaternionManifold;
            problem.AddParameterBlock(q_, 4, q_manifold);
            problem.AddParameterBlock(t_, 3);

            // 边缘点
            for(int i = 0; i < cornerNum; ++i){
                transform(keyPointCorner -> points[i], pointSel);
                kdtreeCorner -> nearestKSearch(pointSel, 5, pointSearchInd, pointSearchSqDis);

                if(pointSearchSqDis[4] < 1.0){
                    Eigen::Matrix3f matA;
                    Eigen::Matrix<float, 1, 3> matD;
                    Eigen::Matrix3f matV;

                    float cx = 0, cy = 0, cz = 0;
                    for(int j = 0; j < 5; ++j){
                        cx += subMapCorner -> points[pointSearchInd[j]].x;
                        cy += subMapCorner -> points[pointSearchInd[j]].y;
                        cz += subMapCorner -> points[pointSearchInd[j]].z;
                    }
                    cx /= 5;
                    cy /= 5;
                    cz /= 5;

                    float a11 = 0, a12 = 0, a13 = 0, a22 = 0, a23 = 0, a33 = 0;
                    for(int j = 0; j < 5; ++j){
                        float ax = subMapCorner -> points[pointSearchInd[j]].x - cx;
                        float ay = subMapCorner -> points[pointSearchInd[j]].y - cy;
                        float az = subMapCorner -> points[pointSearchInd[j]].z - cz;

                        a11 += ax * ax;
                        a12 += ax * ay;
                        a13 += ax * az;
                        a22 += ay * ay;
                        a23 += ay * az;
                        a33 += az * az;
                    }
                    a11 /= 5;
                    a12 /= 5;
                    a13 /= 5;
                    a22 /= 5;
                    a23 /= 5;
                    a33 /= 5;

                    matA(0, 0) = a11;
                    matA(0, 1) = a12;
                    matA(0, 2) = a13;
                    matA(1, 0) = a12;
                    matA(1, 1) = a22;
                    matA(1, 2) = a23;
                    matA(2, 0) = a13;
                    matA(2, 1) = a12;
                    matA(2, 2) = a33;

                    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3f> esolver(matA);

                    matD = esolver.eigenvalues().real();
                    matV = esolver.eigenvectors().real();

                    if(matD[2] > 3 * matD[1]){
                        Eigen::Vector3d curr_p{keyPointCorner -> points[i].x, 
                                               keyPointCorner -> points[i].y, 
                                               keyPointCorner -> points[i].z};
                        Eigen::Vector3d point_a{cx + 0.1 * matV(2, 0),
                                                cy + 0.1 * matV(2, 1),
                                                cz + 0.1 * matV(2, 2)};
                        Eigen::Vector3d point_b{cx - 0.1 * matV(2, 0),
                                                cy - 0.1 * matV(2, 1),
                                                cz - 0.1 * matV(2, 2)};
                        ceres::CostFunction *cost_function = 
                            LidarEdgeFactor::Create(curr_p, point_a, point_b, 1);
                        problem.AddResidualBlock(cost_function, loss_function, q_, t_);
                    }
                }
            }

            // 地面点
            for(int i = 0; i < surfNum; ++i){
                transform(keyPointSurf -> points[i], pointSel);
                kdtreeSurf -> nearestKSearch(pointSel, 5, pointSearchInd, pointSearchSqDis);

                if(pointSearchSqDis[4] < 1.0){
                    Eigen::Matrix<double, 5, 1> matb;
                    matb.fill(-1);
                    Eigen::Matrix<double, 5, 3> matA;
                    Eigen::Matrix<double, 3, 1> matX;

                    for(int j = 0; j < 5; ++j){
                        matA(j, 0) = subMapSurf -> points[pointSearchInd[j]].x;
                        matA(j, 1) = subMapSurf -> points[pointSearchInd[j]].y;
                        matA(j, 2) = subMapSurf -> points[pointSearchInd[j]].z;
                    }
                    // 求解Ax = b得到平面方程
                    matX = matA.colPivHouseholderQr().solve(matb);

                    double pa = matX(0, 0);
                    double pb = matX(1, 0);
                    double pc = matX(2, 0);
                    double pd = 1;
                    // 归一化
                    double ps = sqrt(pa * pa + pb * pb + pc * pc);
                    pa /= ps;
                    pb /= ps;
                    pc /= ps;
                    pd /= ps;


                    // 判断平面是否合理
                    bool planeValid = true;
                    for(int j = 0; j < 5; ++j){
                        if(abs(pa * subMapSurf -> points[pointSearchInd[j]].x +
                               pb * subMapSurf -> points[pointSearchInd[j]].y +
                               pc * subMapSurf -> points[pointSearchInd[j]].z +
                               pd) > 0.2){
                            planeValid = false;
                            break;
                        }
                    }

                    if(planeValid == true){
                        Eigen::Vector3d curr_point{keyPointSurf -> points[i].x,
                                                   keyPointSurf -> points[i].y,
                                                   keyPointSurf -> points[i].z};
                        Eigen::Vector3d norm{pa, pb, pc};
                        ceres::CostFunction *cost_function =
                            LidarPlaneNormFactor::Create(curr_point, norm, pd);
                        problem.AddResidualBlock(cost_function, loss_function, q_, t_);
                    }
                }
            }   


            // 求解
            ceres::Solver::Options options;
            options.linear_solver_type = ceres::DENSE_QR;
            options.max_num_iterations = 5;
            options.minimizer_progress_to_stdout = false;
            ceres::Solver::Summary summary;
            ceres::Solve(options, &problem, &summary);
        }
        */
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

    // 将新关键帧插入滑动窗口
    allCornerCloud.push_back(keyPointCorner);
    keyPointCorner.reset(new CloudType());
    allSurfCloud.push_back(keyPointSurf);
    keyPointSurf.reset(new CloudType());
    allSegmentCloud.push_back(segmentCloud);
    segmentCloud.reset(new CloudType());

    int size = keyFramePoses.size();
    queCorner.push_back(size - 1);
    if(queCorner.size() > 50){
        queCorner.pop_front();
    }
    queSurf.push_back(size - 1);
    if(queSurf.size() > 50){
        queSurf.pop_front();
    }

    // 将新关键帧插入地图发布队列
    globalMtx.lock();
    queMap.push(size - 1);
    globalMtx.unlock();
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
        pointAft.x = point.x();
        pointAft.y = point.y();
        pointAft.z = point.z();
        pointAft.intensity = cloud -> points[i].intensity;
        temp -> push_back(pointAft);        
    }
}

} // namespace lidarslam