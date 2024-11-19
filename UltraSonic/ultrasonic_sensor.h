#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "pico/stdlib.h"

// Define the GPIO pins for the Trigger and Echo pins
#define TRIGGER_PIN 15  // GPIO pin for the Trigger
#define ECHO_PIN 14     // GPIO pin for the Echo

// Function declarations

// Initializes the ultrasonic sensor (sets up GPIO pins)
void setup_ultrasonic(void);

// Sends a 10us high pulse to the trigger pin to initiate measurement
void send_trigger_pulse(void);

// Measures the time (in microseconds) for the echo to return
uint32_t measure_echo_time(void);

// Calculates the distance in centimeters based on the echo time
float calculate_distance(uint32_t echo_time);

#endif // ULTRASONIC_H