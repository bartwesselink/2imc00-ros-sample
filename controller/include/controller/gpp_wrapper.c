//
// Created by Bart Wesselink on 28/02/2022.
//

#include "gpp_wrapper.h"
#include "gpp_engine.h"
#include <stdio.h>

// Initialize variables
void gpp_AssignInputVariables(void) {
    ROS_Distance_Sensor_i_distance_ = 20;
    ROS_Node_Obstacle_Destroyer_Action_Destroy_i_result_ = FALSE;
    ROS_Node_Obstacle_Destroyer_Action_Destroy_i_feedback_ = 0;
    ROS_Node_Robot_Platform_Service_Time_Since_Start_i_result_ = 0;
    ROS_Robot_Platform_i_robot_x_ = 9;
    ROS_Robot_Platform_i_robot_y_ = 9;
}

BoolType gpp_ExecuteDistanceEvent(int distance) {
    ROS_Distance_Sensor_i_distance_ = distance;

    return execEvent0();
}

BoolType gpp_ExecuteRobotXEvent(int robotX) {
    ROS_Robot_Platform_i_robot_x_ = robotX;

    return execEvent15();
}

BoolType gpp_ExecuteRobotYEvent(int robotY) {
    ROS_Robot_Platform_i_robot_y_ = robotY;

    return execEvent16();
}

BoolType gpp_ExecuteServiceCallTimeToStartEvent(long int response) {
    ROS_Node_Robot_Platform_Service_Time_Since_Start_i_result_ = response;

    return execEvent14();
}

BoolType gpp_ExecuteServiceDestroyResponseEvent(BoolType success) {
    ROS_Node_Obstacle_Destroyer_Action_Destroy_i_result_ = success;

    return execEvent5();
}

int gpp_GetDestroyInputRobotX() {
    return ROS_Node_Obstacle_Destroyer_Action_Destroy_input_x_;
}

int gpp_GetDestroyInputRobotY() {
    return ROS_Node_Obstacle_Destroyer_Action_Destroy_input_y_;
}

BoolType gpp_ExecuteEvent(int number) {
    switch (number) {
        case 0:
            return execEvent0();
        case 1:
            return execEvent1();
        case 2:
            return execEvent2();
        case 3:
            return execEvent3();
        case 4:
            return execEvent4();
        case 5:
            return execEvent5();
        case 6:
            return execEvent6();
        case 7:
            return execEvent7();
        case 8:
            return execEvent8();
        case 9:
            return execEvent9();
        case 10:
            return execEvent10();
        case 11:
            return execEvent11();
        case 12:
            return execEvent12();
        case 13:
            return execEvent13();
        case 14:
            return execEvent14();
        case 15:
            return execEvent15();
        case 16:
            return execEvent16();
    }

    return FALSE;
}


void gpp_Init(void) {
    gpp_EngineFirstStep(); // perform initialization, note that MAX_EVENTS is 0
}