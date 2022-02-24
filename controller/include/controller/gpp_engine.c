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
    "initial-step",                             /**< Initial step. */
    "delay-step",                               /**< Delay step. */
    "tau",                                      /**< Tau step. */
    "ROS_Distance_Sensor_u_distance_0",         /**< Event ROS_Distance_Sensor_u_distance_0. */
    "ROS_Distance_Sensor_u_distance_1",         /**< Event ROS_Distance_Sensor_u_distance_1. */
    "ROS_Distance_Sensor_u_distance_2",         /**< Event ROS_Distance_Sensor_u_distance_2. */
    "ROS_Distance_Sensor_u_distance_3",         /**< Event ROS_Distance_Sensor_u_distance_3. */
    "ROS_Distance_Sensor_u_distance_4",         /**< Event ROS_Distance_Sensor_u_distance_4. */
    "ROS_Distance_Sensor_u_distance_5",         /**< Event ROS_Distance_Sensor_u_distance_5. */
    "ROS_Distance_Sensor_u_distance_6",         /**< Event ROS_Distance_Sensor_u_distance_6. */
    "ROS_Distance_Sensor_u_distance_7",         /**< Event ROS_Distance_Sensor_u_distance_7. */
    "ROS_Distance_Sensor_u_distance_8",         /**< Event ROS_Distance_Sensor_u_distance_8. */
    "ROS_Distance_Sensor_u_distance_9",         /**< Event ROS_Distance_Sensor_u_distance_9. */
    "ROS_Distance_Sensor_u_distance_10",        /**< Event ROS_Distance_Sensor_u_distance_10. */
    "ROS_Distance_Sensor_u_distance_11",        /**< Event ROS_Distance_Sensor_u_distance_11. */
    "ROS_Distance_Sensor_u_distance_12",        /**< Event ROS_Distance_Sensor_u_distance_12. */
    "ROS_Distance_Sensor_u_distance_13",        /**< Event ROS_Distance_Sensor_u_distance_13. */
    "ROS_Distance_Sensor_u_distance_14",        /**< Event ROS_Distance_Sensor_u_distance_14. */
    "ROS_Distance_Sensor_u_distance_15",        /**< Event ROS_Distance_Sensor_u_distance_15. */
    "ROS_Distance_Sensor_u_distance_16",        /**< Event ROS_Distance_Sensor_u_distance_16. */
    "ROS_Distance_Sensor_u_distance_17",        /**< Event ROS_Distance_Sensor_u_distance_17. */
    "ROS_Distance_Sensor_u_distance_18",        /**< Event ROS_Distance_Sensor_u_distance_18. */
    "ROS_Distance_Sensor_u_distance_19",        /**< Event ROS_Distance_Sensor_u_distance_19. */
    "ROS_Distance_Sensor_u_distance_20",        /**< Event ROS_Distance_Sensor_u_distance_20. */
    "ROS_Environment_Scanner_u_environment",    /**< Event ROS_Environment_Scanner_u_environment. */
    "ROS_Node_Robot_Platform_u_robot_x",        /**< Event ROS_Node_Robot_Platform_u_robot_x. */
    "ROS_Node_Robot_Platform_u_robot_y",        /**< Event ROS_Node_Robot_Platform_u_robot_y. */
    "ROS_Node_Robot_Platform_u_robot_rotation", /**< Event ROS_Node_Robot_Platform_u_robot_rotation. */
    "ROS_Node_Robot_Platform_c_move_forward",   /**< Event ROS_Node_Robot_Platform_c_move_forward. */
    "ROS_Node_Robot_Platform_c_rotate_up",      /**< Event ROS_Node_Robot_Platform_c_rotate_up. */
    "ROS_Node_Robot_Platform_c_rotate_right",   /**< Event ROS_Node_Robot_Platform_c_rotate_right. */
    "ROS_Node_Robot_Platform_c_rotate_left",    /**< Event ROS_Node_Robot_Platform_c_rotate_left. */
    "ROS_Node_Robot_Platform_c_rotate_down",    /**< Event ROS_Node_Robot_Platform_c_rotate_down. */
    "ROS_Web_Controller_c_environment",         /**< Event ROS_Web_Controller_c_environment. */
    "ROS_Web_Controller_c_robot_x",             /**< Event ROS_Web_Controller_c_robot_x. */
    "ROS_Web_Controller_c_robot_y",             /**< Event ROS_Web_Controller_c_robot_y. */
    "ROS_Web_Controller_c_robot_rotation",      /**< Event ROS_Web_Controller_c_robot_rotation. */
};

/** Enumeration names. */
const char *enum_names[] = {
    "down",
    "left",
    "right",
    "up",
    "X",
};

/* Constants. */


/* Functions. */


/* Input variables. */


/* State variables. */
gppEnum RequirementStateEvtExcls_;     /**< Discrete variable "E RequirementStateEvtExcls". */
IntType ROS_Distance_Sensor_distance_; /**< Discrete variable "int[0..20] ROS_Distance_Sensor.distance". */
gppEnum ROS_Distance_Sensor_;          /**< Discrete variable "E ROS_Distance_Sensor". */
gppEnum ROS_Environment_Scanner_;      /**< Discrete variable "E ROS_Environment_Scanner". */
gppEnum ROS_Node_Robot_Platform_;      /**< Discrete variable "E ROS_Node_Robot_Platform". */
gppEnum ROS_Web_Controller_;           /**< Discrete variable "E ROS_Web_Controller". */
gppEnum sup_;                          /**< Discrete variable "E sup". */

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
 * Execute code for event "ROS_Distance_Sensor.u_distance_0".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent0(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_0_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 0;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_0_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_1".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent1(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_1_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 1;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_1_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_10".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent2(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_10_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 10;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_10_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_11".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent3(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_11_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 11;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_11_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_12".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent4(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_12_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 12;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_12_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_13".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent5(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_13_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 13;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_13_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_14".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent6(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_14_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 14;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_14_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_15".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent7(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_15_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 15;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_15_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_16".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent8(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_16_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 16;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_16_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_17".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent9(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_17_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 17;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_17_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_18".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent10(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_18_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 18;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_18_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_19".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent11(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_19_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 19;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_19_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_2".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent12(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_2_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 2;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_2_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_20".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent13(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_20_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 20;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_20_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_3".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent14(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_3_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 3;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_3_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_4".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent15(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_4_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 4;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_4_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_5".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent16(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_5_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 5;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_5_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_6".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent17(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_6_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 6;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_6_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_7".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent18(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_7_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 7;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_7_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_8".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent19(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_8_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 8;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_8_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Distance_Sensor.u_distance_9".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent20(void) {
    BoolType guard = (ROS_Distance_Sensor_) == (_gpp_X);
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_9_, TRUE);
    #endif

    ROS_Distance_Sensor_distance_ = 9;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Distance_Sensor_u_distance_9_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "ROS_Node_Robot_Platform.c_move_forward".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent21(void) {
    BoolType guard = (((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Distance_Sensor_distance_) > (0))) && (((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_up))) || (((ROS_Node_Robot_Platform_) == (_gpp_left)) || ((ROS_Node_Robot_Platform_) == (_gpp_down)))) && ((sup_) == (_gpp_X)));
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
static BoolType execEvent22(void) {
    BoolType guard = (((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Distance_Sensor_distance_) == (0))) && (((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_up))) || (((ROS_Node_Robot_Platform_) == (_gpp_left)) || ((ROS_Node_Robot_Platform_) == (_gpp_down)))) && ((sup_) == (_gpp_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_down_, TRUE);
    #endif

    if ((ROS_Node_Robot_Platform_) == (_gpp_right)) {
        ROS_Node_Robot_Platform_ = _gpp_down;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_up)) {
        ROS_Node_Robot_Platform_ = _gpp_down;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_left)) {
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
static BoolType execEvent23(void) {
    BoolType guard = (((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Distance_Sensor_distance_) == (0))) && (((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_up))) || (((ROS_Node_Robot_Platform_) == (_gpp_left)) || ((ROS_Node_Robot_Platform_) == (_gpp_down)))) && ((sup_) == (_gpp_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_left_, TRUE);
    #endif

    if ((ROS_Node_Robot_Platform_) == (_gpp_right)) {
        ROS_Node_Robot_Platform_ = _gpp_left;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_up)) {
        ROS_Node_Robot_Platform_ = _gpp_left;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_left)) {
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
static BoolType execEvent24(void) {
    BoolType guard = (((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Distance_Sensor_distance_) == (0))) && (((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_up))) || (((ROS_Node_Robot_Platform_) == (_gpp_left)) || ((ROS_Node_Robot_Platform_) == (_gpp_down)))) && ((sup_) == (_gpp_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_right_, TRUE);
    #endif

    if ((ROS_Node_Robot_Platform_) == (_gpp_right)) {
        ROS_Node_Robot_Platform_ = _gpp_right;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_up)) {
        ROS_Node_Robot_Platform_ = _gpp_right;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_left)) {
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
static BoolType execEvent25(void) {
    BoolType guard = (((RequirementStateEvtExcls_) == (_gpp_X)) && ((ROS_Distance_Sensor_distance_) == (0))) && (((((ROS_Node_Robot_Platform_) == (_gpp_right)) || ((ROS_Node_Robot_Platform_) == (_gpp_up))) || (((ROS_Node_Robot_Platform_) == (_gpp_left)) || ((ROS_Node_Robot_Platform_) == (_gpp_down)))) && ((sup_) == (_gpp_X)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        gpp_InfoEvent(ROS_Node_Robot_Platform_c_rotate_up_, TRUE);
    #endif

    if ((ROS_Node_Robot_Platform_) == (_gpp_right)) {
        ROS_Node_Robot_Platform_ = _gpp_up;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_up)) {
        ROS_Node_Robot_Platform_ = _gpp_up;
    } else if ((ROS_Node_Robot_Platform_) == (_gpp_left)) {
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

        if (execEvent0()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_0". */
        if (execEvent1()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_1". */
        if (execEvent2()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_10". */
        if (execEvent3()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_11". */
        if (execEvent4()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_12". */
        if (execEvent5()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_13". */
        if (execEvent6()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_14". */
        if (execEvent7()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_15". */
        if (execEvent8()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_16". */
        if (execEvent9()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_17". */
        if (execEvent10()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_18". */
        if (execEvent11()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_19". */
        if (execEvent12()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_2". */
        if (execEvent13()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_20". */
        if (execEvent14()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_3". */
        if (execEvent15()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_4". */
        if (execEvent16()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_5". */
        if (execEvent17()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_6". */
        if (execEvent18()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_7". */
        if (execEvent19()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_8". */
        if (execEvent20()) continue;  /* (Try to) perform event "ROS_Distance_Sensor.u_distance_9". */
        if (execEvent21()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_move_forward". */
        if (execEvent22()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_rotate_down". */
        if (execEvent23()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_rotate_left". */
        if (execEvent24()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_rotate_right". */
        if (execEvent25()) continue;  /* (Try to) perform event "ROS_Node_Robot_Platform.c_rotate_up". */
        break; /* No event fired, done with discrete steps. */
    }
}

/** First model call, initializing, and performing discrete events before the first time step. */
void gpp_EngineFirstStep(void) {
    InitConstants();

    model_time = 0.0;

    RequirementStateEvtExcls_ = _gpp_X;
    ROS_Distance_Sensor_distance_ = 0;
    ROS_Distance_Sensor_ = _gpp_X;
    ROS_Environment_Scanner_ = _gpp_X;
    ROS_Node_Robot_Platform_ = _gpp_right;
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

BoolType execute_event(int number) {
    switch (number) {
        case 21:
            return execEvent21();
        case 22:
            return execEvent22();
        case 23:
            return execEvent23();
        case 24:
            return execEvent24();
        case 25:
            return execEvent25();
    }

    return FALSE;
}

BoolType gpp_DistanceEvent(int distance) {
    switch (distance) {
        case 0:
            return execEvent0();
        case 1:
            return execEvent1();
        case 2:
            return execEvent12();
        case 3:
            return execEvent14();
        case 4:
            return execEvent15();
        case 5:
            return execEvent16();
        case 6:
            return execEvent17();
        case 7:
            return execEvent18();
        case 8:
            return execEvent19();
        case 9:
            return execEvent20();
        case 10:
            return execEvent2();
        case 11:
            return execEvent3();
        case 12:
            return execEvent4();
        case 13:
            return execEvent5();
        case 14:
            return execEvent6();
        case 15:
            return execEvent7();
        case 16:
            return execEvent8();
        case 17:
            return execEvent9();
        case 18:
            return execEvent10();
        case 19:
            return execEvent11();
        case 20:
            return execEvent13();
    }

    return FALSE;
}

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

void gpp_Init(void) {
    InitConstants();

    model_time = 0.0;

    RequirementStateEvtExcls_ = _gpp_X;
    ROS_Distance_Sensor_distance_ = 0;
    ROS_Distance_Sensor_ = _gpp_X;
    ROS_Environment_Scanner_ = _gpp_X;
    ROS_Node_Robot_Platform_ = _gpp_right;
    ROS_Web_Controller_ = _gpp_X;
    sup_ = _gpp_X;
}

int gpp_ControllableEvent(void) {
    int n = 5;
    int controllable_events[5] = { 21, 22, 23, 24, 25 };

    // shuffle controllable events
    shuffle(controllable_events, n);

    for (int i = 0; i < n; i++) {
        BoolType result = execute_event(controllable_events[i]);

        if (result) {
            return controllable_events[i];
        }
    }

    return -1;
}