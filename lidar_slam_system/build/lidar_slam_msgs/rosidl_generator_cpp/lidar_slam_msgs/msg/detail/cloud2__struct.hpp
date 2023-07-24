// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lidar_slam_msgs:msg/Cloud2.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__STRUCT_HPP_
#define LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'corner_less_sharp'
// Member 'surf_less_flat'
// Member 'segment_cloud'
// Member 'ground_cloud'
#include "lidar_slam_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lidar_slam_msgs__msg__Cloud2 __attribute__((deprecated))
#else
# define DEPRECATED__lidar_slam_msgs__msg__Cloud2 __declspec(deprecated)
#endif

namespace lidar_slam_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Cloud2_
{
  using Type = Cloud2_<ContainerAllocator>;

  explicit Cloud2_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Cloud2_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _transform_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _transform_type transform;
  using _corner_less_sharp_type =
    std::vector<lidar_slam_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lidar_slam_msgs::msg::Point_<ContainerAllocator>>>;
  _corner_less_sharp_type corner_less_sharp;
  using _surf_less_flat_type =
    std::vector<lidar_slam_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lidar_slam_msgs::msg::Point_<ContainerAllocator>>>;
  _surf_less_flat_type surf_less_flat;
  using _segment_cloud_type =
    std::vector<lidar_slam_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lidar_slam_msgs::msg::Point_<ContainerAllocator>>>;
  _segment_cloud_type segment_cloud;
  using _ground_cloud_type =
    std::vector<lidar_slam_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lidar_slam_msgs::msg::Point_<ContainerAllocator>>>;
  _ground_cloud_type ground_cloud;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__transform(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->transform = _arg;
    return *this;
  }
  Type & set__corner_less_sharp(
    const std::vector<lidar_slam_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lidar_slam_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->corner_less_sharp = _arg;
    return *this;
  }
  Type & set__surf_less_flat(
    const std::vector<lidar_slam_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lidar_slam_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->surf_less_flat = _arg;
    return *this;
  }
  Type & set__segment_cloud(
    const std::vector<lidar_slam_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lidar_slam_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->segment_cloud = _arg;
    return *this;
  }
  Type & set__ground_cloud(
    const std::vector<lidar_slam_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lidar_slam_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->ground_cloud = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lidar_slam_msgs::msg::Cloud2_<ContainerAllocator> *;
  using ConstRawPtr =
    const lidar_slam_msgs::msg::Cloud2_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lidar_slam_msgs::msg::Cloud2_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lidar_slam_msgs::msg::Cloud2_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lidar_slam_msgs::msg::Cloud2_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lidar_slam_msgs::msg::Cloud2_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lidar_slam_msgs::msg::Cloud2_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lidar_slam_msgs::msg::Cloud2_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lidar_slam_msgs::msg::Cloud2_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lidar_slam_msgs::msg::Cloud2_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lidar_slam_msgs__msg__Cloud2
    std::shared_ptr<lidar_slam_msgs::msg::Cloud2_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lidar_slam_msgs__msg__Cloud2
    std::shared_ptr<lidar_slam_msgs::msg::Cloud2_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Cloud2_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->transform != other.transform) {
      return false;
    }
    if (this->corner_less_sharp != other.corner_less_sharp) {
      return false;
    }
    if (this->surf_less_flat != other.surf_less_flat) {
      return false;
    }
    if (this->segment_cloud != other.segment_cloud) {
      return false;
    }
    if (this->ground_cloud != other.ground_cloud) {
      return false;
    }
    return true;
  }
  bool operator!=(const Cloud2_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Cloud2_

// alias to use template instance with default allocator
using Cloud2 =
  lidar_slam_msgs::msg::Cloud2_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lidar_slam_msgs

#endif  // LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__STRUCT_HPP_
