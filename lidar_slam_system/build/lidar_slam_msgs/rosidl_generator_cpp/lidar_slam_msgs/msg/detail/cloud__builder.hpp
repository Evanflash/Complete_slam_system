// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_slam_msgs:msg/Cloud.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD__BUILDER_HPP_
#define LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lidar_slam_msgs/msg/detail/cloud__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lidar_slam_msgs
{

namespace msg
{

namespace builder
{

class Init_Cloud_ground_cloud
{
public:
  explicit Init_Cloud_ground_cloud(::lidar_slam_msgs::msg::Cloud & msg)
  : msg_(msg)
  {}
  ::lidar_slam_msgs::msg::Cloud ground_cloud(::lidar_slam_msgs::msg::Cloud::_ground_cloud_type arg)
  {
    msg_.ground_cloud = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud msg_;
};

class Init_Cloud_segment_cloud
{
public:
  explicit Init_Cloud_segment_cloud(::lidar_slam_msgs::msg::Cloud & msg)
  : msg_(msg)
  {}
  Init_Cloud_ground_cloud segment_cloud(::lidar_slam_msgs::msg::Cloud::_segment_cloud_type arg)
  {
    msg_.segment_cloud = std::move(arg);
    return Init_Cloud_ground_cloud(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud msg_;
};

class Init_Cloud_surf_less_flat
{
public:
  explicit Init_Cloud_surf_less_flat(::lidar_slam_msgs::msg::Cloud & msg)
  : msg_(msg)
  {}
  Init_Cloud_segment_cloud surf_less_flat(::lidar_slam_msgs::msg::Cloud::_surf_less_flat_type arg)
  {
    msg_.surf_less_flat = std::move(arg);
    return Init_Cloud_segment_cloud(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud msg_;
};

class Init_Cloud_surf_flat
{
public:
  explicit Init_Cloud_surf_flat(::lidar_slam_msgs::msg::Cloud & msg)
  : msg_(msg)
  {}
  Init_Cloud_surf_less_flat surf_flat(::lidar_slam_msgs::msg::Cloud::_surf_flat_type arg)
  {
    msg_.surf_flat = std::move(arg);
    return Init_Cloud_surf_less_flat(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud msg_;
};

class Init_Cloud_corner_less_sharp
{
public:
  explicit Init_Cloud_corner_less_sharp(::lidar_slam_msgs::msg::Cloud & msg)
  : msg_(msg)
  {}
  Init_Cloud_surf_flat corner_less_sharp(::lidar_slam_msgs::msg::Cloud::_corner_less_sharp_type arg)
  {
    msg_.corner_less_sharp = std::move(arg);
    return Init_Cloud_surf_flat(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud msg_;
};

class Init_Cloud_corner_sharp
{
public:
  explicit Init_Cloud_corner_sharp(::lidar_slam_msgs::msg::Cloud & msg)
  : msg_(msg)
  {}
  Init_Cloud_corner_less_sharp corner_sharp(::lidar_slam_msgs::msg::Cloud::_corner_sharp_type arg)
  {
    msg_.corner_sharp = std::move(arg);
    return Init_Cloud_corner_less_sharp(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud msg_;
};

class Init_Cloud_header
{
public:
  Init_Cloud_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cloud_corner_sharp header(::lidar_slam_msgs::msg::Cloud::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Cloud_corner_sharp(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Cloud msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_slam_msgs::msg::Cloud>()
{
  return lidar_slam_msgs::msg::builder::Init_Cloud_header();
}

}  // namespace lidar_slam_msgs

#endif  // LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD__BUILDER_HPP_
