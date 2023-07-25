cmake_minimum_required(VERSION 3.8)
project(lidar_slam)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED)
find_package(GTSAM REQUIRED QUIET)
find_package(Boost REQUIRED COMPONENTS thread serialization timer)
find_package(Ceres REQUIRED)

include_directories(include/lidar_slam)
ament_export_include_directories(include/lidar_slam)

set(dependencies
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  nav_msgs
  pcl_conversions
)

add_executable(${PROJECT_NAME} src/data_process.cpp src/front_end.cpp src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES} ${CERES_LIBRARIES} gtsam)
ament_target_dependencies(${PROJECT_NAME} ${dependencies} Eigen3)

install(TARGETS
  ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  config
  launch
  rviz
  DESTINATION share/${PROJECT_NAME}
)


ament_package()
