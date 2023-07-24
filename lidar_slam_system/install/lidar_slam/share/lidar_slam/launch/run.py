import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import SetEnvironmentVariable, DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from os.path import expanduser


def generate_launch_description():

  # Configure environment
  stdout_linebuf_envvar = SetEnvironmentVariable('RCUTILS_CONSOLE_STDOUT_LINE_BUFFERED', '1')
  stdout_colorized_envvar = SetEnvironmentVariable('RCUTILS_COLORIZED_OUTPUT', '1')

  # Nodes Configurations
  config_file = os.path.join(get_package_share_directory('lidar_slam'), 'config', 'config.yaml')
  # config_file = '/home/evan/code/lego-loam/lego/src/LeGO-LOAM/config/loam_config.yaml'
  rviz_config = os.path.join(get_package_share_directory('lidar_slam'), 'rviz', 'test.rviz')

  #######################
  # data-publisher 
  data_config_file = '/home/evan/code/ndt-loc/src/data-publisher/config/data_config.yaml'

  #######################

  lidar_slam_node = Node(
    package='lidar_slam',
    executable='lidar_slam',
    output='screen',
    parameters=[config_file],
    remappings=[('/lidar_points', '/velodyne_points')],
  )

  # Rviz
  rviz_node = Node(
    package='rviz2',
    executable='rviz2',
    name='rviz2',
    arguments=['-d', rviz_config],
    output='screen'
  )

  data = Node(
    package='data-publisher',
    executable='lidar_data_node',
    name='data',
    parameters=[data_config_file]
  )

  ld = LaunchDescription()
  # Set environment variables
  ld.add_action(stdout_linebuf_envvar)
  ld.add_action(stdout_colorized_envvar)
  # Add nodes
  ld.add_action(data)
  ld.add_action(lidar_slam_node)
  ld.add_action(rviz_node)

  return ld