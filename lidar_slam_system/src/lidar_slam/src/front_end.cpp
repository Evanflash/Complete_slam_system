#include "front_end.h"

namespace lidarslam{

FrontEnd::FrontEnd(const std::string &name, Channel<DataProcessOut> &channel_in, Channel<FrontEndOut> &channel_out)
    : Node(name), _input_channel(channel_in), _output_channel(channel_out), q_w_last(1, 0, 0, 0), t_w_last(0, 0, 0)
{
    pub_laser_odometry = this -> create_publisher<nav_msgs::msg::Odometry>("/laser_odom_init", 1);


    _run_thread = std::thread(&FrontEnd::run, this);

    cornerKeyPoints.reset(new CloudType());
    surfKeyPoints.reset(new CloudType());
    laserCloudCornerLast.reset(new CloudType());
    laserCloudSurfLast.reset(new CloudType());
    segmentCloud.reset(new CloudType());
    groundCloud.reset(new CloudType());

    kdtreeCornerLast.reset(new pcl::KdTreeFLANN<PointType>());
    kdtreeSurfLast.reset(new pcl::KdTreeFLANN<PointType>());
}

FrontEnd::~FrontEnd(){
    _input_channel.send({});
    _run_thread.join();
}

void FrontEnd::run(){
    while(rclcpp::ok()){
        
    }
}

void FrontEnd::resetParameters(){

}

void FrontEnd::odometry(){

}

void FrontEnd::publishCloud(){

}

} // namespace lidarslam

