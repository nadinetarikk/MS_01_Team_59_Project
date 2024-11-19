#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "pico/stdlib.h"

#endif // MOTOR_CONTROL_H

// GPIO Pins for Motor Control
#define MOTOR_PWM_PIN  8  // GPIO 8 for PWM (speed control)
#define MOTOR_DIR_PIN1 6  // GPIO 6 for motor direction
#define MOTOR_DIR_PIN2 7  // GPIO 7 for motor direction

// Function Declarations
void motor_init(void);
void motor_control(uint16_t speed, bool forward);
void motor_stop(void);

