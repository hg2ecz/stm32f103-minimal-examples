#include "stm32f103_util.h"

#define FLASH_BASE      0x08000000
#define SRAM_BASE       0x20000000
#define PERIPH_BASE     0x40000000

#define SRAM_SIZE       20*1024
#define SRAM_END        (SRAM_BASE + SRAM_SIZE)

int main();
unsigned long *vector_table[] __attribute__((section(".vector_table"))) = {
    (unsigned long *)SRAM_END,   // initial stack pointer 
    (unsigned long *)main        // main as Reset_Handler
};

#define RCC_BASE        (PERIPH_BASE + 0x21000)
#define RCC_APB2ENR     (*(volatile unsigned long*)(RCC_BASE + 0x18))
void init_clocks() {
    /* enable clock on GPIOC peripheral */
    RCC_APB2ENR = 0x10;
}

/* GPIOC peripheral addresses */
#define GPIOC_BASE      (PERIPH_BASE + 0x11000)
#define GPIOC_CRL       (*(volatile unsigned long*)(GPIOC_BASE + 0x00))
#define GPIOC_CRH       (*(volatile unsigned long*)(GPIOC_BASE + 0x04))
#define GPIOC_BSRR      (*(volatile unsigned long*)(GPIOC_BASE + 0x10))
#define GPIOC_BRR       (*(volatile unsigned long*)(GPIOC_BASE + 0x14))
// output mode: push-pull + 50MHz
#define OUTPUT_MODE     (0x10|0x03)

void init_gpioc_out_mode(int pin) {
    if (pin <= 7) {
        GPIOC_CRL |= OUTPUT_MODE << ((pin) << 2);   // if pins 0 to 7
    } else {
        GPIOC_CRH |= OUTPUT_MODE << ((pin-8) << 2); // if pins 8 to 15
    }
}

void gpioc_set_high(int pins) {
    GPIOC_BSRR = pins;
}

void gpioc_set_low(int pins) {
    GPIOC_BRR  = pins;
}
