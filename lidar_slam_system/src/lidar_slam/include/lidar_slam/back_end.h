#ifndef _BACK_END_H
#define _BACK_END_H

#include "slam_utils.h"
#include "channel.h"

#include <gtsam/geometry/Pose3.h>
#include <gtsam/geometry/Rot3.h>
#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>
#include <gtsam/nonlinear/Marginals.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/Values.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/slam/PriorFactor.h>
#include <gtsam/nonlinear/ISAM2.h>

namespace lidarslam{

class BackEnd : public rclcpp::Node{
private:
    Channel<FrontEndOut> &_input_channel;

    // 全局地图
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_global_map;
    CloudTypePtr globalMap;
    std::queue<int> queMap;
    std::mutex globalMtx;

    // 线程
    std::thread _run_thread;
    std::thread _global_map_thread;
    Channel<bool> _publish_global_signal;

    // 特征点
    CloudTypePtr keyPointCorner;
    CloudTypePtr keyPointSurf;

    // sub map
    CloudTypePtr subMapCorner;
    CloudTypePtr subMapSurf;

    // 滑动窗口
    std::queue<int> queCorner;
    std::queue<int> queSurf;

    // kd tree
    pcl::KdTreeFLANN<PointType>::Ptr kdtreeCorner;
    pcl::KdTreeFLANN<PointType>::Ptr kdtreeSurf;

    // 下采样
    pcl::VoxelGrid<PointType>::Ptr downSampleCorner;
    pcl::VoxelGrid<PointType>::Ptr downSampleSurf;
    pcl::VoxelGrid<PointType>::Ptr downSampleGlobalMap;

    // 全局位姿
    std::vector<pose> keyFramePoses;
    
    // 图优化
    gtsam::NonlinearFactorGraph gtsamGraph;
    gtsam::Values initialEstimate;
    gtsam::ISAM2 *isam;
    gtsam::Values isamCurrentEstimate;

    // 互斥锁
    std::mutex mtx;

    // 所有点云
    std::vector<CloudTypePtr> allCornerCloud;
    std::vector<CloudTypePtr> allSurfCloud;
    std::vector<CloudTypePtr> allSegmentCloud;
    std::vector<CloudTypePtr> allGroundCloud;

    // 位姿
    Eigen::Quaterniond q_w_last;
    Eigen::Vector3d t_w_last;

    // 上一帧位置
    PointType previousPosPoint;
    Eigen::Quaterniond q_keyframe_last;
    Eigen::Vector3d t_keyframe_last;

public:
    BackEnd(const std::string &name, Channel<FrontEndOut> &channel_in);
    
    ~BackEnd();

    void run();
    void scan2MapOptimization();
    void saveKeyFramesAndFactor();
    void publishGlobalMap();
    void downsample(CloudTypePtr cloud, pcl::VoxelGrid<PointType>::Ptr filter);
    void transToGlobalMap(CloudTypePtr cloud, CloudTypePtr temp, pose p);
}; // class BackEnd

} // namespace lidarslam

#endif // _BACK_END_H