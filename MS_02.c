#include "pico/stdlib.h"
// #include "infrared_sensor.c"
#include "Led/LED.c"
#include "ultraSonic/ultrasonic_sensor.c"
#include "motor/motor_control.c"
#include "LDR/LDR.c"
#include "Buzzer/buzzer.c"
#include <stdio.h>

// Define the default pin for the infrared sensor
#ifndef IR_SENSOR_PIN
// Default GPIO pin for infrared sensor
#define IR_SENSOR_PIN 15
#endif

int main()
{
    stdio_init_all();

    // Motor control test
    motor_init();

    // while (true)
    // {
    //     // Move Front Left motor forward
    //     motor_control(100, true, FRONT_LEFT); // Move Front Left motor forward at speed 100
    //     printf("Front Left motor moving forward.\n");
    //     sleep_ms(5000); // Wait for 1 second

    //     // Move Front Left motor backward
    //     motor_control(100, false, FRONT_LEFT); // Move Front Left motor backward at speed 100
    //     printf("Front Left motor moving backward.\n");
    //     sleep_ms(5000); // Wait for 1 second

    //     // Move Back Left motor forward
    //     motor_control(100, true, BACK_LEFT); // Move Back Left motor forward at speed 100
    //     printf("Back Left motor moving forward.\n");
    //     sleep_ms(5000); // Wait for 1 second

    //     // Move Back Left motor backward
    //     motor_control(100, false, BACK_LEFT); // Move Back Left motor backward at speed 100
    //     printf("Back Left motor moving backward.\n");
    //     sleep_ms(5000); // Wait for 1 second

    //     // Move Front Right motor forward
    //     motor_control(100, true, FRONT_RIGHT); // Move Front Right motor forward at speed 100
    //     printf("Front Right motor moving forward.\n");
    //     sleep_ms(5000); // Wait for 1 second

    //     // Move Front Right motor backward
    //     motor_control(100, false, FRONT_RIGHT); // Move Front Right motor backward at speed 100
    //     printf("Front Right motor moving backward.\n");
    //     sleep_ms(5000); // Wait for 1 second

    //     // Move Back Right motor forward
    //     motor_control(100, true, BACK_RIGHT); // Move Back Right motor forward at speed 100
    //     printf("Back Right motor moving forward.\n");
    //     sleep_ms(5000); // Wait for 1 second

    //     // Move Back Right motor backward
    //     motor_control(100, false, BACK_RIGHT); // Move Back Right motor backward at speed 100
    //     printf("Back Right motor moving backward.\n");
    //     sleep_ms(5000); // Wait for 1 second

    //     // Stop all motors
    //     motor_stop(FRONT_LEFT);  // Stop Front Left motor
    //     motor_stop(BACK_LEFT);   // Stop Back Left motor
    //     motor_stop(FRONT_RIGHT); // Stop Front Right motor
    //     motor_stop(BACK_RIGHT);  // Stop Back Right motor
    //     printf("All motors stopped.\n");

    //     sleep_ms(2000); // Wait for 2 seconds before repeating
    // }

    while (true)
    {
        motor_control(100, true, FRONT_LEFT);
        motor_control(100, true, BACK_LEFT);
        motor_control(100, true, FRONT_RIGHT);
        motor_control(100, true, BACK_RIGHT);
    }

    return 0;
}

// int main()
// {
//     stdio_init_all();
//     buzzer_init();

//     printf("Starting the buzzer...\n");

//     while (true)
//     {
//         printf("Beeping at different frequencies between 1 kHz and 15 kHz...\n");

//         // Beep at 1 kHz (1000 Hz)
//         printf("Playing at 1 kHz\n");
//         buzzer_beep(1000, 2000); // 1 kHz for 2 seconds
//         sleep_ms(1000);

//         // // Beep at 2 kHz (2000 Hz)
//         // printf("Playing at 2 kHz\n");
//         // buzzer_beep(2000, 2000); // 2 kHz for 2 seconds
//         // sleep_ms(1000);

//         // // Beep at 3 kHz (3000 Hz)
//         // printf("Playing at 3 kHz\n");
//         // buzzer_beep(3000, 2000); // 3 kHz for 2 seconds
//         // sleep_ms(1000);

//         // // Beep at 4 kHz (4000 Hz)
//         // printf("Playing at 4 kHz\n");
//         // buzzer_beep(4000, 2000); // 4 kHz for 2 seconds
//         // sleep_ms(1000);

//         // Beep at 5 kHz (5000 Hz)
//         printf("Playing at 5 kHz\n");
//         buzzer_beep(5000, 2000); // 5 kHz for 2 seconds
//         sleep_ms(1000);
//     }

//     return 0;
// }

// int main()
// {
//     stdio_init_all();
//     setup_ldr_gl5528();

//     pico_led_init(IR_SENSOR_PIN);

//     float fixed_resistor = 1000.0; // 1kΩ fixed resistor
//     while (1)
//     {
//         // Read and process LDR data
//         uint16_t raw_value = read_ldr_gl5528_raw();
//         float voltage = ldr_gl5528_to_voltage(raw_value);
//         float resistance = ldr_gl5528_to_resistance(voltage, fixed_resistor);
//         float intensity = ldr_gl5528_to_light_intensity(resistance);

//         printf("Raw: %u, Voltage: %.2f mV, Resistance: %.2f Ω, Light Intensity: %.2f%%\n",
//                raw_value, voltage, resistance, intensity);

//         // Control LED based on light intensity
//         if (intensity < 50.0)
//         {
//             pico_set_led(IR_SENSOR_PIN, true); // Turn LED on
//         }
//         else
//         {
//             pico_set_led(IR_SENSOR_PIN, false); // Turn LED off
//         }

//         sleep_ms(500); // Delay for stability
//     }
//     return 0;
// }

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