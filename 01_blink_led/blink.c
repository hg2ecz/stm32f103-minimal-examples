/************************************
 * stm32 minimal example - Blink LED
 ************************************/
  
/* memory and peripheral start addresses */
#define FLASH_BASE      0x08000000
#define SRAM_BASE       0x20000000
#define PERIPH_BASE     0x40000000
 
/* work out end of RAM address as initial stack pointer */
#define SRAM_SIZE       20*1024     // STM32F103RB has 20 Kbye of RAM
#define SRAM_END        (SRAM_BASE + SRAM_SIZE)
 
/* LED connected to PIN 8 of GPIOA */
#define LED_PIN         13
#define OUTPUT_MODE     (0x10|0x03) // output mode: push-pull + 50MHz
 
/* RCC peripheral addresses applicable to GPIOC */
#define RCC_BASE        (PERIPH_BASE + 0x21000)
#define RCC_APB2ENR     (*(volatile unsigned long*)(RCC_BASE + 0x18))
 
/* GPIOA peripheral addresses */
#define GPIOC_BASE      (PERIPH_BASE + 0x11000)
#define GPIOC_CRL       (*(volatile unsigned long*)(GPIOC_BASE + 0x00))
#define GPIOC_CRH       (*(volatile unsigned long*)(GPIOC_BASE + 0x04))
#define GPIOC_BSRR      (*(volatile unsigned long*)(GPIOC_BASE + 0x10))
#define GPIOC_BRR       (*(volatile unsigned long*)(GPIOC_BASE + 0x14))

/* vector table */
int main();
unsigned long *vector_table[] __attribute__((section(".vector_table"))) = {
    (unsigned long *)SRAM_END,   // initial stack pointer 
    (unsigned long *)main        // main as Reset_Handler
};


void delay(unsigned long count) {
    while(count--) asm ("NOP");
}

int main() {
    /* enable clock on GPIOC peripheral */
    RCC_APB2ENR = 0x10;

    /* set LED pin output mode */
    #if LED_PIN <= 7
        GPIOA_CRL |= OUTPUT_MODE << ((LED_PIN) << 2); // if pins 0 to 7
    #else
        GPIOC_CRH |= OUTPUT_MODE << ((LED_PIN-8) << 2); // if pins 8 to 15
    #endif

    while(1) {
        GPIOC_BSRR = 1<<LED_PIN;  // set LED pin high
        delay(500000);
        GPIOC_BRR  = 1<<LED_PIN;  // set LED pin low
        delay(500000);
    }
}
