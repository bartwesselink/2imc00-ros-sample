//
// Created by Bart Wesselink on 28/02/2022.
//
#include "gpp_library.h"
#include <time.h>

#ifndef INC_2IMC00_ROS_SAMPLE_GPP_WRAPPER_H
#define INC_2IMC00_ROS_SAMPLE_GPP_WRAPPER_H

BoolType gpp_ExecuteDistanceEvent(int distance);
BoolType gpp_ExecuteRobotXEvent(int robotX);
BoolType gpp_ExecuteRobotYEvent(int robotY);
BoolType gpp_ExecuteServiceCallTimeToStartEvent(long int response);
BoolType gpp_ExecuteServiceDestroyResponseEvent(BoolType success);
BoolType gpp_ExecuteEvent(int number);
int gpp_GetDestroyInputRobotX();
int gpp_GetDestroyInputRobotY();
void gpp_Init(void);

#endif //INC_2IMC00_ROS_SAMPLE_GPP_WRAPPER_H
