// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lidar_slam_msgs:msg/Cloud.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD__FUNCTIONS_H_
#define LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lidar_slam_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "lidar_slam_msgs/msg/detail/cloud__struct.h"

/// Initialize msg/Cloud message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lidar_slam_msgs__msg__Cloud
 * )) before or use
 * lidar_slam_msgs__msg__Cloud__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
bool
lidar_slam_msgs__msg__Cloud__init(lidar_slam_msgs__msg__Cloud * msg);

/// Finalize msg/Cloud message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
void
lidar_slam_msgs__msg__Cloud__fini(lidar_slam_msgs__msg__Cloud * msg);

/// Create msg/Cloud message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lidar_slam_msgs__msg__Cloud__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
lidar_slam_msgs__msg__Cloud *
lidar_slam_msgs__msg__Cloud__create();

/// Destroy msg/Cloud message.
/**
 * It calls
 * lidar_slam_msgs__msg__Cloud__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
void
lidar_slam_msgs__msg__Cloud__destroy(lidar_slam_msgs__msg__Cloud * msg);

/// Check for msg/Cloud message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
bool
lidar_slam_msgs__msg__Cloud__are_equal(const lidar_slam_msgs__msg__Cloud * lhs, const lidar_slam_msgs__msg__Cloud * rhs);

/// Copy a msg/Cloud message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
bool
lidar_slam_msgs__msg__Cloud__copy(
  const lidar_slam_msgs__msg__Cloud * input,
  lidar_slam_msgs__msg__Cloud * output);

/// Initialize array of msg/Cloud messages.
/**
 * It allocates the memory for the number of elements and calls
 * lidar_slam_msgs__msg__Cloud__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
bool
lidar_slam_msgs__msg__Cloud__Sequence__init(lidar_slam_msgs__msg__Cloud__Sequence * array, size_t size);

/// Finalize array of msg/Cloud messages.
/**
 * It calls
 * lidar_slam_msgs__msg__Cloud__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
void
lidar_slam_msgs__msg__Cloud__Sequence__fini(lidar_slam_msgs__msg__Cloud__Sequence * array);

/// Create array of msg/Cloud messages.
/**
 * It allocates the memory for the array and calls
 * lidar_slam_msgs__msg__Cloud__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
lidar_slam_msgs__msg__Cloud__Sequence *
lidar_slam_msgs__msg__Cloud__Sequence__create(size_t size);

/// Destroy array of msg/Cloud messages.
/**
 * It calls
 * lidar_slam_msgs__msg__Cloud__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
void
lidar_slam_msgs__msg__Cloud__Sequence__destroy(lidar_slam_msgs__msg__Cloud__Sequence * array);

/// Check for msg/Cloud message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
bool
lidar_slam_msgs__msg__Cloud__Sequence__are_equal(const lidar_slam_msgs__msg__Cloud__Sequence * lhs, const lidar_slam_msgs__msg__Cloud__Sequence * rhs);

/// Copy an array of msg/Cloud messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_slam_msgs
bool
lidar_slam_msgs__msg__Cloud__Sequence__copy(
  const lidar_slam_msgs__msg__Cloud__Sequence * input,
  lidar_slam_msgs__msg__Cloud__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD__FUNCTIONS_H_
