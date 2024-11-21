#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Define the GPIO pin for the buzzer (connected directly to Raspberry Pi Pico GPIO)
#define BUZZER_PIN 15  // You can change this to another pin if needed

// Function to initialize the buzzer (sets up PWM for control)
void buzzer_init(void);

// Function to make the buzzer beep at a given frequency and duration
void buzzer_beep(uint16_t frequency, uint16_t duration);

// Function to turn off the buzzer
void buzzer_off(void);

#endif // BUZZER_H
