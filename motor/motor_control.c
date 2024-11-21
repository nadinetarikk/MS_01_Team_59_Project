#include "motor_control.h"

// Motor initialization function
void motor_init(void) {
    // Initialize GPIO pins for motor direction control
    gpio_init(FRONT_LEFT_DIR_PIN1);
    gpio_set_dir(FRONT_LEFT_DIR_PIN1, GPIO_OUT);
    gpio_init(FRONT_LEFT_DIR_PIN2);
    gpio_set_dir(FRONT_LEFT_DIR_PIN2, GPIO_OUT);

    gpio_init(BACK_LEFT_DIR_PIN1);
    gpio_set_dir(BACK_LEFT_DIR_PIN1, GPIO_OUT);
    gpio_init(BACK_LEFT_DIR_PIN2);
    gpio_set_dir(BACK_LEFT_DIR_PIN2, GPIO_OUT);

    gpio_init(FRONT_RIGHT_DIR_PIN1);
    gpio_set_dir(FRONT_RIGHT_DIR_PIN1, GPIO_OUT);
    gpio_init(FRONT_RIGHT_DIR_PIN2);
    gpio_set_dir(FRONT_RIGHT_DIR_PIN2, GPIO_OUT);

    gpio_init(BACK_RIGHT_DIR_PIN1);
    gpio_set_dir(BACK_RIGHT_DIR_PIN1, GPIO_OUT);
    gpio_init(BACK_RIGHT_DIR_PIN2);
    gpio_set_dir(BACK_RIGHT_DIR_PIN2, GPIO_OUT);
}

// Function to control the motor direction and speed
void motor_control(uint16_t speed, bool forward, motor_id_t motor) {
    uint8_t dir_pin1, dir_pin2;

    // Select the motor based on motor_id
    switch (motor) {
        case FRONT_LEFT:
            dir_pin1 = FRONT_LEFT_DIR_PIN1;
            dir_pin2 = FRONT_LEFT_DIR_PIN2;
            break;
        case BACK_LEFT:
            dir_pin1 = BACK_LEFT_DIR_PIN1;
            dir_pin2 = BACK_LEFT_DIR_PIN2;
            break;
        case FRONT_RIGHT:
            dir_pin1 = FRONT_RIGHT_DIR_PIN1;
            dir_pin2 = FRONT_RIGHT_DIR_PIN2;
            break;
        case BACK_RIGHT:
            dir_pin1 = BACK_RIGHT_DIR_PIN1;
            dir_pin2 = BACK_RIGHT_DIR_PIN2;
            break;
        default:
            return;  // Invalid motor_id
    }

    // Set motor direction
    if (forward) {
        gpio_put(dir_pin1, 1);  // Set direction forward
        gpio_put(dir_pin2, 0);
    } else {
        gpio_put(dir_pin1, 0);  // Set direction reverse
        gpio_put(dir_pin2, 1);
    }

    // PWM or speed control logic can be implemented here if needed.
    // Since PWM pin is removed, speed control would need to be done
    // via another mechanism if necessary (e.g., via H-bridge or other hardware).
}

// Function to stop the motor
void motor_stop(motor_id_t motor) {
    uint8_t dir_pin1, dir_pin2;

    // Select the motor based on motor_id
    switch (motor) {
        case FRONT_LEFT:
            dir_pin1 = FRONT_LEFT_DIR_PIN1;
            dir_pin2 = FRONT_LEFT_DIR_PIN2;
            break;
        case BACK_LEFT:
            dir_pin1 = BACK_LEFT_DIR_PIN1;
            dir_pin2 = BACK_LEFT_DIR_PIN2;
            break;
        case FRONT_RIGHT:
            dir_pin1 = FRONT_RIGHT_DIR_PIN1;
            dir_pin2 = FRONT_RIGHT_DIR_PIN2;
            break;
        case BACK_RIGHT:
            dir_pin1 = BACK_RIGHT_DIR_PIN1;
            dir_pin2 = BACK_RIGHT_DIR_PIN2;
            break;
        default:
            return;  // Invalid motor_id
    }

    // Set both direction pins to low to stop the motor
    gpio_put(dir_pin1, 0);
    gpio_put(dir_pin2, 0);
}
