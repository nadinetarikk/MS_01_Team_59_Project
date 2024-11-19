#ifndef LED_H
#define LED_H

#include "pico/stdlib.h"

// Perform initialisation
void pico_led_init(uint led_pin);

// Turn the led on or off
void pico_set_led(uint led_pin, bool led_on);
#endif