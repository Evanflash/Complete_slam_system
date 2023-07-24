// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lidar_slam_msgs:msg/Cloud2.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__TRAITS_HPP_
#define LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lidar_slam_msgs/msg/detail/cloud2__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'corner_less_sharp'
// Member 'surf_less_flat'
// Member 'segment_cloud'
// Member 'ground_cloud'
#include "lidar_slam_msgs/msg/detail/point__traits.hpp"

namespace lidar_slam_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Cloud2 & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: transform
  {
    if (msg.transform.size() == 0) {
      out << "transform: []";
    } else {
      out << "transform: [";
      size_t pending_items = msg.transform.size();
      for (auto item : msg.transform) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: corner_less_sharp
  {
    if (msg.corner_less_sharp.size() == 0) {
      out << "corner_less_sharp: []";
    } else {
      out << "corner_less_sharp: [";
      size_t pending_items = msg.corner_less_sharp.size();
      for (auto item : msg.corner_less_sharp) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: surf_less_flat
  {
    if (msg.surf_less_flat.size() == 0) {
      out << "surf_less_flat: []";
    } else {
      out << "surf_less_flat: [";
      size_t pending_items = msg.surf_less_flat.size();
      for (auto item : msg.surf_less_flat) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: segment_cloud
  {
    if (msg.segment_cloud.size() == 0) {
      out << "segment_cloud: []";
    } else {
      out << "segment_cloud: [";
      size_t pending_items = msg.segment_cloud.size();
      for (auto item : msg.segment_cloud) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: ground_cloud
  {
    if (msg.ground_cloud.size() == 0) {
      out << "ground_cloud: []";
    } else {
      out << "ground_cloud: [";
      size_t pending_items = msg.ground_cloud.size();
      for (auto item : msg.ground_cloud) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cloud2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: transform
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.transform.size() == 0) {
      out << "transform: []\n";
    } else {
      out << "transform:\n";
      for (auto item : msg.transform) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: corner_less_sharp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.corner_less_sharp.size() == 0) {
      out << "corner_less_sharp: []\n";
    } else {
      out << "corner_less_sharp:\n";
      for (auto item : msg.corner_less_sharp) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: surf_less_flat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.surf_less_flat.size() == 0) {
      out << "surf_less_flat: []\n";
    } else {
      out << "surf_less_flat:\n";
      for (auto item : msg.surf_less_flat) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: segment_cloud
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.segment_cloud.size() == 0) {
      out << "segment_cloud: []\n";
    } else {
      out << "segment_cloud:\n";
      for (auto item : msg.segment_cloud) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: ground_cloud
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ground_cloud.size() == 0) {
      out << "ground_cloud: []\n";
    } else {
      out << "ground_cloud:\n";
      for (auto item : msg.ground_cloud) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cloud2 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace lidar_slam_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lidar_slam_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lidar_slam_msgs::msg::Cloud2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  lidar_slam_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lidar_slam_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lidar_slam_msgs::msg::Cloud2 & msg)
{
  return lidar_slam_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lidar_slam_msgs::msg::Cloud2>()
{
  return "lidar_slam_msgs::msg::Cloud2";
}

template<>
inline const char * name<lidar_slam_msgs::msg::Cloud2>()
{
  return "lidar_slam_msgs/msg/Cloud2";
}

template<>
struct has_fixed_size<lidar_slam_msgs::msg::Cloud2>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lidar_slam_msgs::msg::Cloud2>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lidar_slam_msgs::msg::Cloud2>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LIDAR_SLAM_MSGS__MSG__DETAIL__CLOUD2__TRAITS_HPP_
