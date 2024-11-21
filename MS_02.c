#include "pico/stdlib.h"
// #include "infrared_sensor.c"
#include "Led/LED.c"
#include "ultraSonic/ultrasonic_sensor.c"
#include "motor/motor_control.c"
#include "LDR/LDR.c"
#include <stdio.h>

// Define the default pin for the infrared sensor
#ifndef IR_SENSOR_PIN
// Default GPIO pin for infrared sensor
#define IR_SENSOR_PIN 15
#endif

int main()
{
    stdio_init_all();
    setup_ldr_gl5528();

    pico_led_init(IR_SENSOR_PIN);

    float fixed_resistor = 1000.0; // 1kΩ fixed resistor
    while (1)
    {
        // Read and process LDR data
        uint16_t raw_value = read_ldr_gl5528_raw();
        float voltage = ldr_gl5528_to_voltage(raw_value);
        float resistance = ldr_gl5528_to_resistance(voltage, fixed_resistor);
        float intensity = ldr_gl5528_to_light_intensity(resistance);

        printf("Raw: %u, Voltage: %.2f mV, Resistance: %.2f Ω, Light Intensity: %.2f%%\n",
               raw_value, voltage, resistance, intensity);

        // Control LED based on light intensity
        if (intensity < 50.0)
        {
            pico_set_led(IR_SENSOR_PIN, true); // Turn LED on
        }
        else
        {
            pico_set_led(IR_SENSOR_PIN, false); // Turn LED off
        }

        sleep_ms(500); // Delay for stability
    }
    return 0;
}

// int main()
// {
//     stdio_init_all();
//     // setup_ultrasonic();
//     // pico_led_init(20);
//     motor_init();
//     while (true)
//     {

//         // send_trigger_pulse();

//         // uint32_t echo_time = measure_echo_time();
//         // float distance = calculate_distance(echo_time);
//         // printf("Distance: %.2f cm\n", distance);

//         motor_control(100, true);

//         // Do something else when the sensor is not triggered
//         printf("No object detected with ultrasonic.\n");
//         sleep_ms(100); // Wait for a short delay for debouncing
//     }

//     return 0;
// }

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