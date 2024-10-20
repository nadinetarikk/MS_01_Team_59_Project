#include "LED.h"

void pico_led_init(uint led_pin)
{
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
}

void pico_set_led(uint led_pin, bool led_on) {
    gpio_put(led_pin, led_on);
}
