#include "pico/stdlib.h" 
#include "LED.c"

#define LED1 12 //GREEN
#define LED2 14 //RED
#define LED3 13 //BLUE


int main() {
    pico_led_init(LED1);
    pico_led_init(LED2);
    pico_led_init(LED3);
    pico_set_led(LED3,1);

    while (1) {
    sleep_ms(5000);

    pico_set_led(LED2, 1);
    sleep_ms(1000);
    pico_set_led(LED2, 0);

    pico_set_led(LED1, 1);
    sleep_ms(1000);
    pico_set_led(LED1, 0);

    pico_set_led(LED3, 0);
    sleep_ms(1000);
    pico_set_led(LED3, 1);

    pico_set_led(LED1,1);
    pico_set_led(LED2,1);
    pico_set_led(LED3,0);
    sleep_ms(2000);
    pico_set_led(LED1,0);
    pico_set_led(LED2,0);
    pico_set_led(LED3,1);

    }

    return 0;
}
