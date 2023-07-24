// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_slam_msgs:msg/Cloud2.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__BUILDER_HPP_
#define LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lidar_slam_msgs/msg/detail/cloud2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lidar_slam_msgs
{

namespace msg
{

namespace builder
{

class Init_Cloud2_ground_cloud
{
public:
  explicit Init_Cloud2_ground_cloud(::lidar_slam_msgs::msg::Cloud2 & msg)
  : msg_(msg)
  {}
  ::lidar_slam_msgs::msg::Cloud2 ground_cloud(::lidar_slam_msgs::msg::Cloud2::_ground_cloud_type arg)
  {
    msg_.ground_cloud = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud2 msg_;
};

class Init_Cloud2_segment_cloud
{
public:
  explicit Init_Cloud2_segment_cloud(::lidar_slam_msgs::msg::Cloud2 & msg)
  : msg_(msg)
  {}
  Init_Cloud2_ground_cloud segment_cloud(::lidar_slam_msgs::msg::Cloud2::_segment_cloud_type arg)
  {
    msg_.segment_cloud = std::move(arg);
    return Init_Cloud2_ground_cloud(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud2 msg_;
};

class Init_Cloud2_surf_less_flat
{
public:
  explicit Init_Cloud2_surf_less_flat(::lidar_slam_msgs::msg::Cloud2 & msg)
  : msg_(msg)
  {}
  Init_Cloud2_segment_cloud surf_less_flat(::lidar_slam_msgs::msg::Cloud2::_surf_less_flat_type arg)
  {
    msg_.surf_less_flat = std::move(arg);
    return Init_Cloud2_segment_cloud(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud2 msg_;
};

class Init_Cloud2_corner_less_sharp
{
public:
  explicit Init_Cloud2_corner_less_sharp(::lidar_slam_msgs::msg::Cloud2 & msg)
  : msg_(msg)
  {}
  Init_Cloud2_surf_less_flat corner_less_sharp(::lidar_slam_msgs::msg::Cloud2::_corner_less_sharp_type arg)
  {
    msg_.corner_less_sharp = std::move(arg);
    return Init_Cloud2_surf_less_flat(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud2 msg_;
};

class Init_Cloud2_transform
{
public:
  explicit Init_Cloud2_transform(::lidar_slam_msgs::msg::Cloud2 & msg)
  : msg_(msg)
  {}
  Init_Cloud2_corner_less_sharp transform(::lidar_slam_msgs::msg::Cloud2::_transform_type arg)
  {
    msg_.transform = std::move(arg);
    return Init_Cloud2_corner_less_sharp(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud2 msg_;
};

class Init_Cloud2_header
{
public:
  Init_Cloud2_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cloud2_transform header(::lidar_slam_msgs::msg::Cloud2::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Cloud2_transform(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud2 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_slam_msgs::msg::Cloud2>()
{
  return lidar_slam_msgs::msg::builder::Init_Cloud2_header();
}

}  // namespace lidar_slam_msgs

#endif  // LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__BUILDER_HPP_
