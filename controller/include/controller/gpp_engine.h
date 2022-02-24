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
    _gpp_down,
    _gpp_left,
    _gpp_right,
    _gpp_up,
    _gpp_X,
};
typedef enum Enumgpp_ gppEnum;

extern const char *enum_names[];
extern int EnumTypePrint(gppEnum value, char *dest, int start, int end);


/* Event declarations. */
enum gppEventEnum_ {
    EVT_INITIAL_,                              /**< Initial step. */
    EVT_DELAY_,                                /**< Delay step. */
    EVT_TAU_,                                  /**< Tau step. */
    ROS_Distance_Sensor_u_distance_0_,         /**< Event ROS_Distance_Sensor_u_distance_0. */
    ROS_Distance_Sensor_u_distance_1_,         /**< Event ROS_Distance_Sensor_u_distance_1. */
    ROS_Distance_Sensor_u_distance_2_,         /**< Event ROS_Distance_Sensor_u_distance_2. */
    ROS_Distance_Sensor_u_distance_3_,         /**< Event ROS_Distance_Sensor_u_distance_3. */
    ROS_Distance_Sensor_u_distance_4_,         /**< Event ROS_Distance_Sensor_u_distance_4. */
    ROS_Distance_Sensor_u_distance_5_,         /**< Event ROS_Distance_Sensor_u_distance_5. */
    ROS_Distance_Sensor_u_distance_6_,         /**< Event ROS_Distance_Sensor_u_distance_6. */
    ROS_Distance_Sensor_u_distance_7_,         /**< Event ROS_Distance_Sensor_u_distance_7. */
    ROS_Distance_Sensor_u_distance_8_,         /**< Event ROS_Distance_Sensor_u_distance_8. */
    ROS_Distance_Sensor_u_distance_9_,         /**< Event ROS_Distance_Sensor_u_distance_9. */
    ROS_Distance_Sensor_u_distance_10_,        /**< Event ROS_Distance_Sensor_u_distance_10. */
    ROS_Distance_Sensor_u_distance_11_,        /**< Event ROS_Distance_Sensor_u_distance_11. */
    ROS_Distance_Sensor_u_distance_12_,        /**< Event ROS_Distance_Sensor_u_distance_12. */
    ROS_Distance_Sensor_u_distance_13_,        /**< Event ROS_Distance_Sensor_u_distance_13. */
    ROS_Distance_Sensor_u_distance_14_,        /**< Event ROS_Distance_Sensor_u_distance_14. */
    ROS_Distance_Sensor_u_distance_15_,        /**< Event ROS_Distance_Sensor_u_distance_15. */
    ROS_Distance_Sensor_u_distance_16_,        /**< Event ROS_Distance_Sensor_u_distance_16. */
    ROS_Distance_Sensor_u_distance_17_,        /**< Event ROS_Distance_Sensor_u_distance_17. */
    ROS_Distance_Sensor_u_distance_18_,        /**< Event ROS_Distance_Sensor_u_distance_18. */
    ROS_Distance_Sensor_u_distance_19_,        /**< Event ROS_Distance_Sensor_u_distance_19. */
    ROS_Distance_Sensor_u_distance_20_,        /**< Event ROS_Distance_Sensor_u_distance_20. */
    ROS_Environment_Scanner_u_environment_,    /**< Event ROS_Environment_Scanner_u_environment. */
    ROS_Node_Robot_Platform_u_robot_x_,        /**< Event ROS_Node_Robot_Platform_u_robot_x. */
    ROS_Node_Robot_Platform_u_robot_y_,        /**< Event ROS_Node_Robot_Platform_u_robot_y. */
    ROS_Node_Robot_Platform_u_robot_rotation_, /**< Event ROS_Node_Robot_Platform_u_robot_rotation. */
    ROS_Node_Robot_Platform_c_move_forward_,   /**< Event ROS_Node_Robot_Platform_c_move_forward. */
    ROS_Node_Robot_Platform_c_rotate_up_,      /**< Event ROS_Node_Robot_Platform_c_rotate_up. */
    ROS_Node_Robot_Platform_c_rotate_right_,   /**< Event ROS_Node_Robot_Platform_c_rotate_right. */
    ROS_Node_Robot_Platform_c_rotate_left_,    /**< Event ROS_Node_Robot_Platform_c_rotate_left. */
    ROS_Node_Robot_Platform_c_rotate_down_,    /**< Event ROS_Node_Robot_Platform_c_rotate_down. */
    ROS_Web_Controller_c_environment_,         /**< Event ROS_Web_Controller_c_environment. */
    ROS_Web_Controller_c_robot_x_,             /**< Event ROS_Web_Controller_c_robot_x. */
    ROS_Web_Controller_c_robot_y_,             /**< Event ROS_Web_Controller_c_robot_y. */
    ROS_Web_Controller_c_robot_rotation_,      /**< Event ROS_Web_Controller_c_robot_rotation. */
};
typedef enum gppEventEnum_ gpp_Event_;

/** Names of all the events. */
extern const char *gpp_event_names[];

/* Constants. */


/* Input variables. */




/* Declaration of internal functions. */


/* State variables (use for output only). */
extern RealType model_time; /**< Current model time. */
extern gppEnum RequirementStateEvtExcls_;     /**< Discrete variable "E RequirementStateEvtExcls". */
extern IntType ROS_Distance_Sensor_distance_; /**< Discrete variable "int[0..20] ROS_Distance_Sensor.distance". */
extern gppEnum ROS_Distance_Sensor_;          /**< Discrete variable "E ROS_Distance_Sensor". */
extern gppEnum ROS_Environment_Scanner_;      /**< Discrete variable "E ROS_Environment_Scanner". */
extern gppEnum ROS_Node_Robot_Platform_;      /**< Discrete variable "E ROS_Node_Robot_Platform". */
extern gppEnum ROS_Web_Controller_;           /**< Discrete variable "E ROS_Web_Controller". */
extern gppEnum sup_;                          /**< Discrete variable "E sup". */

/* Algebraic and derivative functions (use for output only). */






/* Code entry points. */
void gpp_EngineFirstStep(void);
void gpp_EngineTimeStep(double delta);
int gpp_ControllableEvent(void);
BoolType gpp_DistanceEvent(int distance);
void gpp_Init(void);

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
