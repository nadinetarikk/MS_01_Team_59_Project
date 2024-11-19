#include "pico/stdlib.h"
#include "infrared_sensor.h"
#include "motor_control.h"
// Define the default pin for the infrared sensor
#ifndef IR_SENSOR_PIN
// Default GPIO pin for infrared sensor
#define IR_SENSOR_PIN 15
#endif

int main()
{
    stdio_init_all();

    // Initialize the infrared sensor on GPIO 15
    infrared_sensor_init(IR_SENSOR_PIN);
    motor_init();


    while (true)
    {

        if (infrared_sensor_is_triggered(IR_SENSOR_PIN))
        {
            // Do something when the sensor is triggered
            printf("Object detected!\n");
        }
        else
        {
            // Do something else when the sensor is not triggered
            printf("No object detected.\n");
        }


        motor_control(255, true);
        sleep_ms(2000);

        motor_control(0, false);
        sleep_ms(1000);

        motor_control(128, false);
        sleep_ms(2000);

        motor_control(0, false);
        sleep_ms(1000);

    }
    
}