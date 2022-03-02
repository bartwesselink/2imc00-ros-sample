cmake_minimum_required(VERSION 3.5)
project(controller)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -std=c99)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(communication_interfaces REQUIRED)

add_library(gpp_wrapper include/controller/gpp_wrapper.c)
add_library(gpp_engine include/controller/gpp_engine.c)
add_executable(interface src/controller_member_function.cpp)

add_definitions(-DMAX_NUM_EVENTS=0)

target_link_libraries(gpp_wrapper gpp_engine)
target_link_libraries(interface gpp_wrapper)

ament_target_dependencies(interface rclcpp std_msgs rclcpp_action communication_interfaces)

install(TARGETS
        interface
        DESTINATION lib/${PROJECT_NAME})

ament_package()