/* Cif to C translation of gpp.cif
 * Generated file, DO NOT EDIT
 */

#include <stdio.h>
#include <stdlib.h>
#include "gpp_engine.h"

#ifndef MAX_NUM_EVENTS
#define MAX_NUM_EVENTS 1000
#endif

/* What to do if a range error is found in an assignment? */
#ifdef KEEP_RUNNING
static inline void RangeErrorDetected(void) { /* Do nothing, error is already reported. */ }
#else
static inline void RangeErrorDetected(void) { exit(1); }
#endif

/* Type support code. */
int EnumTypePrint(gppEnum value, char *dest, int start, int end) {
    int last = end - 1;
    const char *lit_name = enum_names[value];
    while (start < last && *lit_name) {
        dest[start++] = *lit_name;
        lit_name++;
    }
    dest[start] = '\0';
    return start;
}


/** Event names. */
const char *gpp_event_names[] = {
    "initial-step",                                                /**< Initial step. */
    "delay-step",                                                  /**< Delay step. */
    "tau",                                                         /**< Tau step. */
    "ROS_Distance_Sensor_u_distance",                              /**< Event ROS_Distance_Sensor_u_distance. */
    "ROS_Environment_Scanner_u_environment",                       /**< Event ROS_Environment_Scanner_u_environment. */
    "ROS_Node_Obstacle_Destroyer_Action_Destroy_c_reset",          /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_c_reset. */
    "ROS_Node_Obstacle_Destroyer_Action_Destroy_c_trigger",        /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_c_trigger. */
    "ROS_Node_Obstacle_Destroyer_Action_Destroy_u_succeeded",      /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_u_succeeded. */
    "ROS_Node_Obstacle_Destroyer_Action_Destroy_u_aborted",        /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_u_aborted. */
    "ROS_Node_Obstacle_Destroyer_Action_Destroy_u_feedback",       /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_u_feedback. */
    "ROS_Node_Robot_Platform_u_robot_x",                           /**< Event ROS_Node_Robot_Platform_u_robot_x. */
    "ROS_Node_Robot_Platform_u_robot_y",                           /**< Event ROS_Node_Robot_Platform_u_robot_y. */
    "ROS_Node_Robot_Platform_u_robot_rotation",                    /**< Event ROS_Node_Robot_Platform_u_robot_rotation. */
    "ROS_Node_Robot_Platform_c_move_forward",                      /**< Event ROS_Node_Robot_Platform_c_move_forward. */
    "ROS_Node_Robot_Platform_c_rotate_up",                         /**< Event ROS_Node_Robot_Platform_c_rotate_up. */
    "ROS_Node_Robot_Platform_c_rotate_right",                      /**< Event ROS_Node_Robot_Platform_c_rotate_right. */
    "ROS_Node_Robot_Platform_c_rotate_left",                       /**< Event ROS_Node_Robot_Platform_c_rotate_left. */
    "ROS_Node_Robot_Platform_c_rotate_down",                       /**< Event ROS_Node_Robot_Platform_c_rotate_down. */
    "ROS_Node_Robot_Platform_Service_Time_Since_Start_c_trigger",  /**< Event ROS_Node_Robot_Platform_Service_Time_Since_Start_c_trigger. */
    "ROS_Node_Robot_Platform_Service_Time_Since_Start_c_reset",    /**< Event ROS_Node_Robot_Platform_Service_Time_Since_Start_c_reset. */
    "ROS_Node_Robot_Platform_Service_Time_Since_Start_u_response", /**< Event ROS_Node_Robot_Platform_Service_Time_Since_Start_u_response. */
    "ROS_Node_Robot_Platform_Service_Time_Since_Start_u_error",    /**< Event ROS_Node_Robot_Platform_Service_Time_Since_Start_u_error. */
    "ROS_Robot_Platform_u_robot_x",                                /**< Event ROS_Robot_Platform_u_robot_x. */
    "ROS_Robot_Platform_u_robot_y",                                /**< Event ROS_Robot_Platform_u_robot_y. */
    "ROS_Web_Controller_c_environment",                            /**< Event ROS_Web_Controller_c_environment. */
    "ROS_Web_Controller_c_robot_x",                                /**< Event ROS_Web_Controller_c_robot_x. */
    "ROS_Web_Controller_c_robot_y",                                /**< Event ROS_Web_Controller_c_robot_y. */
    "ROS_Web_Controller_c_robot_rotation",                         /**< Event ROS_Web_Controller_c_robot_rotation. */
};

/** Enumeration names. */
const char *enum_names[] = {
    "aborted",
    "awaiting_response",
    "down",
    "error",
    "executing",
    "finished",
    "idle",
    "left",
    "received_feedback",
    "received_response",
    "right",
    "up",
    "X",
};

/* Constants. */


/* Functions. */


/* Input variables. */
IntType ROS_Distance_Sensor_i_distance_;                            /**< Input variable "int[0..20] ROS_Distance_Sensor.i_distance". */
BoolType ROS_Node_Obstacle_Destroyer_Action_Destroy_i_result_;      /**< Input variable "bool ROS_Node_Obstacle_Destroyer_Action_Destroy.i_result". */
IntType ROS_Node_Obstacle_Destroyer_Action_Destroy_i_feedback_;     /**< Input variable "int[0..100] ROS_Node_Obstacle_Destroyer_Action_Destroy.i_feedback". */
IntType ROS_Node_Robot_Platform_Service_Time_Since_Start_i_result_; /**< Input variable "int[0..100] ROS_Node_Robot_Platform_Service_Time_Since_Start.i_result". */
IntType ROS_Robot_Platform_i_robot_x_;                              /**< Input variable "int[0..20] ROS_Robot_Platform.i_robot_x". */
IntType ROS_Robot_Platform_i_robot_y_;                              /**< Input variable "int[0..20] ROS_Robot_Platform.i_robot_y". */

/* State variables. */
gppEnum RequirementStateEvtExcls_;                                /**< Discrete variable "E RequirementStateEvtExcls". */
IntType ROS_Distance_Sensor_distance_;                            /**< Discrete variable "int[0..20] ROS_Distance_Sensor.distance". */
gppEnum ROS_Distance_Sensor_;                                     /**< Discrete variable "E ROS_Distance_Sensor". */
gppEnum ROS_Environment_Scanner_;                                 /**< Discrete variable "E ROS_Environment_Scanner". */
BoolType ROS_Node_Obstacle_Destroyer_Action_Destroy_result_;      /**< Discrete variable "bool ROS_Node_Obstacle_Destroyer_Action_Destroy.result". */
IntType ROS_Node_Obstacle_Destroyer_Action_Destroy_feedback_;     /**< Discrete variable "int[0..100] ROS_Node_Obstacle_Destroyer_Action_Destroy.feedback". */
IntType ROS_Node_Obstacle_Destroyer_Action_Destroy_input_x_;      /**< Discrete variable "int[0..20] ROS_Node_Obstacle_Destroyer_Action_Destroy.input_x". */
IntType ROS_Node_Obstacle_Destroyer_Action_Destroy_input_y_;      /**< Discrete variable "int[0..20] ROS_Node_Obstacle_Destroyer_Action_Destroy.input_y". */
gppEnum ROS_Node_Obstacle_Destroyer_Action_Destroy_;              /**< Discrete variable "E ROS_Node_Obstacle_Destroyer_Action_Destroy". */
gppEnum ROS_Node_Robot_Platform_;                                 /**< Discrete variable "E ROS_Node_Robot_Platform". */
IntType ROS_Node_Robot_Platform_Service_Time_Since_Start_result_; /**< Discrete variable "int[0..100] ROS_Node_Robot_Platform_Service_Time_Since_Start.result". */
gppEnum ROS_Node_Robot_Platform_Service_Time_Since_Start_;        /**< Discrete variable "E ROS_Node_Robot_Platform_Service_Time_Since_Start". */
IntType ROS_Robot_Platform_robot_x_;                              /**< Discrete variable "int[0..20] ROS_Robot_Platform.robot_x". */
IntType ROS_Robot_Platform_robot_y_;                              /**< Discrete variable "int[0..20] ROS_Robot_Platform.robot_y". */
gppEnum ROS_Robot_Platform_;                                      /**< Discrete variable "E ROS_Robot_Platform". */
gppEnum ROS_Web_Controller_;                                      /**< Discrete variable "E ROS_Web_Controller". */
gppEnum sup_;                                                     /**< Discrete variable "E sup". */

RealType model_time; /**< Current model time. */

/** Initialize constants. */
static void InitConstants(void) {

}

/** Print function. */
#if PRINT_OUTPUT
static void PrintOutput(gpp_Event_ event, BoolType pre) {
}
#endif

/* Event execution code. */

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent0(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = ROS_Distance_Sensor_i_distance_;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Obstacle_Destroyer_Action_Destroy.c_reset".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent1(void) {
    BoolType guard = (((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_aborted)) || ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_finished))) && ((sup_) == (_gpp_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_c_reset_, TRUE);
    #endif

    if ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_aborted)) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_idle;
    } else if ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_finished)) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_idle;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_c_reset_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Obstacle_Destroyer_Action_Destroy.c_trigger".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent2(void) {
    BoolType guard = ((((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Distance_Sensor_distance_) == (0))) && ((((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_idle)) && ((((ROS_Node_Robot_Platform_) == (_gpp_left)) || ((ROS_Node_Robot_Platform_) == (_gpp_right))) || (((ROS_Node_Robot_Platform_) == (_gpp_up)) || ((ROS_Node_Robot_Platform_) == (_gpp_down))))) && ((sup_) == (_gpp_X)))) && (((((ROS_Node_Robot_Platform_ != _gpp_right)) || ((ROS_Robot_Platform_robot_x_) != (20))) && (((ROS_Node_Robot_Platform_ != _gpp_up)) || ((ROS_Robot_Platform_robot_y_) != (20)))) && ((((ROS_Node_Robot_Platform_ != _gpp_left)) || ((ROS_Robot_Platform_robot_x_) != (0))) && (((ROS_Node_Robot_Platform_ != _gpp_down)) || ((ROS_Robot_Platform_robot_y_) != (0)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_c_trigger_, TRUE);
    #endif

    if (((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_idle)) && ((ROS_Node_Robot_Platform_) == (_gpp_left))) {
        {
            IntType rhs2 = (ROS_Robot_Platform_robot_x_) - (1);
            #if CHECK_RANGES
            if ((rhs2) < 0) {
                fprintf(stderr, "RangeError: Writing %d into \"int[0..20]\"\n", rhs2);
                fprintf(stderr, "            at " "ROS_Node_Obstacle_Destroyer_Action_Destroy.input_x" "\n");
                RangeErrorDetected();
            }
            #endif
            ROS_Node_Obstacle_Destroyer_Action_Destroy_input_x_ = rhs2;
        }
        ROS_Node_Obstacle_Destroyer_Action_Destroy_input_y_ = ROS_Robot_Platform_robot_y_;
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_executing;
    } else if (((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_idle)) && ((ROS_Node_Robot_Platform_) == (_gpp_right))) {
        {
            IntType rhs2 = (ROS_Robot_Platform_robot_x_) + (1);
            #if CHECK_RANGES
            if ((rhs2) > 20) {
                fprintf(stderr, "RangeError: Writing %d into \"int[0..20]\"\n", rhs2);
                fprintf(stderr, "            at " "ROS_Node_Obstacle_Destroyer_Action_Destroy.input_x" "\n");
                RangeErrorDetected();
            }
            #endif
            ROS_Node_Obstacle_Destroyer_Action_Destroy_input_x_ = rhs2;
        }
        ROS_Node_Obstacle_Destroyer_Action_Destroy_input_y_ = ROS_Robot_Platform_robot_y_;
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_executing;
    } else if (((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_idle)) && ((ROS_Node_Robot_Platform_) == (_gpp_up))) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_input_x_ = ROS_Robot_Platform_robot_x_;
        {
            IntType rhs2 = (ROS_Robot_Platform_robot_y_) + (1);
            #if CHECK_RANGES
            if ((rhs2) > 20) {
                fprintf(stderr, "RangeError: Writing %d into \"int[0..20]\"\n", rhs2);
                fprintf(stderr, "            at " "ROS_Node_Obstacle_Destroyer_Action_Destroy.input_y" "\n");
                RangeErrorDetected();
            }
            #endif
            ROS_Node_Obstacle_Destroyer_Action_Destroy_input_y_ = rhs2;
        }
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_executing;
    } else if (((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_idle)) && ((ROS_Node_Robot_Platform_) == (_gpp_down))) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_input_x_ = ROS_Robot_Platform_robot_x_;
        {
            IntType rhs2 = (ROS_Robot_Platform_robot_y_) - (1);
            #if CHECK_RANGES
            if ((rhs2) < 0) {
                fprintf(stderr, "RangeError: Writing %d into \"int[0..20]\"\n", rhs2);
                fprintf(stderr, "            at " "ROS_Node_Obstacle_Destroyer_Action_Destroy.input_y" "\n");
                RangeErrorDetected();
            }
            #endif
            ROS_Node_Obstacle_Destroyer_Action_Destroy_input_y_ = rhs2;
        }
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_executing;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_c_trigger_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Obstacle_Destroyer_Action_Destroy.u_aborted".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent3(void) {
    BoolType guard = ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_executing)) || ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_received_feedback));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_u_aborted_, TRUE);
    #endif

    if ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_executing)) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_aborted;
    } else if ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_received_feedback)) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_aborted;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_u_aborted_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Obstacle_Destroyer_Action_Destroy.u_feedback".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent4(void) {
    BoolType guard = ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_executing)) || ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_received_feedback));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_u_feedback_, TRUE);
    #endif

    if ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_executing)) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_feedback_ = ROS_Node_Obstacle_Destroyer_Action_Destroy_i_feedback_;
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_received_feedback;
    } else if ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_received_feedback)) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_feedback_ = ROS_Node_Obstacle_Destroyer_Action_Destroy_i_feedback_;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_u_feedback_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Obstacle_Destroyer_Action_Destroy.u_succeeded".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent5(void) {
    BoolType guard = ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_executing)) || ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_received_feedback));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_u_succeeded_, TRUE);
    #endif

    if ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_executing)) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_result_ = ROS_Node_Obstacle_Destroyer_Action_Destroy_i_result_;
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_finished;
    } else if ((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_received_feedback)) {
        ROS_Node_Obstacle_Destroyer_Action_Destroy_result_ = ROS_Node_Obstacle_Destroyer_Action_Destroy_i_result_;
        ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_finished;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Obstacle_Destroyer_Action_Destroy_u_succeeded_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform.c_move_forward".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent6(void) {
    BoolType guard = (((RequirementStateEvtExcls_) == (_gpp_X)) && (((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_received_response)) && ((ROS_Distance_Sensor_distance_) > (0)))) && ((((ROS_Node_Robot_Platform_Service_Time_Since_Start_result_) <= (120)) && ((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_left))) || (((ROS_Node_Robot_Platform_) == (_gpp_up)) || ((ROS_Node_Robot_Platform_) == (_gpp_down))))) && ((sup_) == (_gpp_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_move_forward_, TRUE);
    #endif

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_move_forward_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform.c_rotate_down".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent7(void) {
    BoolType guard = ((((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_received_response))) && (((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_idle)) && ((ROS_Node_Robot_Platform_ != _gpp_down)))) && ((((ROS_Distance_Sensor_distance_) < (0)) && ((ROS_Node_Robot_Platform_Service_Time_Since_Start_result_) <= (120))) && (((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_left))) || (((ROS_Node_Robot_Platform_) == (_gpp_up)) || ((ROS_Node_Robot_Platform_) == (_gpp_down)))) && ((sup_) == (_gpp_X))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_down_, TRUE);
    #endif

    if ((ROS_Node_Robot_Platform_) == (_gpp_right)) {
        ROS_Node_Robot_Platform_ = _gpp_down;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_left)) {
        ROS_Node_Robot_Platform_ = _gpp_down;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_up)) {
        ROS_Node_Robot_Platform_ = _gpp_down;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_down)) {
        ROS_Node_Robot_Platform_ = _gpp_down;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_down_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform.c_rotate_left".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent8(void) {
    BoolType guard = ((((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_received_response))) && (((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_idle)) && ((ROS_Node_Robot_Platform_ != _gpp_left)))) && ((((ROS_Distance_Sensor_distance_) < (0)) && ((ROS_Node_Robot_Platform_Service_Time_Since_Start_result_) <= (120))) && (((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_left))) || (((ROS_Node_Robot_Platform_) == (_gpp_up)) || ((ROS_Node_Robot_Platform_) == (_gpp_down)))) && ((sup_) == (_gpp_X))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_left_, TRUE);
    #endif

    if ((ROS_Node_Robot_Platform_) == (_gpp_right)) {
        ROS_Node_Robot_Platform_ = _gpp_left;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_left)) {
        ROS_Node_Robot_Platform_ = _gpp_left;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_up)) {
        ROS_Node_Robot_Platform_ = _gpp_left;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_down)) {
        ROS_Node_Robot_Platform_ = _gpp_left;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_left_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform.c_rotate_right".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent9(void) {
    BoolType guard = ((((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_received_response))) && (((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_idle)) && ((ROS_Node_Robot_Platform_ != _gpp_right)))) && ((((ROS_Distance_Sensor_distance_) < (0)) && ((ROS_Node_Robot_Platform_Service_Time_Since_Start_result_) <= (120))) && (((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_left))) || (((ROS_Node_Robot_Platform_) == (_gpp_up)) || ((ROS_Node_Robot_Platform_) == (_gpp_down)))) && ((sup_) == (_gpp_X))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_right_, TRUE);
    #endif

    if ((ROS_Node_Robot_Platform_) == (_gpp_right)) {
        ROS_Node_Robot_Platform_ = _gpp_right;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_left)) {
        ROS_Node_Robot_Platform_ = _gpp_right;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_up)) {
        ROS_Node_Robot_Platform_ = _gpp_right;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_down)) {
        ROS_Node_Robot_Platform_ = _gpp_right;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_right_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform.c_rotate_up".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent10(void) {
    BoolType guard = ((((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_received_response))) && (((ROS_Node_Obstacle_Destroyer_Action_Destroy_) == (_gpp_idle)) && ((ROS_Node_Robot_Platform_ != _gpp_up)))) && ((((ROS_Distance_Sensor_distance_) < (0)) && ((ROS_Node_Robot_Platform_Service_Time_Since_Start_result_) <= (120))) && (((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_left))) || (((ROS_Node_Robot_Platform_) == (_gpp_up)) || ((ROS_Node_Robot_Platform_) == (_gpp_down)))) && ((sup_) == (_gpp_X))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_up_, TRUE);
    #endif

    if ((ROS_Node_Robot_Platform_) == (_gpp_right)) {
        ROS_Node_Robot_Platform_ = _gpp_up;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_left)) {
        ROS_Node_Robot_Platform_ = _gpp_up;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_up)) {
        ROS_Node_Robot_Platform_ = _gpp_up;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_down)) {
        ROS_Node_Robot_Platform_ = _gpp_up;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_up_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform_Service_Time_Since_Start.c_reset".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent11(void) {
    BoolType guard = (((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_error)) || ((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_received_response))) && ((sup_) == (_gpp_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_Service_Time_Since_Start_c_reset_, TRUE);
    #endif

    if ((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_error)) {
        ROS_Node_Robot_Platform_Service_Time_Since_Start_ = _gpp_idle;
    } else if ((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_received_response)) {
        ROS_Node_Robot_Platform_Service_Time_Since_Start_ = _gpp_idle;
    }

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_Service_Time_Since_Start_c_reset_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform_Service_Time_Since_Start.c_trigger".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent12(void) {
    BoolType guard = ((ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_idle)) && ((sup_) == (_gpp_X));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_Service_Time_Since_Start_c_trigger_, TRUE);
    #endif

    ROS_Node_Robot_Platform_Service_Time_Since_Start_ = _gpp_awaiting_response;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_Service_Time_Since_Start_c_trigger_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform_Service_Time_Since_Start.u_error".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent13(void) {
    BoolType guard = (ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_awaiting_response);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_Service_Time_Since_Start_u_error_, TRUE);
    #endif

    ROS_Node_Robot_Platform_Service_Time_Since_Start_ = _gpp_error;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_Service_Time_Since_Start_u_error_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform_Service_Time_Since_Start.u_response".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent14(void) {
    BoolType guard = (ROS_Node_Robot_Platform_Service_Time_Since_Start_) == (_gpp_awaiting_response);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_Service_Time_Since_Start_u_response_, TRUE);
    #endif

    ROS_Node_Robot_Platform_Service_Time_Since_Start_result_ = ROS_Node_Robot_Platform_Service_Time_Since_Start_i_result_;
    ROS_Node_Robot_Platform_Service_Time_Since_Start_ = _gpp_received_response;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_Service_Time_Since_Start_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Robot_Platform.u_robot_x".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent15(void) {
    BoolType guard = (ROS_Robot_Platform_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Robot_Platform_u_robot_x_, TRUE);
    #endif

    ROS_Robot_Platform_robot_x_ = ROS_Robot_Platform_i_robot_x_;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Robot_Platform_u_robot_x_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Robot_Platform.u_robot_y".
 *
 * @return Whether the event was performed.
 */
BoolType execEvent16(void) {
    BoolType guard = (ROS_Robot_Platform_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Robot_Platform_u_robot_y_, TRUE);
    #endif

    ROS_Robot_Platform_robot_y_ = ROS_Robot_Platform_i_robot_y_;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Robot_Platform_u_robot_y_, FALSE);
    #endif
    return TRUE;
}

/**
 * Normalize and check the new value of a continuous variable after an update.
 * @param new_value Unnormalized new value of the continuous variable.
 * @param var_name Name of the continuous variabl ein the CIF model.
 * @return The normalized new value of the continuous variable.
 */
static inline RealType UpdateContValue(RealType new_value, const char *var_name) {
    if (isfinite(new_value)) {
        return (new_value == -0.0) ? 0.0 : new_value;
    }

    const char *err_type;
    if (isnan(new_value)) {
        err_type = "NaN";
    } else if (new_value > 0) {
        err_type = "+inf";
    } else {
        err_type = "-inf";
    }
    fprintf(stderr, "Continuous variable \"%s\" has become %s.\n", var_name, err_type);

#ifdef KEEP_RUNNING
    return 0.0;
#else
    exit(1);
#endif
}

/** Repeatedly perform discrete event steps, until no progress can be made any more. */
static void PerformEvents(void) {
    int count = 0;
    for (;;) {
        count++;
        if (count > MAX_NUM_EVENTS) { /* 'Infinite' loop detection. */
            fprintf(stderr, "Warning: Quitting after performing %d events, infinite loop?\n", count);
            break;
        }

        if (execEvent0()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance". */
        if (execEvent1()) continue;  /* (Try to) perform event "ROS_Node_Obstacle_Destroyer_Action_Destroy.c_reset". */
        if (execEvent2()) continue;  /* (Try to) perform event "ROS_Node_Obstacle_Destroyer_Action_Destroy.c_trigger". */
        if (execEvent3()) continue;  /* (Try to) perform event "ROS_Node_Obstacle_Destroyer_Action_Destroy.u_aborted". */
        if (execEvent4()) continue;  /* (Try to) perform event "ROS_Node_Obstacle_Destroyer_Action_Destroy.u_feedback". */
        if (execEvent5()) continue;  /* (Try to) perform event "ROS_Node_Obstacle_Destroyer_Action_Destroy.u_succeeded". */
        if (execEvent6()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_move_forward". */
        if (execEvent7()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_rotate_down". */
        if (execEvent8()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_rotate_left". */
        if (execEvent9()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_rotate_right". */
        if (execEvent10()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_rotate_up". */
        if (execEvent11()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform_Service_Time_Since_Start.c_reset". */
        if (execEvent12()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform_Service_Time_Since_Start.c_trigger". */
        if (execEvent13()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform_Service_Time_Since_Start.u_error". */
        if (execEvent14()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform_Service_Time_Since_Start.u_response". */
        if (execEvent15()) continue;  /* (Try to) perform event "ROS_Robot_Platform.u_robot_x". */
        if (execEvent16()) continue;  /* (Try to) perform event "ROS_Robot_Platform.u_robot_y". */
        break; /* No event fired, done with discrete steps. */
    }
}

/** First model call, initializing, and performing discrete events before the first time step. */
void gpp_EngineFirstStep(void) {
    InitConstants();

    model_time = 0.0;
    gpp_AssignInputVariables();
    RequirementStateEvtExcls_ = _gpp_X;
    ROS_Distance_Sensor_distance_ = 20;
    ROS_Distance_Sensor_ = _gpp_X;
    ROS_Environment_Scanner_ = _gpp_X;
    ROS_Node_Obstacle_Destroyer_Action_Destroy_result_ = FALSE;
    ROS_Node_Obstacle_Destroyer_Action_Destroy_feedback_ = 0;
    ROS_Node_Obstacle_Destroyer_Action_Destroy_input_x_ = 0;
    ROS_Node_Obstacle_Destroyer_Action_Destroy_input_y_ = 0;
    ROS_Node_Obstacle_Destroyer_Action_Destroy_ = _gpp_idle;
    ROS_Node_Robot_Platform_ = _gpp_right;
    ROS_Node_Robot_Platform_Service_Time_Since_Start_result_ = 0;
    ROS_Node_Robot_Platform_Service_Time_Since_Start_ = _gpp_idle;
    ROS_Robot_Platform_robot_x_ = 0;
    ROS_Robot_Platform_robot_y_ = 0;
    ROS_Robot_Platform_ = _gpp_X;
    ROS_Web_Controller_ = _gpp_X;
    sup_ = _gpp_X;

    #if PRINT_OUTPUT
        /* pre-initial and post-initial prints. */
        PrintOutput(EVT_INITIAL_, TRUE);
        PrintOutput(EVT_INITIAL_, FALSE);
    #endif

    PerformEvents();

    #if PRINT_OUTPUT
        /* pre-timestep print. */
        PrintOutput(EVT_DELAY_, TRUE);
    #endif
}

/**
 * Engine takes a time step of length \a delta.
 * @param delta Length of the time step.
 */
void gpp_EngineTimeStep(double delta) {
    gpp_AssignInputVariables();

    /* Update continuous variables. */
    if (delta > 0.0) {

        model_time += delta;
    }

    #if PRINT_OUTPUT
        /* post-timestep print. */
        PrintOutput(EVT_DELAY_, FALSE);
    #endif

    PerformEvents();

    #if PRINT_OUTPUT
        /* pre-timestep print. */
        PrintOutput(EVT_DELAY_, TRUE);
    #endif
}

