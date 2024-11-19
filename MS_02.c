#include "pico/stdlib.h"
// #include "infrared_sensor.c"
#include "Led/LED.c"
#include "ultraSonic/ultrasonic_sensor.c"
#include "motor/motor_control.c"
#include <stdio.h>

// Define the default pin for the infrared sensor
#ifndef IR_SENSOR_PIN
// Default GPIO pin for infrared sensor
#define IR_SENSOR_PIN 15
#endif

int main()
{
    stdio_init_all();
    // setup_ultrasonic();
    // pico_led_init(20);
    motor_init();
    while (true)
    {

        // send_trigger_pulse();

        // uint32_t echo_time = measure_echo_time();
        // float distance = calculate_distance(echo_time);
        // printf("Distance: %.2f cm\n", distance);

        motor_control(100, true);

        // Do something else when the sensor is not triggered
        printf("No object detected with ultrasonic.\n");
        sleep_ms(100); // Wait for a short delay for debouncing
    }

    return 0;
}

// int main()
// {
//     stdio_init_all();

//     // Initialize the infrared sensor on GPIO 15
//     infrared_sensor_init(IR_SENSOR_PIN);
//     {
//         while (true)
//         {
//             if (!infrared_sensor_is_triggered(IR_SENSOR_PIN))
//             {
//                 // Do something when the sensor is triggered
//                 printf("Object detected!\n");
//             }
//             else
//             {
//                 // Do something else when the sensor is not triggered
//                 printf("No object detected.\n");
//             }
//             sleep_ms(100); // Wait for a short delay for debouncing
//         }
//         return 0;
//     }
// }