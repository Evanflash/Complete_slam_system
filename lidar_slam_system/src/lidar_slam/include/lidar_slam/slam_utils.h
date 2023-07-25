#ifndef _LIDAR_SLAM_UTILS_H
#define _LIDAR_SLAM_UTILS_H

#include "lidar_factor.hpp"

#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <unordered_set>
#include <boost/circular_buffer.hpp>
#include <Eigen/Dense>
#include <thread>
#include <deque>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <std_msgs/msg/header.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/filter.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/voxel_grid.h>

#include <ceres/ceres.h>

namespace lidarslam{

using PointType = pcl::PointXYZI;
using CloudType = pcl::PointCloud<PointType>;
using CloudTypePtr = pcl::PointCloud<PointType>::Ptr;


struct smoothness{
    float curvature;
    int index;

    smoothness(){
        curvature = 0;
        index = 0;
    }
    smoothness(int c, int i){
        curvature = c;
        index = i;
    }
};

struct DataProcessOut{
    CloudTypePtr corner_sharp;
    CloudTypePtr corner_less_sharp;
    CloudTypePtr surf_flat;
    CloudTypePtr surf_less_flat;
    CloudTypePtr segment_cloud;
    CloudTypePtr ground_cloud;
};

struct FrontEndOut{
    nav_msgs::msg::Odometry laserOdometry;
    CloudTypePtr cornerLast;
    CloudTypePtr surfLast;
    CloudTypePtr segment_cloud;
    CloudTypePtr ground_cloud;
};

struct pose{
    Eigen::Quaterniond q;
    Eigen::Vector3d t;
};

}

#endif // _LIDAR_SLAM_UTILS_h