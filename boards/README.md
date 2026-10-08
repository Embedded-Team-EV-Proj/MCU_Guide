# Candidate boards

One page per board. Each page has the specs that matter for our car, the
official links, and open questions for the person researching it. Prices are
rough single-unit prices from official or major distributors in 2026 and
change often. Check the lab before assuming we need to buy anything.

| Board | Chip | Logic | Wireless | PWM / motor hardware | Encoder hardware | Approx. price | PlatformIO | Wokwi |
|---|---|---|---|---|---|---|---|---|
| [ESP32 DevKitC](esp32-devkitc.md) | ESP32 (dual-core, 240 MHz) | 3.3 V | Wi-Fi, BT Classic, BLE, ESP-NOW | LEDC (16 ch) + MCPWM | PCNT | $10 (clones less) | yes | yes, except MCPWM and Bluetooth |
| [ESP32-S3 DevKitC-1](esp32-s3-devkitc.md) | ESP32-S3 (dual-core, 240 MHz) | 3.3 V | Wi-Fi, BLE 5, ESP-NOW | LEDC + MCPWM | PCNT | $15 | yes | yes, except MCPWM and Bluetooth |
| [Arduino Uno R3](arduino-uno-r3.md) | ATmega328P (8-bit, 16 MHz) | 5 V | none | 6 PWM pins | interrupts only | $27 (clones less) | yes | yes |
| [Arduino Uno R4](arduino-uno-r4.md) | Renesas RA4M1 (48 MHz) | 5 V | WiFi version: Wi-Fi, BLE | 6 PWM pins on the Uno layout | timers (check) | $20 Minima / $28 WiFi | yes | check |
| [Arduino Nano ESP32](arduino-nano-esp32.md) | ESP32-S3 (u-blox NORA-W106) | 3.3 V | Wi-Fi, BLE, ESP-NOW | LEDC + MCPWM | PCNT | $21 | yes | check |
| [Raspberry Pi Pico family](raspberry-pi-pico.md) | RP2040 / RP2350 | 3.3 V | W versions: Wi-Fi, BT | 16 PWM channels, PIO | PIO | $4 to $7 | partly (see page) | yes (Pico) |
| [STM32 Nucleo-F401RE](stm32-nucleo-f401re.md) | STM32F401RE (84 MHz) | 3.3 V, many pins 5 V tolerant | none | advanced timers | timer encoder mode | $15 | yes | limited |
| [Teensy 4.0](teensy-4.md) | NXP i.MX RT1062 (600 MHz) | 3.3 V | none | many PWM pins | quadrature encoder hardware | $24 | yes | no |

"Check" means we were not sure when writing this. Whoever researches the
board should confirm and update the table.

## How to compare fairly

Use the criteria in [../decision/decision-matrix.md](../decision/decision-matrix.md).
Clock speed is not the deciding factor for us. Built-in wireless, motor PWM,
3.3 V vs 5 V, tool support, and what the lab already has will matter more.
