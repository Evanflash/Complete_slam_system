#ifndef _DATA_PROCESS_H
#define _DATA_PROCESS_H

#include "slam_utils.h"
#include "channel.h"

namespace lidarslam{
class DataProcess : public rclcpp::Node{
private:
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr Cloudmsg;

    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_cloud_in;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_corner_sharp;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_corner_less_sharp;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_surf_flat;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_surf_less_flat;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_segment_cloud;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_ground_cloud;

    // 接收消息
    std::queue<sensor_msgs::msg::PointCloud2> queClouds;
    std::mutex mtx;

    // run子线程
    std::thread _run_thread;

    // 输出
    Channel<DataProcessOut>& _output_channel;

    // 点云
    CloudTypePtr _cloud_in;
    CloudTypePtr _corner_sharp;
    CloudTypePtr _corner_less_sharp;
    CloudTypePtr _surf_flat;
    CloudTypePtr _surf_less_flat;
    CloudTypePtr _segment_cloud;
    CloudTypePtr _ground_cloud;
    CloudTypePtr _full_cloud;

    // 消息
    sensor_msgs::msg::PointCloud2 oneCloud;

    // 标记
    Eigen::MatrixXf _range_mat;
    Eigen::MatrixXi _label_mat;
    Eigen::MatrixXi _ground_mat;
    Eigen::MatrixXi _corner_label;

    // 曲率
    std::vector<smoothness> cloudCurvature;
    std::vector<int> str_index;
    std::vector<int> end_index;

    // 超参
    int _vertical_scans;
    int _horizontal_scans;
    float _ang_bottom;
    float _ang_top;
    int _ground_scan_index;
    float _sensor_mount_angle;
    float _segment_theta;
    int _segment_valid_line_num;
    float _ang_resolution_X;
    float _ang_resolution_Y;
    
    

public:
    DataProcess(const std::string &name, 
        Channel<DataProcessOut> &output_channel);
    
    ~DataProcess();

    void cloudHandler(const sensor_msgs::msg::PointCloud2 &laserCloudMsg);

    void run();

private:
    void resetParameters();
    void projectPointCloud();
    void groundRemoval();
    void calculateSmoothness();
    void markCornerPoints();
    void labelVaildableCornerPoints(int row, int col);
    void cornerCloudSegmentation();
    void publishCloud();


}; // DataProcess

} // lidarslam

#endif // _DATA_PROCESS_H