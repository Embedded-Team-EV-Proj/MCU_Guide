# Teensy 4.0

A very fast, small board with excellent Arduino support from its maker, PJRC.
Probably more than we need, but a good benchmark.

## Key specs

- Chip: NXP i.MX RT1062, Arm Cortex-M7, 600 MHz
- Memory: 1 MB RAM, 2 MB flash
- Logic: 3.3 V, **not** 5 V tolerant
- I/O: 40 signals total, 24 easy to reach on a breadboard. Many PWM pins
- Buses: 7 serial, 3 I2C, 3 SPI
- Hardware quadrature encoder inputs
- Wireless: none
- Programmed with Teensyduino (Arduino add-on) or PlatformIO

## Official links

- Board page (specs, pinout card, schematic): https://www.pjrc.com/store/teensy40.html
- Pinout reference: https://www.pjrc.com/teensy/pinout.html
- i.MX RT1060 reference manual (annotated for Teensy): https://www.pjrc.com/teensy/IMXRT1060RM_rev3_annotations.pdf

PlatformIO board ID: `teensy40`

## Gotchas to look up

- Many of the 40 signals are pads on the bottom, hard to use without
  soldering.
- No wireless. Needs an add-on radio.
- Not supported in Wokwi as far as we know.
- About $24, more than an ESP32 that also has wireless.

## Fit for our car

- Drive side: plenty of power and pins.
- RC side: needs an add-on radio.
- Likely overkill. The report should still say clearly why or why not.

## Questions for the researcher

1. Is there anything our car needs that only a Teensy could do?
2. How easy are the encoder and PWM libraries compared with ESP32?
3. Is the 3.3 V-only logic a problem with the motor drivers we are
   considering?
