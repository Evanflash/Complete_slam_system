// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lidar_slam_msgs:msg/Cloud2.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__STRUCT_H_
#define LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__STRUCT_H_

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
// Member 'transform'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'corner_less_sharp'
// Member 'surf_less_flat'
// Member 'segment_cloud'
// Member 'ground_cloud'
#include "lidar_slam_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Cloud2 in the package lidar_slam_msgs.
typedef struct lidar_slam_msgs__msg__Cloud2
{
  std_msgs__msg__Header header;
  /// x, y, z, w, qx, qy, qz
  rosidl_runtime_c__float__Sequence transform;
  lidar_slam_msgs__msg__Point__Sequence corner_less_sharp;
  lidar_slam_msgs__msg__Point__Sequence surf_less_flat;
  lidar_slam_msgs__msg__Point__Sequence segment_cloud;
  lidar_slam_msgs__msg__Point__Sequence ground_cloud;
} lidar_slam_msgs__msg__Cloud2;

// Struct for a sequence of lidar_slam_msgs__msg__Cloud2.
typedef struct lidar_slam_msgs__msg__Cloud2__Sequence
{
  lidar_slam_msgs__msg__Cloud2 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_slam_msgs__msg__Cloud2__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__STRUCT_H_
