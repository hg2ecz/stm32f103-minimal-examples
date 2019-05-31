#!/bin/sh

# rustup target add thumbv7m-none-eabi
# sudo apt install binutils-arm-none-eabi

BINFILE=stm32_blink.bin

cargo build --release
arm-none-eabi-objcopy -O binary target/thumbv7m-none-eabi/release/stm32_blink $BINFILE

# flashing ...
if [ " $1" = ' flash' ]; then
    stm32flash -w $BINFILE /dev/ttyUSB0
fi
