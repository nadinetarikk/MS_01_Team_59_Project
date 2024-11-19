#include "motor_control.h"
// Function to initialize GPIO and PWM
void motor_init() {
    // Set direction pins as output
    gpio_init(MOTOR_DIR_PIN1);
    gpio_set_dir(MOTOR_DIR_PIN1, GPIO_OUT);
    gpio_init(MOTOR_DIR_PIN2);
    gpio_set_dir(MOTOR_DIR_PIN2, GPIO_OUT);

    // Set PWM function for speed control
    gpio_set_function(MOTOR_PWM_PIN, GPIO_FUNC_PWM);

    // Get PWM slice number for GPIO 8
    uint32_t slice_num = pwm_gpio_to_slice_num(MOTOR_PWM_PIN);

    // Set PWM configuration: wrap value and clock divider
    pwm_set_wrap(slice_num, 255);         // 8-bit resolution
    pwm_set_clkdiv(slice_num, 4.0f);      // Set clock divider

    // Enable PWM output
    pwm_set_enabled(slice_num, true);
}

void motor_control(u_int16_t speed, bool forward){
    //set speed
    if (speed > 255)
    {
        speed = 255;
    }

    //Set Motor Direction
    if(forward){
        gpio_put(MOTOR_DIR_PIN1, 1);
        gpio_put(MOTOR_DIR_PIN2, 0);
    }
    else{
        gpio_put(MOTOR_DIR_PIN1, 0);
        gpio_put(MOTOR_DIR_PIN2, 1);
    }

    // Seting PWM duty cycle to control speed
    pwm_set_gpio_level(MOTOR_PWM_PIN, speed);
    
}

void motor_stop() {
    gpio_put(MOTOR_DIR_PIN1, 0);
    gpio_put(MOTOR_DIR_PIN2, 0);
    pwm_set_gpio_level(MOTOR_PWM_PIN, 0);
}
