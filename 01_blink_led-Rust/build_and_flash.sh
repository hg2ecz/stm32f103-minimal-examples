#!/bin/sh

# Required packages:
# ------------------
# Standard Rust install (stable):
#     curl https://sh.rustup.rs -sSf | sh
# ARM target:
#     rustup target add thumbv7m-none-eabi
# Debian/Ubuntu: objcopy & flash tool for USB-TTL:
#     sudo apt install binutils-arm-none-eabi stm32flash

BINFILE=stm32_blink.bin

cargo build --release
arm-none-eabi-objcopy -O binary target/thumbv7m-none-eabi/release/stm32_blink $BINFILE

# flashing ...
if [ " $1" = ' flash' ]; then
    stm32flash -w $BINFILE /dev/ttyUSB0
fi
