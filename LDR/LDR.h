#ifndef LDR_H
#define LDR_H

#include "pico/stdlib.h"

// Define the GPIO pin for the LDR
#define LDR_PIN 28 // GPIO pin connected to the LDR sensor (analog input)

// Function declarations

// Initializes the ADC for the LDR sensor
void setup_ldr_gl5528(void);

// Reads the raw ADC value from the LDR sensor
uint16_t read_ldr_gl5528_raw(void);

// Converts the raw ADC value to a voltage (in millivolts)
float ldr_gl5528_to_voltage(uint16_t raw_value);

// Maps the voltage to an approximate resistance (in ohms)
float ldr_gl5528_to_resistance(float voltage, float fixed_resistor);

// Maps the resistance to a light intensity percentage (0% to 100%)
float ldr_gl5528_to_light_intensity(float resistance);

#endif // LDR_H