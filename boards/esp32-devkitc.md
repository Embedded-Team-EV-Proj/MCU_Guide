# ESP32 DevKitC (classic ESP32)

The current front-runner. Cheap, built-in Wi-Fi and Bluetooth, and good motor
control hardware. Many clone boards ("ESP32 DevKit V1", "ESP-WROOM-32 dev
board") use the same chip and work the same way, though pinouts vary.

## Key specs

- Chip: ESP32, dual-core Xtensa LX6, up to 240 MHz, 520 KB SRAM
- Module on the official board: ESP32-WROOM-32E (4 MB flash typical)
- Logic: 3.3 V. Pins are **not** 5 V tolerant
- Wireless: Wi-Fi 802.11 b/g/n, Bluetooth Classic and BLE, ESP-NOW
- PWM: LEDC peripheral, 16 channels, adjustable frequency and resolution
- Motor PWM: MCPWM peripheral (2 units) with dead time and fault inputs
- Encoders: PCNT pulse counter hardware
- Buses: 3 UART, 2 I2C, SPI
- ADC: 12-bit, two units (ADC1 and ADC2)
- USB: micro-USB through a USB-to-UART chip (no native USB)

Verify every number above in the datasheet and note the page.

## Official links

- Board user guide (pinout, header table): https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/esp32-devkitc/user_guide.html
- Board schematic: https://dl.espressif.com/dl/schematics/esp32_devkitc_v4-sch.pdf
- ESP32 chip datasheet: https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf
- ESP32-WROOM-32E module datasheet: https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf
- Technical reference manual: https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf
- Arduino core for ESP32: https://docs.espressif.com/projects/arduino-esp32/en/latest/
- LEDC (PWM) docs: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/ledc.html
- MCPWM docs: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/mcpwm.html
- ESP-NOW docs: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/network/esp_now.html
- Wokwi ESP32 guide: https://docs.wokwi.com/guides/esp32 (Wokwi simulates GPIO, LEDC PWM, PCNT and Wi-Fi, but not MCPWM or Bluetooth. Check the feature table on that page.)

PlatformIO board ID: `esp32dev`

## Gotchas to look up

- GPIO 34 to 39 are input only.
- GPIO 6 to 11 connect to the flash chip. Do not use them.
- Strapping pins (0, 2, 5, 12, 15) affect boot. Avoid putting motor driver
  inputs on them, or the car might twitch on power-up.
- ADC2 cannot be used while Wi-Fi is on. Use ADC1 pins for analog reads.
- Clone boards differ in pin labels and USB chip (CP2102 vs CH340). Check
  drivers on your laptop.

## Fit for our car

- RC side: strong. Wi-Fi, BLE and ESP-NOW built in.
- Drive side: strong. MCPWM and PCNT are made for motors and encoders.
- Two ESP32s per car (RC + drive) plus one in a handheld controller would let
  us use ESP-NOW everywhere.

## Questions for the researcher

1. Which pins are safe for 4 PWM outputs plus 4 direction pins plus 2
   encoders? Draw up a pin plan.
2. How do you set PWM frequency to 20 kHz with the Arduino core?
3. Does the lab have official DevKitC boards or clones? Which USB chip?
4. What range and latency do people report for ESP-NOW?
