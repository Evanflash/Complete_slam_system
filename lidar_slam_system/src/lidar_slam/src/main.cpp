#include "rclcpp/rclcpp.hpp"
#include "channel.h"
#include "slam_utils.h"
#include "data_process.h"
#include "front_end.h"
#include "back_end.h"
#include "mapOptimization.h"

using namespace lidarslam;

int main(int argc, char** argv) {

  Channel<DataProcessOut> Data_out_channel(true);
  Channel<FrontEndOut> front_out_channel(false);

  rclcpp::init(argc, argv);

  // Create nodes
  auto DP = std::make_shared<DataProcess>("data_process", Data_out_channel);
  auto FE = std::make_shared<FrontEnd>("front_end", Data_out_channel, front_out_channel);
  // auto BE = std::make_shared<BackEnd>("back_end", front_out_channel);
  auto MO = std::make_shared<MapOptimization>("map_optimization", front_out_channel);
  

  RCLCPP_INFO(DP->get_logger(), "\033[1;32m---->\033[0m Started.");
  RCLCPP_INFO(FE->get_logger(), "\033[1;32m---->\033[0m Started.");
  // RCLCPP_INFO(BE->get_logger(), "\033[1;32m---->\033[0m Started.");
  RCLCPP_INFO(MO->get_logger(), "\033[1;32m---->\033[0m Started.");


  // Use 4 threads
  rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), 4);//been modify to galactic syntax
  executor.add_node(DP);
  executor.add_node(FE);
  // executor.add_node(BE);
  executor.add_node(MO);

  executor.spin();

  // Must be called to cleanup threads
  rclcpp::shutdown();

  return 0;
}