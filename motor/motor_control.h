#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "pico/stdlib.h"

// Enum for Motor IDs
typedef enum {
    FRONT_LEFT = 1,
    BACK_LEFT,
    FRONT_RIGHT,
    BACK_RIGHT
} motor_id_t;

// Define GPIO Pins for Motors
#define FRONT_LEFT_DIR_PIN1 16
#define FRONT_LEFT_DIR_PIN2 17

#define BACK_LEFT_DIR_PIN1 18
#define BACK_LEFT_DIR_PIN2 19

#define FRONT_RIGHT_DIR_PIN1 14
#define FRONT_RIGHT_DIR_PIN2 15

#define BACK_RIGHT_DIR_PIN1 12
#define BACK_RIGHT_DIR_PIN2 13

// Function Declarations
void motor_init(void);
void motor_control(uint16_t speed, bool forward, motor_id_t motor);
void motor_stop(motor_id_t motor);

#endif // MOTOR_CONTROL_H
