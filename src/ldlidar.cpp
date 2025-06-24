#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include <ldlidar_node.h>

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto ld06_node = std::make_shared<LD06>();
  diagnostic_updater::Updater updater(ld06_node);
  updater.setHardwareID("LD06");
  updater.add("LD06 diag", ld06_node.get(), &LD06::produce_diagnostics);

  rclcpp::spin(ld06_node);  rclcpp::shutdown();
  return 0;
}