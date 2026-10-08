# STM32 Nucleo-F401RE

A board used in industry and many university courses. Strong timers for motor
control and a built-in debugger. Steeper learning curve and no wireless.

## Key specs

- Chip: STM32F401RE, Arm Cortex-M4 with FPU, 84 MHz
- Memory: 512 KB flash, 96 KB SRAM
- Logic: 3.3 V, with many pins 5 V tolerant (marked FT in the datasheet)
- Timers: advanced-control timer (complementary PWM, dead time), general
  timers with encoder mode
- Buses: 3 USART, 3 I2C, up to 4 SPI
- On-board ST-LINK debugger/programmer (step through code, set breakpoints)
- Arduino Uno-style headers plus ST morpho headers
- Wireless: none

## Official links

- Board page (all documents and CAD files): https://www.st.com/en/evaluation-tools/nucleo-f401re.html
- Board user manual UM1724 (pinout, jumpers, power): https://www.st.com/resource/en/user_manual/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf
- Board schematic (MB1136 C-04): https://www.st.com/resource/en/schematic_pack/mb1136-default-c04_schematic.pdf
- STM32F401RE chip page (datasheet and reference manual): https://www.st.com/en/microcontrollers-microprocessors/stm32f401re.html
- STM32 Arduino core (STM32duino): https://github.com/stm32duino/Arduino_Core_STM32

PlatformIO board ID: `nucleo_f401re`

## Gotchas to look up

- The board revision (sticker on the bottom, for example MB1136 C-02) changes
  some solder bridges and clock settings. The schematic link above is C-04.
- USART2 on D0/D1 goes to the ST-LINK's virtual COM port by default, not the
  headers. UM1724 explains the solder bridges.
- Using the full timer features usually means STM32 HAL code instead of plain
  Arduino functions.

## Fit for our car

- Drive side: excellent hardware for motors and encoders.
- RC side: needs an add-on radio (nRF24L01+ or a hobby RC receiver).
- Good choice if someone in the group already knows STM32 or wants the
  experience. Otherwise the learning curve may cost us time.

## Questions for the researcher

1. How much harder is the STM32 encoder mode to use from Arduino code than
   ESP32's PCNT?
2. Does Wokwi support this board? If not, how would we test without hardware?
3. Does the ECE department or the lab have Nucleo boards already?
