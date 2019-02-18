ARCH=arm-none-eabi-
CC=$(ARCH)gcc

CFLAGS = -O2 -Wall -mcpu=cortex-m3 -mthumb
#CFLAGS+= -funroll-loops
LDFLAGS= -s -T minimal.ld

OBJS = blink.o
TARGET = progi

all: $(OBJS)
	$(ARCH)ld $(OBJS) $(LDFLAGS) -o $(TARGET).elf
	$(ARCH)objcopy -S -O binary $(TARGET).elf $(TARGET).bin
	$(ARCH)size $(TARGET).elf

flash:
	stm32flash -w progi.bin /dev/ttyUSB0

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).bin
