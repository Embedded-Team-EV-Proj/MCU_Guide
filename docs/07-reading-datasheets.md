# 07. Reading datasheets and schematics

## Which document has what

- **Board page / user guide** (Arduino docs, Espressif DevKit guide,
  Raspberry Pi docs): pinout, how to power it, what is on the board. Start
  here.
- **Board schematic**: what each header pin actually connects to, the
  regulator, USB chip, LEDs and buttons. Check this to find pins already used
  by the board.
- **Chip datasheet**: electrical limits (max voltage, current per pin),
  peripheral counts, pin functions.
- **Technical reference manual**: how each peripheral works register by
  register. You only need this for advanced work.

## What to look for, in order

1. Absolute maximum ratings: the voltages that will damage the chip.
2. Recommended operating conditions: supply voltage, input high/low levels.
3. Pin description table: which pins do PWM, ADC, UART, I2C, SPI. Note
   input-only pins and "strapping" or boot pins.
4. Peripheral summary: PWM channels, timers, ADC resolution, UART count.
5. On the board schematic: which chip pins go to the header, and which are
   tied to LEDs, flash memory or USB.

## Guides

- How to read a datasheet: https://learn.sparkfun.com/tutorials/how-to-read-a-datasheet
- How to read a schematic: https://learn.sparkfun.com/tutorials/how-to-read-a-schematic

## Practice

Open the ESP32-DevKitC V4 schematic
(https://dl.espressif.com/dl/schematics/esp32_devkitc_v4-sch.pdf) and answer:

1. What chip converts USB to serial?
2. Which GPIO is connected to the BOOT button?
3. What regulator makes 3.3 V, and what is its input?

Write your answers in your board report's notes section.

## Notes from the team

(Add findings here with links.)
