/* Headers for the Cif to C translation of gpp.cif
 * Generated file, DO NOT EDIT
 */

#ifndef CIF_C_GPP_ENGINE_H
#define CIF_C_GPP_ENGINE_H

#include "gpp_library.h"

/* Types of the specification.
 * Note that integer ranges are ignored in C.
 */
enum Enumgpp_ {
    _gpp_aborted,
    _gpp_awaiting_response,
    _gpp_down,
    _gpp_error,
    _gpp_executing,
    _gpp_finished,
    _gpp_idle,
    _gpp_left,
    _gpp_received_feedback,
    _gpp_received_response,
    _gpp_right,
    _gpp_up,
    _gpp_X,
};
typedef enum Enumgpp_ gppEnum;

extern const char *enum_names[];
extern int EnumTypePrint(gppEnum value, char *dest, int start, int end);


/* Event declarations. */
enum gppEventEnum_ {
    EVT_INITIAL_,                                                 /**< Initial step. */
    EVT_DELAY_,                                                   /**< Delay step. */
    EVT_TAU_,                                                     /**< Tau step. */
    ROS_Distance_Sensor_u_distance_,                              /**< Event ROS_Distance_Sensor_u_distance. */
    ROS_Environment_Scanner_u_environment_,                       /**< Event ROS_Environment_Scanner_u_environment. */
    ROS_Node_Obstacle_Destroyer_Action_Destroy_c_reset_,          /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_c_reset. */
    ROS_Node_Obstacle_Destroyer_Action_Destroy_c_trigger_,        /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_c_trigger. */
    ROS_Node_Obstacle_Destroyer_Action_Destroy_u_succeeded_,      /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_u_succeeded. */
    ROS_Node_Obstacle_Destroyer_Action_Destroy_u_aborted_,        /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_u_aborted. */
    ROS_Node_Obstacle_Destroyer_Action_Destroy_u_feedback_,       /**< Event ROS_Node_Obstacle_Destroyer_Action_Destroy_u_feedback. */
    ROS_Node_Robot_Platform_u_robot_x_,                           /**< Event ROS_Node_Robot_Platform_u_robot_x. */
    ROS_Node_Robot_Platform_u_robot_y_,                           /**< Event ROS_Node_Robot_Platform_u_robot_y. */
    ROS_Node_Robot_Platform_u_robot_rotation_,                    /**< Event ROS_Node_Robot_Platform_u_robot_rotation. */
    ROS_Node_Robot_Platform_c_move_forward_,                      /**< Event ROS_Node_Robot_Platform_c_move_forward. */
    ROS_Node_Robot_Platform_c_rotate_up_,                         /**< Event ROS_Node_Robot_Platform_c_rotate_up. */
    ROS_Node_Robot_Platform_c_rotate_right_,                      /**< Event ROS_Node_Robot_Platform_c_rotate_right. */
    ROS_Node_Robot_Platform_c_rotate_left_,                       /**< Event ROS_Node_Robot_Platform_c_rotate_left. */
    ROS_Node_Robot_Platform_c_rotate_down_,                       /**< Event ROS_Node_Robot_Platform_c_rotate_down. */
    ROS_Node_Robot_Platform_Service_Time_Since_Start_c_trigger_,  /**< Event ROS_Node_Robot_Platform_Service_Time_Since_Start_c_trigger. */
    ROS_Node_Robot_Platform_Service_Time_Since_Start_c_reset_,    /**< Event ROS_Node_Robot_Platform_Service_Time_Since_Start_c_reset. */
    ROS_Node_Robot_Platform_Service_Time_Since_Start_u_response_, /**< Event ROS_Node_Robot_Platform_Service_Time_Since_Start_u_response. */
    ROS_Node_Robot_Platform_Service_Time_Since_Start_u_error_,    /**< Event ROS_Node_Robot_Platform_Service_Time_Since_Start_u_error. */
    ROS_Robot_Platform_u_robot_x_,                                /**< Event ROS_Robot_Platform_u_robot_x. */
    ROS_Robot_Platform_u_robot_y_,                                /**< Event ROS_Robot_Platform_u_robot_y. */
    ROS_Web_Controller_c_environment_,                            /**< Event ROS_Web_Controller_c_environment. */
    ROS_Web_Controller_c_robot_x_,                                /**< Event ROS_Web_Controller_c_robot_x. */
    ROS_Web_Controller_c_robot_y_,                                /**< Event ROS_Web_Controller_c_robot_y. */
    ROS_Web_Controller_c_robot_rotation_,                         /**< Event ROS_Web_Controller_c_robot_rotation. */
};
typedef enum gppEventEnum_ gpp_Event_;

/** Names of all the events. */
extern const char *gpp_event_names[];

/* Constants. */


/* Input variables. */
extern IntType ROS_Distance_Sensor_i_distance_;                            /**< Input variable "int[0..20] ROS_Distance_Sensor.i_distance". */
extern BoolType ROS_Node_Obstacle_Destroyer_Action_Destroy_i_result_;      /**< Input variable "bool ROS_Node_Obstacle_Destroyer_Action_Destroy.i_result". */
extern IntType ROS_Node_Obstacle_Destroyer_Action_Destroy_i_feedback_;     /**< Input variable "int[0..100] ROS_Node_Obstacle_Destroyer_Action_Destroy.i_feedback". */
extern IntType ROS_Node_Robot_Platform_Service_Time_Since_Start_i_result_; /**< Input variable "int[0..100] ROS_Node_Robot_Platform_Service_Time_Since_Start.i_result". */
extern IntType ROS_Robot_Platform_i_robot_x_;                              /**< Input variable "int[0..20] ROS_Robot_Platform.i_robot_x". */
extern IntType ROS_Robot_Platform_i_robot_y_;                              /**< Input variable "int[0..20] ROS_Robot_Platform.i_robot_y". */

extern void gpp_AssignInputVariables();

/* Declaration of internal functions. */


/* State variables (use for output only). */
extern RealType model_time; /**< Current model time. */
extern gppEnum RequirementStateEvtExcls_;                                /**< Discrete variable "E RequirementStateEvtExcls". */
extern IntType ROS_Distance_Sensor_distance_;                            /**< Discrete variable "int[0..20] ROS_Distance_Sensor.distance". */
extern gppEnum ROS_Distance_Sensor_;                                     /**< Discrete variable "E ROS_Distance_Sensor". */
extern gppEnum ROS_Environment_Scanner_;                                 /**< Discrete variable "E ROS_Environment_Scanner". */
extern BoolType ROS_Node_Obstacle_Destroyer_Action_Destroy_result_;      /**< Discrete variable "bool ROS_Node_Obstacle_Destroyer_Action_Destroy.result". */
extern IntType ROS_Node_Obstacle_Destroyer_Action_Destroy_feedback_;     /**< Discrete variable "int[0..100] ROS_Node_Obstacle_Destroyer_Action_Destroy.feedback". */
extern IntType ROS_Node_Obstacle_Destroyer_Action_Destroy_input_x_;      /**< Discrete variable "int[0..20] ROS_Node_Obstacle_Destroyer_Action_Destroy.input_x". */
extern IntType ROS_Node_Obstacle_Destroyer_Action_Destroy_input_y_;      /**< Discrete variable "int[0..20] ROS_Node_Obstacle_Destroyer_Action_Destroy.input_y". */
extern gppEnum ROS_Node_Obstacle_Destroyer_Action_Destroy_;              /**< Discrete variable "E ROS_Node_Obstacle_Destroyer_Action_Destroy". */
extern gppEnum ROS_Node_Robot_Platform_;                                 /**< Discrete variable "E ROS_Node_Robot_Platform". */
extern IntType ROS_Node_Robot_Platform_Service_Time_Since_Start_result_; /**< Discrete variable "int[0..100] ROS_Node_Robot_Platform_Service_Time_Since_Start.result". */
extern gppEnum ROS_Node_Robot_Platform_Service_Time_Since_Start_;        /**< Discrete variable "E ROS_Node_Robot_Platform_Service_Time_Since_Start". */
extern IntType ROS_Robot_Platform_robot_x_;                              /**< Discrete variable "int[0..20] ROS_Robot_Platform.robot_x". */
extern IntType ROS_Robot_Platform_robot_y_;                              /**< Discrete variable "int[0..20] ROS_Robot_Platform.robot_y". */
extern gppEnum ROS_Robot_Platform_;                                      /**< Discrete variable "E ROS_Robot_Platform". */
extern gppEnum ROS_Web_Controller_;                                      /**< Discrete variable "E ROS_Web_Controller". */
extern gppEnum sup_;                                                     /**< Discrete variable "E sup". */

/* Algebraic and derivative functions (use for output only). */






/* Code entry points. */
void gpp_EngineFirstStep(void);
void gpp_EngineTimeStep(double delta);

#if EVENT_OUTPUT
/**
 * External callback function reporting about the execution of an event.
 * @param event Event veing executed.
 * @param pre If \c TRUE, event is about to be executed. If \c FALSE, event has been executed.
 * @note Function must be implemented externally.
 */
extern void gpp_InfoEvent(gpp_Event_ event, BoolType pre);
#endif

#if PRINT_OUTPUT
/**
 * External callback function to output the given text-line to the given filename.
 * @param text Text to print (does not have a EOL character).
 * @param fname Name of the file to print to.
 */
extern void gpp_PrintOutput(const char *text, const char *fname);
#endif

#endif

BoolType execEvent0(void);
BoolType execEvent1(void);
BoolType execEvent2(void);
BoolType execEvent3(void);
BoolType execEvent4(void);
BoolType execEvent5(void);
BoolType execEvent6(void);
BoolType execEvent7(void);
BoolType execEvent8(void);
BoolType execEvent9(void);
BoolType execEvent10(void);
BoolType execEvent11(void);
BoolType execEvent12(void);
BoolType execEvent13(void);
BoolType execEvent14(void);
BoolType execEvent15(void);
BoolType execEvent16(void);
