# Arduino Uno R4 (Minima and WiFi)

Same shape and 5 V logic as the Uno R3, with a 32-bit chip and much more
memory. The WiFi version adds an ESP32-S3 module for wireless.

## Key specs

- Chip: Renesas RA4M1, Arm Cortex-M4, 48 MHz
- Memory: 256 KB flash, 32 KB SRAM, 8 KB EEPROM (data flash)
- Logic: 5 V
- I/O: Uno layout. 14 digital, 6 analog (up to 14-bit ADC), DAC on A0
- USB-C
- VIN accepts a wider range than the R3 (the docs say 6 to 24 V; confirm in
  the datasheet)
- Uno R4 WiFi: adds an ESP32-S3 module for Wi-Fi and BLE, plus a 12x8 LED
  matrix and a Qwiic connector

## Official links

- Uno R4 Minima docs: https://docs.arduino.cc/hardware/uno-r4-minima/
- Minima datasheet: https://docs.arduino.cc/resources/datasheets/ABX00080-datasheet.pdf
- Minima schematic: https://docs.arduino.cc/resources/schematics/ABX00080-schematics.pdf
- Minima user manual: https://docs.arduino.cc/tutorials/uno-r4-minima/cheat-sheet
- Uno R4 WiFi docs: https://docs.arduino.cc/hardware/uno-r4-wifi/
- WiFi schematic: https://docs.arduino.cc/resources/schematics/ABX00087-schematics.pdf
- Renesas RA4M1 chip page: https://www.renesas.com/en/products/ra4m1

PlatformIO board IDs: `uno_r4_minima`, `uno_r4_wifi`

## Gotchas to look up

- On the R4 WiFi, the RA4M1 runs your sketch and the ESP32-S3 handles
  wireless through a library. You do not program the ESP32-S3 directly in
  normal use. Find out how much control that gives (for example, is ESP-NOW
  available? Probably not through the standard library).
- Some older AVR-specific libraries and register tricks from Uno R3 tutorials
  do not work on the R4.
- Check which pins do PWM and at what frequencies.

## Fit for our car

- RC side: WiFi version can do Wi-Fi or BLE. Not ESP-NOW with stock tools.
- Drive side: good. 5 V logic matches many motor drivers and shields.
- Easy step up for anyone who already knows the Uno.

## Questions for the researcher

1. Is the R4 WiFi's wireless good enough for low-latency control, or is it
   built for IoT dashboards?
2. Do common motor shields work on the R4?
3. Can we change PWM frequency from the Arduino API?
