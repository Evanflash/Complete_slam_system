// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lidar_slam_msgs:msg/Cloud.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD__STRUCT_H_
#define LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'corner_sharp'
// Member 'corner_less_sharp'
// Member 'surf_flat'
// Member 'surf_less_flat'
// Member 'segment_cloud'
// Member 'ground_cloud'
#include "lidar_slam_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Cloud in the package lidar_slam_msgs.
typedef struct lidar_slam_msgs__msg__Cloud
{
  std_msgs__msg__Header header;
  lidar_slam_msgs__msg__Point__Sequence corner_sharp;
  lidar_slam_msgs__msg__Point__Sequence corner_less_sharp;
  lidar_slam_msgs__msg__Point__Sequence surf_flat;
  lidar_slam_msgs__msg__Point__Sequence surf_less_flat;
  lidar_slam_msgs__msg__Point__Sequence segment_cloud;
  lidar_slam_msgs__msg__Point__Sequence ground_cloud;
} lidar_slam_msgs__msg__Cloud;

// Struct for a sequence of lidar_slam_msgs__msg__Cloud.
typedef struct lidar_slam_msgs__msg__Cloud__Sequence
{
  lidar_slam_msgs__msg__Cloud * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_slam_msgs__msg__Cloud__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD__STRUCT_H_
