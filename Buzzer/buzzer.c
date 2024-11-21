#include "buzzer.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

// Function to initialize the buzzer (sets up PWM for control)
void buzzer_init(void)
{
    // Initialize GPIO pin for PWM
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    // Set the GPIO function to PWM
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);

    // Get the PWM slice corresponding to the GPIO pin
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

    // Adjust the PWM clock divider (to match the desired frequency range more closely)
    pwm_set_clkdiv(slice_num, 4.0f); // New divider value set to 4.0f for smoother operation

    // Set the wrap value for the PWM counter (12-bit resolution)
    pwm_set_wrap(slice_num, 4095); // Ensures fine resolution (12-bit)

    // Enable PWM on the buzzer pin
    pwm_set_enabled(slice_num, true);
}

// Function to make the buzzer beep at a given frequency and duration
void buzzer_beep(uint16_t frequency, uint16_t duration)
{
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

    // Calculate the period for the given frequency, considering the 4.0f clock divider
    uint32_t period = (125000000 / 4.0f) / frequency; // Adjusted to account for the clock divider of 4.0f
    pwm_set_wrap(slice_num, period - 1);              // Set the wrap value based on the desired frequency

    // Set the duty cycle to 50% (2047 out of 4095) for a clean square wave tone
    int half_duty_cycle = 2047;                      // 50% duty cycle of the 12-bit resolution (half of 4095)
    pwm_set_gpio_level(BUZZER_PIN, half_duty_cycle); // Set the duty cycle to 50%

    // Sleep for the specified duration (time in milliseconds)
    sleep_ms(duration); // Sleep for the desired duration in milliseconds

    // After the duration, turn off the buzzer
    buzzer_off();
}

// Function to turn off the buzzer (disable PWM)
void buzzer_off(void)
{
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

    // Set the duty cycle to 0 to stop the buzzer
    pwm_set_gpio_level(BUZZER_PIN, 0); // 0 duty cycle (no signal)
}
