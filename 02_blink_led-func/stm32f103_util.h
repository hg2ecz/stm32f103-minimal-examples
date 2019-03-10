void init_clocks();

void init_gpioc_out_mode(int pin);// 0..15
void gpioc_set_high(int pins);    // binary: 0bxxxx.xxxx.xxxx.xxxx
void gpioc_set_low(int pins);     // binary: 0bxxxx.xxxx.xxxx.xxxx
