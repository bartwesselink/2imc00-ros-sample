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
#include <functional>
#include <future>
#include <memory>
#include <sstream>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/empty.hpp"
#include "std_msgs/msg/int16.hpp"
#include "communication_interfaces/srv/time_since_start.hpp"
#include "communication_interfaces/action/destroy_obstacle.hpp"
#include <cinttypes>

extern "C" {
    #include "../include/controller/gpp_wrapper.h"
}

using namespace std::chrono_literals;


void shuffle(int *x, size_t n)
{
    if (n > 1)
    {
        srand(time(NULL));

        for (int i = 0; i < n-1; ++i)
        {
            int j = rand() % (n-i) + i;
            int temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
    }
}

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
                "distance", 10, std::bind(&Controller::callback_distance, this, std::placeholders::_1));

        subscription_uncontrollable_robot_x = this->create_subscription<std_msgs::msg::Int16>(
                "robot_x", 10, std::bind(&Controller::callback_robot_x, this, std::placeholders::_1));

        subscription_uncontrollable_robot_y = this->create_subscription<std_msgs::msg::Int16>(
                "robot_y", 10, std::bind(&Controller::callback_robot_y, this, std::placeholders::_1));

        service_client_time_since_start = this->create_client<communication_interfaces::srv::TimeSinceStart>("time_since_start");

        action_client_destroy = rclcpp_action::create_client<communication_interfaces::action::DestroyObstacle>(this, "destroy_obstacle");

        timer_ = this->create_wall_timer(500ms, std::bind(&Controller::tick, this));

        gpp_Init();
    }

private:
    void tick() {
        int n = 9;
        int controllable_events[9] = { 1, 2, 6, 7, 8, 9, 10, 11, 12 };

        shuffle(controllable_events, n);

        for (int i = 0; i < n; i++) {
            BoolType result = gpp_ExecuteEvent(controllable_events[i]);

            if (result) {
                emit_controllable_events(controllable_events[i]);
            }
        }
    }

    // GENERATE
    void callback_distance(const std_msgs::msg::Int16::SharedPtr msg) {
        int result = msg->data;

        gpp_ExecuteDistanceEvent(result);
    }

    void callback_robot_x(const std_msgs::msg::Int16::SharedPtr msg) {
        int result = msg->data;

        gpp_ExecuteRobotXEvent(result);
    }

    void callback_robot_y(const std_msgs::msg::Int16::SharedPtr msg) {
        int result = msg->data;

        gpp_ExecuteRobotYEvent(result);
    }
    // END GENERATE

    // GENERATE
    void call_time_to_start() {
        auto request = std::make_shared<communication_interfaces::srv::TimeSinceStart::Request>();

        if (!service_client_time_since_start->wait_for_service()) { // change timeout for repeat
            if (!rclcpp::ok()) {
                gpp_ExecuteEvent(12);
                return;
            }
            gpp_ExecuteEvent(12);
            return;
        }

        using ServiceResponseFuture =
        rclcpp::Client<communication_interfaces::srv::TimeSinceStart>::SharedFutureWithRequest;
        auto result = service_client_time_since_start->async_send_request(
                request, std::bind(&Controller::response_time_to_start, this, std::placeholders::_1));
    }

    bool response_time_to_start(rclcpp::Client<communication_interfaces::srv::TimeSinceStart>::SharedFuture future) {
        std::shared_ptr<communication_interfaces::srv::TimeSinceStart_Response> result = future.get();

        gpp_ExecuteServiceCallTimeToStartEvent(result->result);

        return true;
    }
    // END GENERATE

    // GENERATE
    void call_destroy_action() {
        if (!this->action_client_destroy->wait_for_action_server(1s)) {
            return;
        }

        auto goal_msg = communication_interfaces::action::DestroyObstacle::Goal();
        goal_msg.x = gpp_GetDestroyInputRobotX();
        goal_msg.y = gpp_GetDestroyInputRobotY();

        auto send_goal_options = rclcpp_action::Client<communication_interfaces::action::DestroyObstacle>::SendGoalOptions();
        send_goal_options.result_callback =
                std::bind(&Controller::response_destroy_action, this, std::placeholders::_1);
        this->action_client_destroy->async_send_goal(goal_msg, send_goal_options);
    }

    void response_destroy_action(const rclcpp_action::ClientGoalHandle<communication_interfaces::action::DestroyObstacle>::WrappedResult & result) {
        gpp_ExecuteServiceDestroyResponseEvent(TRUE);
    }
    // END GENERATE

    void emit_controllable_events(int i) {
        auto message = std_msgs::msg::Empty();
        switch (i) {
            case 2:
                this->call_destroy_action();
                break;
            case 6:
                publisher_controllable_move_forward->publish(message);
                break;
            case 7:
                publisher_controllable_rotate_down->publish(message);
                break;
            case 8:
                publisher_controllable_rotate_left->publish(message);
                break;
            case 9:
                publisher_controllable_rotate_right->publish(message);
                break;
            case 10:
                publisher_controllable_rotate_up->publish(message);
                break;
            case 12:
                this->call_time_to_start();
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
    rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr subscription_uncontrollable_robot_x;
    rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr subscription_uncontrollable_robot_y;

    // Service clients
    rclcpp::Client<communication_interfaces::srv::TimeSinceStart>::SharedPtr service_client_time_since_start;

    // Action clients
    rclcpp_action::Client<communication_interfaces::action::DestroyObstacle>::SharedPtr action_client_destroy;
    size_t count_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Controller>());
    rclcpp::shutdown();

    return 0;
}
