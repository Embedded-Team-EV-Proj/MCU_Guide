# Raspberry Pi Pico family (Pico, Pico W, Pico 2, Pico 2 W)

Very cheap boards with lots of PWM and a unique feature called PIO
(programmable I/O state machines). The W versions add wireless.

## Key specs

| | Pico | Pico W | Pico 2 | Pico 2 W |
|---|---|---|---|---|
| Chip | RP2040 | RP2040 | RP2350 | RP2350 |
| CPU | 2x Cortex-M0+, 133 MHz | same | 2x Cortex-M33 (or RISC-V), 150 MHz | same |
| SRAM | 264 KB | 264 KB | 520 KB | 520 KB |
| Wireless | none | Wi-Fi, Bluetooth (CYW43439) | none | Wi-Fi, Bluetooth |
| Approx. price | $4 | $6 | $5 | $7 |

All: 3.3 V logic (not 5 V tolerant), 26 usable GPIO, 16 PWM channels,
2 UART, 2 I2C, 2 SPI, 3 ADC inputs, PIO.

Check the numbers in the datasheets.

## Official links

- Pico boards documentation (links to all datasheets): https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html
- Pico datasheet (schematic in appendix): https://pip.raspberrypi.com/documents/RP-008307-DS-pico-datasheet.pdf
- Pico W datasheet: https://pip.raspberrypi.com/documents/RP-008312-DS-pico-w-datasheet.pdf
- Pico 2 datasheet (schematic in appendix): https://pip.raspberrypi.com/documents/RP-008299-DS
- Pico 2 W datasheet: https://pip.raspberrypi.com/documents/RP-008304-DS
- RP2040 chip datasheet: https://pip.raspberrypi.com/documents/RP-008371-DS-rp2040-datasheet.pdf
- RP2350 chip datasheet: https://pip.raspberrypi.com/documents/RP-008373-DS

PlatformIO board ID: `pico` (official platform, Arduino-Mbed core). Pico W,
Pico 2 and the popular Earle Philhower Arduino core need a community
PlatformIO platform. Find out how well that works before choosing this board.

## Gotchas to look up

- Only 3 ADC inputs. Enough for battery voltage and a joystick, not much
  more.
- PlatformIO support is less smooth than for ESP32 or Arduino boards.
- Pico W wireless is a separate chip on SPI, and BLE support in the Arduino
  core is newer than on ESP32. No ESP-NOW.
- Many tutorials use MicroPython. We are using C++, so filter for Arduino or
  C/C++ examples.

## Fit for our car

- Drive side: good. Lots of PWM, and PIO can count encoder pulses.
- RC side: only the W versions, and with less mature wireless libraries.
- Cheapest option if we need several boards.

## Questions for the researcher

1. Which Arduino core would we use, and does it work in PlatformIO without
   trouble? Try building the starter project.
2. How do you count a quadrature encoder with PIO? Find an example library.
3. Does the lab have any Picos?
