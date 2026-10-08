# Arduino Uno R3

The classic beginner board. Huge number of tutorials and shields, including
motor shields. Limited for wireless and RAM.

## Key specs

- Chip: ATmega328P, 8-bit AVR, 16 MHz
- Memory: 32 KB flash, 2 KB SRAM, 1 KB EEPROM
- Logic: 5 V
- I/O: 14 digital pins (6 with PWM: 3, 5, 6, 9, 10, 11), 6 analog inputs (10-bit)
- Buses: 1 hardware UART (shared with USB), 1 I2C, 1 SPI
- Wireless: none (add a module such as nRF24L01+ or HC-05)
- Input voltage (VIN / barrel jack): see datasheet for recommended range

## Official links

- Board docs: https://docs.arduino.cc/hardware/uno-rev3/
- Board datasheet: https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf
- Board schematic: https://docs.arduino.cc/resources/schematics/A000066-schematics.pdf
- Full pinout: https://content.arduino.cc/assets/A000066-full-pinout.pdf
- ATmega328P chip page and datasheet: https://www.microchip.com/en-us/product/ATmega328P
- Changing PWM frequency with timer registers: https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM

PlatformIO board ID: `uno`

## Gotchas to look up

- Only one hardware UART, and USB uses it. Linking to another MCU means
  SoftwareSerial or sharing pins with the USB connection.
- 2 KB of RAM fills up quickly with radio libraries.
- Default PWM frequency is about 490 Hz (980 Hz on pins 5 and 6). Motors
  whine at that frequency.
- Pins 5 and 6 share a timer with `millis()`. Changing their PWM frequency
  breaks timing.
- 5 V logic: connecting to a 3.3 V board or 3.3 V radio module needs level
  shifting.

## Fit for our car

- RC side: weak on its own. Needs an add-on radio.
- Drive side: workable for simple open-loop motor control, especially with a
  motor shield. Tight if we add encoders and a radio.
- Most likely to already be in the lab.

## Questions for the researcher

1. How many Uno boards and motor shields does the lab have?
2. Could an Uno be the drive MCU with an ESP32 as the RC MCU? What wiring
   would that take (level shifting on UART)?
3. How would you raise PWM frequency on pins 9 and 10, and what does it cost?
