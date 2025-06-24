#ifndef LD06_H
#define LD06_H

#include <iostream>
#include "cmd_interface_linux.h"
#include <stdio.h>
#include "lipkg.h"
#include <rclcpp/rclcpp.hpp>
#include "sensor_msgs/msg/laser_scan.hpp"
#include "tofbf.h"
#include <string>
#include <diagnostic_updater/diagnostic_updater.hpp>

using namespace std::chrono_literals;

class LD06 : public rclcpp::Node
{
  public:
    LD06();
    void produce_diagnostics(diagnostic_updater::DiagnosticStatusWrapper& stat);

  private:
    CmdInterfaceLinux cmd_port_;
    rclcpp::TimerBase::SharedPtr loop_timer_;
    LiPkg * lidar_;
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr lidar_pub_;
    void publishLoop();
    bool m_cannot_find_lidar = false;
    bool m_cannot_open_serial_port = false;
};

#endif