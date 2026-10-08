# Arduino Nano ESP32

An ESP32-S3 in the small Arduino Nano shape. Arduino-style pin names and docs
on top of the ESP32 feature set.

## Key specs

- Module: u-blox NORA-W106-10B (ESP32-S3 inside), Xtensa LX7 up to 240 MHz
- Logic: 3.3 V, not 5 V tolerant
- Wireless: Wi-Fi and Bluetooth LE (ESP32-S3), so ESP-NOW is possible
- I/O: Nano layout. D0 to D13, A0 to A7
- USB-C, native USB
- Small: fits on a breadboard, easy to mount

## Official links

- Board docs: https://docs.arduino.cc/hardware/nano-esp32/
- User manual (pin map to ESP32 GPIO numbers): https://docs.arduino.cc/tutorials/nano-esp32/cheat-sheet/
- Board datasheet: https://docs.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf
- Board schematic: https://docs.arduino.cc/resources/schematics/ABX00083-schematics.pdf
- Full pinout: https://docs.arduino.cc/resources/pinouts/ABX00083-full-pinout.pdf
- ESP32-S3 datasheet: https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf

PlatformIO board ID: `arduino_nano_esp32`

## Gotchas to look up

- Arduino pin numbers (D2, A0) and ESP32 GPIO numbers are different. Example
  code from ESP32 tutorials uses GPIO numbers. The user manual has the map.
- A4 to A7 are on ADC2, which is unavailable while Wi-Fi is running (same
  ESP32 rule).
- Costs about twice a generic ESP32 board.

## Fit for our car

- RC side: strong (same radio as ESP32-S3).
- Drive side: strong. Small size is a plus on a cardboard chassis.
- Good middle ground if the group wants Arduino-quality docs with ESP32
  features.

## Questions for the researcher

1. Is the price difference over a generic ESP32 worth it for us?
2. Can Wokwi simulate this board, or do we simulate as an ESP32-S3?
3. Which pins would you use for 2 motors plus 2 encoders?
