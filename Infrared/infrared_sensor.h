#ifndef INFRARED_SENSOR_H
#define INFRARED_SENSOR_H
#include "pico/stdlib.h"
// Function to initialize the infrared sensor
void infrared_sensor_init(uint sensor_pin);
// Function to read the state of the infrared sensor
bool infrared_sensor_is_triggered(uint sensor_pin);
#endif
// INFRARED_SENSOR_H