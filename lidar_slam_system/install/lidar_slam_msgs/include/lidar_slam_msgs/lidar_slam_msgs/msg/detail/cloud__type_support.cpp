// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lidar_slam_msgs:msg/Cloud.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lidar_slam_msgs/msg/detail/cloud__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace lidar_slam_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Cloud_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lidar_slam_msgs::msg::Cloud(_init);
}

void Cloud_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lidar_slam_msgs::msg::Cloud *>(message_memory);
  typed_message->~Cloud();
}

size_t size_function__Cloud__corner_sharp(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Cloud__corner_sharp(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__Cloud__corner_sharp(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__Cloud__corner_sharp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(
    get_const_function__Cloud__corner_sharp(untyped_member, index));
  auto & value = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__Cloud__corner_sharp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(
    get_function__Cloud__corner_sharp(untyped_member, index));
  const auto & value = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__Cloud__corner_sharp(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Cloud__corner_less_sharp(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Cloud__corner_less_sharp(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__Cloud__corner_less_sharp(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__Cloud__corner_less_sharp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(
    get_const_function__Cloud__corner_less_sharp(untyped_member, index));
  auto & value = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__Cloud__corner_less_sharp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(
    get_function__Cloud__corner_less_sharp(untyped_member, index));
  const auto & value = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__Cloud__corner_less_sharp(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Cloud__surf_flat(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Cloud__surf_flat(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__Cloud__surf_flat(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__Cloud__surf_flat(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(
    get_const_function__Cloud__surf_flat(untyped_member, index));
  auto & value = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__Cloud__surf_flat(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(
    get_function__Cloud__surf_flat(untyped_member, index));
  const auto & value = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__Cloud__surf_flat(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Cloud__surf_less_flat(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Cloud__surf_less_flat(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__Cloud__surf_less_flat(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__Cloud__surf_less_flat(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(
    get_const_function__Cloud__surf_less_flat(untyped_member, index));
  auto & value = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__Cloud__surf_less_flat(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(
    get_function__Cloud__surf_less_flat(untyped_member, index));
  const auto & value = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__Cloud__surf_less_flat(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Cloud__segment_cloud(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Cloud__segment_cloud(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__Cloud__segment_cloud(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__Cloud__segment_cloud(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(
    get_const_function__Cloud__segment_cloud(untyped_member, index));
  auto & value = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__Cloud__segment_cloud(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(
    get_function__Cloud__segment_cloud(untyped_member, index));
  const auto & value = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__Cloud__segment_cloud(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Cloud__ground_cloud(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Cloud__ground_cloud(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__Cloud__ground_cloud(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__Cloud__ground_cloud(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(
    get_const_function__Cloud__ground_cloud(untyped_member, index));
  auto & value = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__Cloud__ground_cloud(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lidar_slam_msgs::msg::Point *>(
    get_function__Cloud__ground_cloud(untyped_member, index));
  const auto & value = *reinterpret_cast<const lidar_slam_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__Cloud__ground_cloud(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lidar_slam_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Cloud_message_member_array[7] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs::msg::Cloud, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "corner_sharp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lidar_slam_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs::msg::Cloud, corner_sharp),  // bytes offset in struct
    nullptr,  // default value
    size_function__Cloud__corner_sharp,  // size() function pointer
    get_const_function__Cloud__corner_sharp,  // get_const(index) function pointer
    get_function__Cloud__corner_sharp,  // get(index) function pointer
    fetch_function__Cloud__corner_sharp,  // fetch(index, &value) function pointer
    assign_function__Cloud__corner_sharp,  // assign(index, value) function pointer
    resize_function__Cloud__corner_sharp  // resize(index) function pointer
  },
  {
    "corner_less_sharp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lidar_slam_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs::msg::Cloud, corner_less_sharp),  // bytes offset in struct
    nullptr,  // default value
    size_function__Cloud__corner_less_sharp,  // size() function pointer
    get_const_function__Cloud__corner_less_sharp,  // get_const(index) function pointer
    get_function__Cloud__corner_less_sharp,  // get(index) function pointer
    fetch_function__Cloud__corner_less_sharp,  // fetch(index, &value) function pointer
    assign_function__Cloud__corner_less_sharp,  // assign(index, value) function pointer
    resize_function__Cloud__corner_less_sharp  // resize(index) function pointer
  },
  {
    "surf_flat",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lidar_slam_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs::msg::Cloud, surf_flat),  // bytes offset in struct
    nullptr,  // default value
    size_function__Cloud__surf_flat,  // size() function pointer
    get_const_function__Cloud__surf_flat,  // get_const(index) function pointer
    get_function__Cloud__surf_flat,  // get(index) function pointer
    fetch_function__Cloud__surf_flat,  // fetch(index, &value) function pointer
    assign_function__Cloud__surf_flat,  // assign(index, value) function pointer
    resize_function__Cloud__surf_flat  // resize(index) function pointer
  },
  {
    "surf_less_flat",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lidar_slam_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs::msg::Cloud, surf_less_flat),  // bytes offset in struct
    nullptr,  // default value
    size_function__Cloud__surf_less_flat,  // size() function pointer
    get_const_function__Cloud__surf_less_flat,  // get_const(index) function pointer
    get_function__Cloud__surf_less_flat,  // get(index) function pointer
    fetch_function__Cloud__surf_less_flat,  // fetch(index, &value) function pointer
    assign_function__Cloud__surf_less_flat,  // assign(index, value) function pointer
    resize_function__Cloud__surf_less_flat  // resize(index) function pointer
  },
  {
    "segment_cloud",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lidar_slam_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs::msg::Cloud, segment_cloud),  // bytes offset in struct
    nullptr,  // default value
    size_function__Cloud__segment_cloud,  // size() function pointer
    get_const_function__Cloud__segment_cloud,  // get_const(index) function pointer
    get_function__Cloud__segment_cloud,  // get(index) function pointer
    fetch_function__Cloud__segment_cloud,  // fetch(index, &value) function pointer
    assign_function__Cloud__segment_cloud,  // assign(index, value) function pointer
    resize_function__Cloud__segment_cloud  // resize(index) function pointer
  },
  {
    "ground_cloud",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lidar_slam_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidar_slam_msgs::msg::Cloud, ground_cloud),  // bytes offset in struct
    nullptr,  // default value
    size_function__Cloud__ground_cloud,  // size() function pointer
    get_const_function__Cloud__ground_cloud,  // get_const(index) function pointer
    get_function__Cloud__ground_cloud,  // get(index) function pointer
    fetch_function__Cloud__ground_cloud,  // fetch(index, &value) function pointer
    assign_function__Cloud__ground_cloud,  // assign(index, value) function pointer
    resize_function__Cloud__ground_cloud  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Cloud_message_members = {
  "lidar_slam_msgs::msg",  // message namespace
  "Cloud",  // message name
  7,  // number of fields
  sizeof(lidar_slam_msgs::msg::Cloud),
  Cloud_message_member_array,  // message members
  Cloud_init_function,  // function to initialize message memory (memory has to be allocated)
  Cloud_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Cloud_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Cloud_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace lidar_slam_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lidar_slam_msgs::msg::Cloud>()
{
  return &::lidar_slam_msgs::msg::rosidl_typesupport_introspection_cpp::Cloud_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lidar_slam_msgs, msg, Cloud)() {
  return &::lidar_slam_msgs::msg::rosidl_typesupport_introspection_cpp::Cloud_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
