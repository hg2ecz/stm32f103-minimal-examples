#include "stm32f103_util.h"

void delay(unsigned long count) {
    while(count--) asm ("NOP");
}

#define LED_PIN 13
int main() {
    init_clocks();
    init_gpioc_out_mode(LED_PIN);

    while(1) {
        gpioc_set_high(1<<LED_PIN);
        delay(500000);
        gpioc_set_low(1<<LED_PIN);
        delay(500000);
    }
}
