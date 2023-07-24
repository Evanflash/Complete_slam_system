// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lidar_slam_msgs:msg/Cloud.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lidar_slam_msgs/msg/detail/cloud__rosidl_typesupport_introspection_c.h"
#include "lidar_slam_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lidar_slam_msgs/msg/detail/cloud__functions.h"
#include "lidar_slam_msgs/msg/detail/cloud__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `corner_sharp`
// Member `corner_less_sharp`
// Member `surf_flat`
// Member `surf_less_flat`
// Member `segment_cloud`
// Member `ground_cloud`
#include "lidar_slam_msgs/msg/point.h"
// Member `corner_sharp`
// Member `corner_less_sharp`
// Member `surf_flat`
// Member `surf_less_flat`
// Member `segment_cloud`
// Member `ground_cloud`
#include "lidar_slam_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lidar_slam_msgs__msg__Cloud__init(message_memory);
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_fini_function(void * message_memory)
{
  lidar_slam_msgs__msg__Cloud__fini(message_memory);
}

size_t lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__corner_sharp(
  const void * untyped_member)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__corner_sharp(
  const void * untyped_member, size_t index)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__corner_sharp(
  void * untyped_member, size_t index)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__corner_sharp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lidar_slam_msgs__msg__Point * item =
    ((const lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__corner_sharp(untyped_member, index));
  lidar_slam_msgs__msg__Point * value =
    (lidar_slam_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__corner_sharp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lidar_slam_msgs__msg__Point * item =
    ((lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__corner_sharp(untyped_member, index));
  const lidar_slam_msgs__msg__Point * value =
    (const lidar_slam_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__corner_sharp(
  void * untyped_member, size_t size)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  lidar_slam_msgs__msg__Point__Sequence__fini(member);
  return lidar_slam_msgs__msg__Point__Sequence__init(member, size);
}

size_t lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__corner_less_sharp(
  const void * untyped_member)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__corner_less_sharp(
  const void * untyped_member, size_t index)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__corner_less_sharp(
  void * untyped_member, size_t index)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__corner_less_sharp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lidar_slam_msgs__msg__Point * item =
    ((const lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__corner_less_sharp(untyped_member, index));
  lidar_slam_msgs__msg__Point * value =
    (lidar_slam_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__corner_less_sharp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lidar_slam_msgs__msg__Point * item =
    ((lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__corner_less_sharp(untyped_member, index));
  const lidar_slam_msgs__msg__Point * value =
    (const lidar_slam_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__corner_less_sharp(
  void * untyped_member, size_t size)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  lidar_slam_msgs__msg__Point__Sequence__fini(member);
  return lidar_slam_msgs__msg__Point__Sequence__init(member, size);
}

size_t lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__surf_flat(
  const void * untyped_member)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__surf_flat(
  const void * untyped_member, size_t index)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__surf_flat(
  void * untyped_member, size_t index)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__surf_flat(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lidar_slam_msgs__msg__Point * item =
    ((const lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__surf_flat(untyped_member, index));
  lidar_slam_msgs__msg__Point * value =
    (lidar_slam_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__surf_flat(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lidar_slam_msgs__msg__Point * item =
    ((lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__surf_flat(untyped_member, index));
  const lidar_slam_msgs__msg__Point * value =
    (const lidar_slam_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__surf_flat(
  void * untyped_member, size_t size)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  lidar_slam_msgs__msg__Point__Sequence__fini(member);
  return lidar_slam_msgs__msg__Point__Sequence__init(member, size);
}

size_t lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__surf_less_flat(
  const void * untyped_member)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__surf_less_flat(
  const void * untyped_member, size_t index)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__surf_less_flat(
  void * untyped_member, size_t index)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__surf_less_flat(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lidar_slam_msgs__msg__Point * item =
    ((const lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__surf_less_flat(untyped_member, index));
  lidar_slam_msgs__msg__Point * value =
    (lidar_slam_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__surf_less_flat(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lidar_slam_msgs__msg__Point * item =
    ((lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__surf_less_flat(untyped_member, index));
  const lidar_slam_msgs__msg__Point * value =
    (const lidar_slam_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__surf_less_flat(
  void * untyped_member, size_t size)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  lidar_slam_msgs__msg__Point__Sequence__fini(member);
  return lidar_slam_msgs__msg__Point__Sequence__init(member, size);
}

size_t lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__segment_cloud(
  const void * untyped_member)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__segment_cloud(
  const void * untyped_member, size_t index)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__segment_cloud(
  void * untyped_member, size_t index)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__segment_cloud(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lidar_slam_msgs__msg__Point * item =
    ((const lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__segment_cloud(untyped_member, index));
  lidar_slam_msgs__msg__Point * value =
    (lidar_slam_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__segment_cloud(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lidar_slam_msgs__msg__Point * item =
    ((lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__segment_cloud(untyped_member, index));
  const lidar_slam_msgs__msg__Point * value =
    (const lidar_slam_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__segment_cloud(
  void * untyped_member, size_t size)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  lidar_slam_msgs__msg__Point__Sequence__fini(member);
  return lidar_slam_msgs__msg__Point__Sequence__init(member, size);
}

size_t lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__ground_cloud(
  const void * untyped_member)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__ground_cloud(
  const void * untyped_member, size_t index)
{
  const lidar_slam_msgs__msg__Point__Sequence * member =
    (const lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__ground_cloud(
  void * untyped_member, size_t index)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__ground_cloud(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lidar_slam_msgs__msg__Point * item =
    ((const lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__ground_cloud(untyped_member, index));
  lidar_slam_msgs__msg__Point * value =
    (lidar_slam_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__ground_cloud(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lidar_slam_msgs__msg__Point * item =
    ((lidar_slam_msgs__msg__Point *)
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__ground_cloud(untyped_member, index));
  const lidar_slam_msgs__msg__Point * value =
    (const lidar_slam_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__ground_cloud(
  void * untyped_member, size_t size)
{
  lidar_slam_msgs__msg__Point__Sequence * member =
    (lidar_slam_msgs__msg__Point__Sequence *)(untyped_member);
  lidar_slam_msgs__msg__Point__Sequence__fini(member);
  return lidar_slam_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs__msg__Cloud, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "corner_sharp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs__msg__Cloud, corner_sharp),  // bytes offset in struct
    NULL,  // default value
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__corner_sharp,  // size() function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__corner_sharp,  // get_const(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__corner_sharp,  // get(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__corner_sharp,  // fetch(index, &value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__corner_sharp,  // assign(index, value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__corner_sharp  // resize(index) function pointer
  },
  {
    "corner_less_sharp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs__msg__Cloud, corner_less_sharp),  // bytes offset in struct
    NULL,  // default value
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__corner_less_sharp,  // size() function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__corner_less_sharp,  // get_const(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__corner_less_sharp,  // get(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__corner_less_sharp,  // fetch(index, &value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__corner_less_sharp,  // assign(index, value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__corner_less_sharp  // resize(index) function pointer
  },
  {
    "surf_flat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs__msg__Cloud, surf_flat),  // bytes offset in struct
    NULL,  // default value
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__surf_flat,  // size() function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__surf_flat,  // get_const(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__surf_flat,  // get(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__surf_flat,  // fetch(index, &value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__surf_flat,  // assign(index, value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__surf_flat  // resize(index) function pointer
  },
  {
    "surf_less_flat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs__msg__Cloud, surf_less_flat),  // bytes offset in struct
    NULL,  // default value
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__surf_less_flat,  // size() function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__surf_less_flat,  // get_const(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__surf_less_flat,  // get(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__surf_less_flat,  // fetch(index, &value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__surf_less_flat,  // assign(index, value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__surf_less_flat  // resize(index) function pointer
  },
  {
    "segment_cloud",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs__msg__Cloud, segment_cloud),  // bytes offset in struct
    NULL,  // default value
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__segment_cloud,  // size() function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__segment_cloud,  // get_const(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__segment_cloud,  // get(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__segment_cloud,  // fetch(index, &value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__segment_cloud,  // assign(index, value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__segment_cloud  // resize(index) function pointer
  },
  {
    "ground_cloud",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs__msg__Cloud, ground_cloud),  // bytes offset in struct
    NULL,  // default value
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__size_function__Cloud__ground_cloud,  // size() function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_const_function__Cloud__ground_cloud,  // get_const(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__get_function__Cloud__ground_cloud,  // get(index) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__fetch_function__Cloud__ground_cloud,  // fetch(index, &value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__assign_function__Cloud__ground_cloud,  // assign(index, value) function pointer
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__resize_function__Cloud__ground_cloud  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_members = {
  "lidar_slam_msgs__msg",  // message namespace
  "Cloud",  // message name
  7,  // number of fields
  sizeof(lidar_slam_msgs__msg__Cloud),
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_member_array,  // message members
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_init_function,  // function to initialize message memory (memory has to be allocated)
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_type_support_handle = {
  0,
  &lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lidar_slam_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam_msgs, msg, Cloud)() {
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam_msgs, msg, Point)();
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam_msgs, msg, Point)();
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam_msgs, msg, Point)();
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam_msgs, msg, Point)();
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam_msgs, msg, Point)();
  lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lidar_slam_msgs, msg, Point)();
  if (!lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_type_support_handle.typesupport_identifier) {
    lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lidar_slam_msgs__msg__Cloud__rosidl_typesupport_introspection_c__Cloud_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
