# stm32f103-minimal-examples
Software:
* Linux (e.g. Ubuntu, Debian)
* apt install gcc-arm-none-eabi stm32flash make

Here is a cheap stm32f103 "blue pill" microcontroller board:

![alt stm32_blue_pill](doc/stm32_blue_pill.png)

And here is a cheap USB-TTL converter.

![alt USB-TTL converter](doc/usb-ttl.jpg)

Programming & Run:

* Red wire: +5V
* Black wire: GND
* White wire: PA9
* Green wire: PA10

Jumper "boot0" to 3V3 & push short the RESET button --> you can (re)programming this device (make flash).<br>
Jumpers to GND & push short the RESET button --> run the uploaded code.

If you got the following error message:

   Got NACK from device on command 0x43<br>
   Can't initiate chip mass erase!

The following command will help: <b>make unprotect</b>, because the new blue pill is currently code protected.
