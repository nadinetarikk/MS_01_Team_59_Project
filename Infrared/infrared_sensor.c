#include "infrared_sensor.h"

// Initialize the infrared sensor by setting up the GPIO pin as input
void infrared_sensor_init(uint pin)
{
    gpio_init(pin);             // Initialize the GPIO pin
    gpio_set_dir(pin, GPIO_IN); // Set the GPIO pin direction to input
}

// Check if the infrared sensor is triggered (returns true if an object is detected)
bool infrared_sensor_is_triggered(uint pin)
{
    return gpio_get(pin); // Read the GPIO pin value (1 = triggered, 0 = not triggered)
}
