#include "rclcpp/rclcpp.hpp"
#include "channel.h"
#include "slam_utils.h"
#include "data_process.h"

using namespace lidarslam;

int main(int argc, char** argv) {

  Channel<DataProcessOut> Data_out_channel(true);

  rclcpp::init(argc, argv);

  // Create nodes
  auto DP = std::make_shared<DataProcess>("data_process", Data_out_channel);

  RCLCPP_INFO(DP->get_logger(), "\033[1;32m---->\033[0m Started.");

  // Use 4 threads
  rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), 4);//been modify to galactic syntax
  executor.add_node(DP);
  executor.spin();

  // Must be called to cleanup threads
  rclcpp::shutdown();

  return 0;
}