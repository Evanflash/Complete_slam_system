from setuptools import find_packages
from setuptools import setup

setup(
    name='lidar_slam_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('lidar_slam_msgs', 'lidar_slam_msgs.*')),
)
