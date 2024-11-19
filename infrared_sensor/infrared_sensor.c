#include "infrared_sensor.h"
// Initialize the infrared sensor
void infrared_sensor_init (uint sensor_pin){
    gpio_init(sensor_pin); // Initialize the GPIO pin for the sensor
    gpio_set_dir(sensor_pin , GPIO_IN); // Set the pin direction as input
}
// Check if the infrared sensor is triggered
bool infrared_sensor_is_triggered (uint sensor_pin ){
    return gpio_get(sensor_pin); // Return the state of the sensor (1 if triggered, 0)
}