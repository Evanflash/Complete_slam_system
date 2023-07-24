// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_slam_msgs:msg/Point.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM_MSGS__MSG__DETAIL__POINT__BUILDER_HPP_
#define LIDAR_SLAM_MSGS__MSG__DETAIL__POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lidar_slam_msgs/msg/detail/point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lidar_slam_msgs
{

namespace msg
{

namespace builder
{

class Init_Point_i
{
public:
  explicit Init_Point_i(::lidar_slam_msgs::msg::Point & msg)
  : msg_(msg)
  {}
  ::lidar_slam_msgs::msg::Point i(::lidar_slam_msgs::msg::Point::_i_type arg)
  {
    msg_.i = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Point msg_;
};

class Init_Point_z
{
public:
  explicit Init_Point_z(::lidar_slam_msgs::msg::Point & msg)
  : msg_(msg)
  {}
  Init_Point_i z(::lidar_slam_msgs::msg::Point::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Point_i(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Point msg_;
};

class Init_Point_y
{
public:
  explicit Init_Point_y(::lidar_slam_msgs::msg::Point & msg)
  : msg_(msg)
  {}
  Init_Point_z y(::lidar_slam_msgs::msg::Point::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Point_z(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Point msg_;
};

class Init_Point_x
{
public:
  Init_Point_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Point_y x(::lidar_slam_msgs::msg::Point::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Point_y(msg_);
  }

private:
  ::lidar_slam_msgs::msg::Point msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_slam_msgs::msg::Point>()
{
  return lidar_slam_msgs::msg::builder::Init_Point_x();
}

}  // namespace lidar_slam_msgs

#endif  // LIDAR_SLAM_MSGS__MSG__DETAIL__POINT__BUILDER_HPP_
