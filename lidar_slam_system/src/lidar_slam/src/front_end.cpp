#include "front_end.h"

namespace lidarslam{

static const std::string PARAM_DISTANCE = "param.distance";
static const std::string PARAM_MAP_FREQUENCY = "param.map_frequency";

FrontEnd::FrontEnd(const std::string &name, Channel<DataProcessOut> &channel_in, Channel<FrontEndOut> &channel_out)
    : Node(name), _input_channel(channel_in), _output_channel(channel_out), q_w_last(1, 0, 0, 0), t_w_last(0, 0, 0)
{
    pub_laser_odometry = this -> create_publisher<nav_msgs::msg::Odometry>("/laser_odom_init", 1);

    pub_laser_path = this -> create_publisher<nav_msgs::msg::Path>("/laser_odom_path", 1);
    laserPath.header.frame_id = "map";

    // 声明参数
    this -> declare_parameter(PARAM_DISTANCE, nearest_feature_dist_sqr);
    this -> declare_parameter(PARAM_MAP_FREQUENCY, map_frequency);
    // 更新参数
    if(!this -> get_parameter(PARAM_DISTANCE, nearest_feature_dist_sqr)){
        RCLCPP_WARN(this -> get_logger(), "front_end_node: %s not found", PARAM_DISTANCE.c_str());
    }
    if(!this -> get_parameter(PARAM_MAP_FREQUENCY, map_frequency)){
        RCLCPP_WARN(this -> get_logger(), "front_end_node: %s not found", PARAM_MAP_FREQUENCY.c_str());
    }

    _run_thread = std::thread(&FrontEnd::run, this);

    cornerKeyPoints.reset(new CloudType());
    surfKeyPoints.reset(new CloudType());
    cornerLessSharp.reset(new CloudType());
    surfLessFlat.reset(new CloudType());
    laserCloudCornerLast.reset(new CloudType());
    laserCloudSurfLast.reset(new CloudType());
    segmentCloud.reset(new CloudType());
    groundCloud.reset(new CloudType());

    kdtreeCornerLast.reset(new pcl::KdTreeFLANN<PointType>());
    kdtreeSurfLast.reset(new pcl::KdTreeFLANN<PointType>());

    isFirstFrame = true;
}

FrontEnd::~FrontEnd(){
    _input_channel.send({});
    _run_thread.join();
}

void FrontEnd::run(){
    static int _cycle_count = 0;
    while(rclcpp::ok()){
        DataProcessOut in;
        _input_channel.receive(in);

        cornerKeyPoints = in.corner_sharp;
        surfKeyPoints = in.surf_flat;
        cornerLessSharp = in.corner_less_sharp;
        surfLessFlat = in.surf_less_flat;
        segmentCloud = in.segment_cloud;
        groundCloud = in.ground_cloud;
        odometry();
        publishOdometry();

        //-----------------
        _cycle_count++;

        if(_cycle_count == map_frequency){
            FrontEndOut out;
            out.cornerLast.reset(new CloudType());
            out.surfLast.reset(new CloudType());
            
            *out.cornerLast = *laserCloudCornerLast;
            *out.surfLast = *laserCloudSurfLast;
            out.segment_cloud.swap(segmentCloud);
            out.ground_cloud.swap(groundCloud);
            out.laserOdometry = laserOdometry;

            _output_channel.send(std::move(out));
            _cycle_count = 0;
        }
    }
}

void FrontEnd::odometry(){
    // qx, qy, qz, w
    // tx, ty, tz
    double q[4] = {0, 0, 0, 1};
    double t[3] = {0, 0, 0};
    Eigen::Map<Eigen::Quaterniond> q_odom(q);
    Eigen::Map<Eigen::Vector3d> t_odom(t);
    
    // 变换
    auto transform = [&](const PointType &pi, PointType &po){
        Eigen::Vector3d p{pi.x, pi.y, pi.z};
        p = q_odom * p + t_odom;
        po.x = p.x();
        po.y = p.y();
        po.z = p.z();
        po.intensity = pi.intensity;
    };

    // 计算距离
    auto dis = [](const PointType &p1, const PointType &p2){
        float diffx = p1.x - p2.x;
        float diffy = p1.y - p2.y;
        float diffz = p1.z - p2.z;
        double dis = sqrt(diffx * diffx + diffy * diffy + diffz * diffz);
        return dis;
    };

    if(isFirstFrame){
        isFirstFrame = false;
    }else{
        int cornerSharpNum = cornerKeyPoints -> size();
        int surfFlatNum = surfKeyPoints -> size();
        // RCLCPP_INFO_STREAM(this -> get_logger(), "###########################");
        for(size_t opti_counter = 0; opti_counter < 5; ++opti_counter){
            ceres::LossFunction *loss_function = new ceres::HuberLoss(0.1);
            ceres::Problem::Options problem_options;

            ceres::Problem problem(problem_options);
            ceres::Manifold *q_manifold = new ceres::EigenQuaternionManifold;
            problem.AddParameterBlock(q, 4, q_manifold);
            problem.AddParameterBlock(t, 3);

            PointType pointSel;
            std::vector<int> pointSearchInd;
            std::vector<float> pointSearchSqDis;

            // 边缘点
            for(int i = 0; i < cornerSharpNum; ++i){
                transform(cornerKeyPoints -> points[i], pointSel);
                kdtreeCornerLast -> nearestKSearch(pointSel, 1, pointSearchInd, pointSearchSqDis);
                int closestPointInd = -1, minPointInd2 = -1;
                if(pointSearchSqDis[0] < nearest_feature_dist_sqr){
                    closestPointInd = pointSearchInd[0];
                    int closestPointScanID = int(laserCloudCornerLast -> points[closestPointInd].intensity);

                    double minPointSqDis2 = nearest_feature_dist_sqr;
                    for(int j = closestPointInd + 1; j < int(laserCloudCornerLast -> size()); ++j){
                        if(int(laserCloudCornerLast -> points[j].intensity) <= closestPointScanID)
                            continue;
                        if(int(laserCloudCornerLast -> points[j].intensity) >= closestPointScanID + 2.5)
                            break;
                        
                        double pointSqDis = dis(laserCloudCornerLast -> points[j], pointSel);
                        if(pointSqDis < minPointSqDis2){
                            minPointSqDis2 = pointSqDis;
                            minPointInd2 = j;
                        }
                    }

                    for(int j = closestPointInd - 1; j >= 0; --j){
                        if(int(laserCloudCornerLast -> points[j].intensity) >= closestPointScanID)
                            continue;
                        if(int(laserCloudCornerLast -> points[j].intensity) < closestPointScanID - 2.5)
                            break;
                        
                        double pointSqDis = dis(laserCloudCornerLast -> points[j], pointSel);
                        if(pointSqDis < minPointSqDis2){
                            minPointSqDis2 = pointSqDis;
                            minPointInd2 = j;
                        }
                    }

                    if(minPointInd2 >= 0){
                        Eigen::Vector3d curr_point{cornerKeyPoints -> points[i].x,
                                                   cornerKeyPoints -> points[i].y,
                                                   cornerKeyPoints -> points[i].z};
                        Eigen::Vector3d point_a{laserCloudCornerLast -> points[closestPointInd].x,
                                                laserCloudCornerLast -> points[closestPointInd].y,
                                                laserCloudCornerLast -> points[closestPointInd].z};
                        Eigen::Vector3d point_b{laserCloudCornerLast -> points[minPointInd2].x,
                                                laserCloudCornerLast -> points[minPointInd2].y,
                                                laserCloudCornerLast -> points[minPointInd2].z};

                        ceres::CostFunction *cost_function = 
                            LidarEdgeFactor::Create(curr_point, point_a, point_b, 1);
                        problem.AddResidualBlock(cost_function, loss_function, q, t);
                    }
                }
            }

            // 平面点
            for(int i = 0; i < surfFlatNum; ++i){
                transform(surfKeyPoints -> points[i], pointSel);
                kdtreeSurfLast -> nearestKSearch(pointSel, 1, pointSearchInd, pointSearchSqDis);

                int closestPointInd = -1, minPointInd2 = -1, minPointInd3 = -1;
                if(pointSearchSqDis[0] < nearest_feature_dist_sqr){
                    closestPointInd = pointSearchInd[0];
                    int closestPointScanID = int(laserCloudSurfLast -> points[closestPointInd].intensity);

                    double minPointSqDis2 = nearest_feature_dist_sqr, minPointSqDis3 = nearest_feature_dist_sqr;
                    for(int j = closestPointInd + 1; j < int(laserCloudSurfLast -> size()); ++j){
                        if(int(laserCloudSurfLast -> points[j].intensity) > closestPointScanID + 2.5)
                            break;
                        
                        double pointSqDis = dis(laserCloudSurfLast -> points[j], pointSel);
                        if(int(laserCloudSurfLast -> points[j].intensity) <= closestPointScanID &&
                            pointSqDis < minPointSqDis2){
                            minPointSqDis2 = pointSqDis;
                            minPointInd2 = j;
                        }else if(int(laserCloudSurfLast -> points[j].intensity) > closestPointScanID &&
                            pointSqDis < minPointSqDis3){
                            minPointSqDis3 = pointSqDis;
                            minPointInd3 = j;
                        }
                    }
                    for(int j = closestPointInd - 1; j >= 0; --j){
                        if(int(laserCloudSurfLast -> points[j].intensity) < closestPointScanID - 2.5)
                            break;
                        
                        double pointSqDis = dis(laserCloudSurfLast -> points[j], pointSel);
                        if(int(laserCloudSurfLast -> points[j].intensity) > closestPointScanID &&
                            pointSqDis < minPointSqDis2){
                            minPointSqDis2 = pointSqDis;
                            minPointInd2 = j;
                        }else if(int(laserCloudSurfLast -> points[j].intensity) <= closestPointScanID &&
                            pointSqDis < minPointSqDis3){
                            minPointSqDis3 = pointSqDis;
                            minPointInd3 = j;
                        }
                    }

                    if(minPointInd2 >= 0 && minPointInd3 >= 0){
                        Eigen::Vector3d curr_point = {surfKeyPoints -> points[i].x,
                                                      surfKeyPoints -> points[i].y,
                                                      surfKeyPoints -> points[i].z};
                        Eigen::Vector3d point_a = {laserCloudSurfLast -> points[closestPointInd].x,
                                                   laserCloudSurfLast -> points[closestPointInd].y,
                                                   laserCloudSurfLast -> points[closestPointInd].z};
                        Eigen::Vector3d point_b = {laserCloudSurfLast -> points[minPointSqDis2].x,
                                                   laserCloudSurfLast -> points[minPointSqDis2].y,
                                                   laserCloudSurfLast -> points[minPointSqDis2].z};
                        Eigen::Vector3d point_c = {laserCloudSurfLast -> points[minPointSqDis3].x,
                                                   laserCloudSurfLast -> points[minPointSqDis3].y,
                                                   laserCloudSurfLast -> points[minPointSqDis3].z};
                        
                        ceres::CostFunction *cost_function = 
                            LidarPlaneFactor::Create(curr_point, point_a, point_b, point_c, 1);
                        problem.AddResidualBlock(cost_function, loss_function, q, t);
                    }
                }
            }

            // 迭代优化
            ceres::Solver::Options options;
            options.linear_solver_type = ceres::DENSE_QR;
            options.max_num_iterations = 5;
            options.minimizer_progress_to_stdout = false;
            ceres::Solver::Summary summary;
            ceres::Solve(options, &problem, &summary);
            // RCLCPP_INFO_STREAM(this -> get_logger(), summary.BriefReport());
        }

    }

    // 更新位姿
    t_w_last = q_w_last * t_odom + t_w_last;
    q_w_last = q_w_last * q_odom;

    laserCloudCornerLast.swap(cornerLessSharp);
    laserCloudSurfLast.swap(surfLessFlat);
    
    kdtreeCornerLast -> setInputCloud(laserCloudCornerLast);
    kdtreeSurfLast -> setInputCloud(laserCloudSurfLast);
}

void FrontEnd::publishOdometry(){
    laserOdometry.header.frame_id = "map";
    laserOdometry.pose.pose.orientation.x = q_w_last.x();
    laserOdometry.pose.pose.orientation.y = q_w_last.y();
    laserOdometry.pose.pose.orientation.z = q_w_last.z();
    laserOdometry.pose.pose.orientation.w = q_w_last.w();
    laserOdometry.pose.pose.position.x = t_w_last.x();
    laserOdometry.pose.pose.position.y = t_w_last.y();
    laserOdometry.pose.pose.position.z = t_w_last.z();

    geometry_msgs::msg::PoseStamped laserPose;
    laserPose.header = laserOdometry.header;
    laserPose.pose = laserOdometry.pose.pose;

    laserPath.poses.push_back(laserPose);
    pub_laser_path -> publish(laserPath);
}

} // namespace lidarslam

