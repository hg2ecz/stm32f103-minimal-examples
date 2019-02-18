# stm32f103-minimal-examples
Here is a cheap stm32f103 "blue pill" microcontroller board:

![alt stm32_blue_pill](doc/stm32_blue_pill.png)

And here is a cheap USB-TTL converter.

![alt USB-TTL converter](doc/usb-ttl.jpg)

Programming & Run:

* Red wire: +5V
* Black wire: GND
* White wire: PA9
* Green wire: PA10

Jumper "boot0" to 3V3 & push short the RESET button --> you can programming this device (make flash).
Jumpers to GND & push short the RESET button --> run the uploaded code.
