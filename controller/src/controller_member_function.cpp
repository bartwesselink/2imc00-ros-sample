// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <memory>
#include <thread>
#include <unistd.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/empty.hpp"
#include "std_msgs/msg/int16.hpp"
using std::placeholders::_1;

extern "C" {
    #include "../include/controller/gpp_engine.h"
}

using namespace std::chrono_literals;

class Controller : public rclcpp::Node {
public:
    Controller()
            : Node("controller"), count_(0) {
        publisher_controllable_move_forward = this->create_publisher<std_msgs::msg::Empty>("move_forward", 10);
        publisher_controllable_rotate_down = this->create_publisher<std_msgs::msg::Empty>("rotate_down", 10);
        publisher_controllable_rotate_left = this->create_publisher<std_msgs::msg::Empty>("rotate_left", 10);
        publisher_controllable_rotate_up = this->create_publisher<std_msgs::msg::Empty>("rotate_up", 10);
        publisher_controllable_rotate_right = this->create_publisher<std_msgs::msg::Empty>("rotate_right", 10);

        subscription_uncontrollable_distance = this->create_subscription<std_msgs::msg::Int16>(
                "distance", 10, std::bind(&Controller::callback_distance, this, _1));

        timer_ = this->create_wall_timer(
                500ms, std::bind(&Controller::tick, this));

        gpp_Init();
    }

private:
    void tick() {
        auto executed = gpp_ControllableEvent();

        if (executed >= 0) {
            emit_controllable_events(executed);
        }
    }

    void callback_distance(const std_msgs::msg::Int16::SharedPtr msg) {
        int result = msg->data;

        gpp_DistanceEvent(result);
    }

    void emit_controllable_events(int i) {
        auto message = std_msgs::msg::Empty();

        switch (i) {
            case 21:
                publisher_controllable_move_forward->publish(message);
                break;
            case 22:
                publisher_controllable_rotate_down->publish(message);
                break;
            case 23:
                publisher_controllable_rotate_left->publish(message);
                break;
            case 24:
                publisher_controllable_rotate_up->publish(message);
                break;
            case 25:
                publisher_controllable_rotate_right->publish(message);
                break;
        }
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr publisher_controllable_move_forward;
    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr publisher_controllable_rotate_down;
    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr publisher_controllable_rotate_left;
    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr publisher_controllable_rotate_up;
    rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr publisher_controllable_rotate_right;

    rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr subscription_uncontrollable_distance;

    size_t count_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Controller>());
    rclcpp::shutdown();

    return 0;
}
