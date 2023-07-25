#ifndef _FRONT_END_H
#define _FRONT_END_H

#include "slam_utils.h"
#include "channel.h"

namespace lidarslam{

class FrontEnd : public rclcpp::Node{
private:
    Channel<DataProcessOut> &_input_channel;
    Channel<FrontEndOut> &_output_channel;

    // 发布消息
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr pub_laser_odometry;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub_laser_path;

    // 线程
    std::thread _run_thread;

    // 点云
    CloudTypePtr cornerKeyPoints;
    CloudTypePtr surfKeyPoints;
    CloudTypePtr cornerLessSharp;
    CloudTypePtr surfLessFlat;
    CloudTypePtr laserCloudCornerLast;
    CloudTypePtr laserCloudSurfLast;
    CloudTypePtr segmentCloud;
    CloudTypePtr groundCloud;

    // kd tree
    pcl::KdTreeFLANN<PointType>::Ptr kdtreeCornerLast;
    pcl::KdTreeFLANN<PointType>::Ptr kdtreeSurfLast;

    // 位姿
    Eigen::Quaterniond q_w_last;
    Eigen::Vector3d t_w_last;

    // 里程计消息
    nav_msgs::msg::Odometry laserOdometry;
    nav_msgs::msg::Path laserPath;

    // 超参
    bool isFirstFrame;
    float nearest_feature_dist_sqr;
    int map_frequency;

public:
    FrontEnd(const std::string &name, Channel<DataProcessOut> &channel_in, Channel<FrontEndOut> &channel_out);

    ~FrontEnd();

    void run();
    void resetParameters();
    void odometry();
    void publishOdometry();

}; // class FrontEnd
    
} // namespace lidarslam

#endif // _FRONT_END_H