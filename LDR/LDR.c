#include "LDR.h"
#include "hardware/adc.h"

// Define the reference voltage for the ADC (in millivolts)
#define ADC_REF_VOLTAGE 3300 // Pico's ADC reference voltage (3.3V)
#define ADC_MAX_VALUE 4095   // Maximum ADC value for 12-bit resolution

void setup_ldr_gl5528(void)
{
    // Initialize the ADC and select the input pin for the LDR
    adc_init();
    adc_gpio_init(LDR_PIN);         // Enable the GPIO pin for analog input
    adc_select_input(LDR_PIN - 26); // Select ADC input channel 0 (LDR_PIN)
}

uint16_t read_ldr_gl5528_raw(void)
{
    // Read and return the raw 12-bit ADC value from the LDR pin
    return adc_read();
}

float ldr_gl5528_to_voltage(uint16_t raw_value)
{
    // Convert the raw ADC value to a voltage in millivolts
    return (raw_value * ADC_REF_VOLTAGE) / (float)ADC_MAX_VALUE;
}

float ldr_gl5528_to_resistance(float voltage, float fixed_resistor)
{
    // Calculate the LDR resistance using the voltage divider formula
    // Voltage = (R_LDR / (R_LDR + R_FIXED)) * V_REF
    if (voltage == 0)
    {
        return 1e6; // Return a high resistance value for zero voltage
    }
    return (fixed_resistor * (ADC_REF_VOLTAGE - voltage)) / voltage;
}

float ldr_gl5528_to_light_intensity(float resistance)
{
    // Map resistance to light intensity percentage (generic formula)
    // Low resistance corresponds to high light intensity
    float intensity = 0;

    if (resistance < 8000)
    {
        intensity = 100.0; // Bright light
    }
    else if (resistance > 20000)
    {
        intensity = 0.0; // Darkness
    }
    else
    {
        // Linear interpolation between 8kΩ and 20kΩ
        intensity = 100.0 - ((resistance - 8000) / (20000 - 8000)) * 100.0;
    }

    return intensity;
}
