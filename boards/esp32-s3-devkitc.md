# ESP32-S3 DevKitC-1

The newer ESP32. Same family and tools as the classic ESP32, with more GPIO,
native USB, and BLE 5. It drops Bluetooth Classic.

## Key specs

- Chip: ESP32-S3, dual-core Xtensa LX7, up to 240 MHz, 512 KB SRAM
- Module: ESP32-S3-WROOM-1 (flash and PSRAM size depend on the variant)
- Logic: 3.3 V, not 5 V tolerant
- Wireless: Wi-Fi 802.11 b/g/n, Bluetooth LE 5, ESP-NOW. No Bluetooth Classic
- PWM: LEDC; MCPWM for motors
- Encoders: PCNT
- USB: native USB on the chip plus a USB-to-UART port on the board
- More usable GPIO than the classic ESP32

Verify each in the datasheet.

## Official links

- Board user guide: https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/user_guide_v1.1.html
- Board schematic (v1.1): https://dl.espressif.com/dl/schematics/SCH_ESP32-S3-DevKitC-1_V1.1_20221130.pdf
- ESP32-S3 datasheet: https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf
- ESP32-S3-WROOM-1 module datasheet: https://www.espressif.com/sites/default/files/documentation/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf
- Arduino core for ESP32 (covers S3): https://docs.espressif.com/projects/arduino-esp32/en/latest/

PlatformIO board ID: `esp32-s3-devkitc-1`

## Gotchas to look up

- On boards with octal flash/PSRAM (N8R8 and similar), GPIO 35, 36, 37 are
  used internally. Check the variant printed on the module.
- GPIO 19 and 20 are the native USB pins.
- Strapping pins differ from the classic ESP32. Find them in the datasheet.
- Some phone BLE apps and older tutorials assume Bluetooth Classic, which the
  S3 does not have.

## Fit for our car

- Same strengths as the classic ESP32 for both RC and drive.
- Worth it over the classic ESP32 if we need more pins or native USB. Costs
  a bit more.

## Questions for the researcher

1. What does the S3 give us that the classic ESP32 does not, for this car
   specifically?
2. Which variant (N8, N8R2, N8R8) is cheapest and still enough?
3. Is the board too long to mount easily? Note the dimensions.
