# 02. Embedded basics

You need these terms to read a datasheet and compare boards. Skim each link,
then come back when a board page mentions something you do not know.

## The terms

**GPIO** (general purpose input/output). A pin you can set high or low, or
read as high or low. On a 3.3 V board, high is about 3.3 V.

**PWM** (pulse width modulation). Switching a pin on and off fast. The
percentage of time it is on (duty cycle) sets the average power. This is how
we control motor speed. Things to compare: how many PWM channels, what
frequency, what resolution (8-bit = 256 steps, 10-bit = 1024).
https://learn.sparkfun.com/tutorials/pulse-width-modulation

**ADC** (analog to digital converter). Reads a voltage as a number. Used for
joysticks, battery voltage, current sense. Compare resolution and how many
pins have it.

**UART / Serial**. Two wires (TX, RX) plus ground. Simple and good for
linking two MCUs or talking to a GPS or Bluetooth module.
https://learn.sparkfun.com/tutorials/serial-communication

**I2C**. Two wires (SDA, SCL) shared by many devices, each with an address.
Common for sensors (IMU, distance sensors, displays).
https://learn.sparkfun.com/tutorials/i2c

**SPI**. Four wires, faster than I2C. Used by radio modules like the
nRF24L01+, SD cards, some displays.
https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi

**Interrupts**. The MCU stops what it is doing to handle a pin change right
away. Needed for counting encoder pulses accurately.

**Timers / counters**. Hardware that counts clock ticks or pulses. Some MCUs
have dedicated encoder-counting hardware (ESP32 "PCNT", STM32 timer encoder
mode), which saves CPU time.

**Logic level**. The voltage that means "high". 5 V boards (Uno R3, Uno R4)
and 3.3 V boards (ESP32, Pico, STM32, Teensy) need care when connected to each
other. https://learn.sparkfun.com/tutorials/logic-levels

**Flash / RAM**. Flash holds your program. RAM holds variables while it runs.
An Uno R3 has 2 KB of RAM, which runs out fast with radio libraries. An ESP32
has hundreds of KB.

**Clock speed**. How fast the CPU runs. Our job is not heavy math, so any
board on our list is fast enough. Peripherals and libraries matter more.

## Arduino framework basics

Every Arduino program has `setup()` (runs once) and `loop()` (runs forever).
The key functions we will use:

- `pinMode()`, `digitalWrite()`, `digitalRead()`
- `analogWrite()` for PWM, `analogRead()` for the ADC
- `Serial.begin()`, `Serial.print()` for debugging over USB
- `millis()` for timing without blocking (important for the failsafe)

Reference page for `analogWrite()` (the other functions are linked from it):
https://docs.arduino.cc/language-reference/en/functions/analog-io/analogWrite/

PWM explained by Arduino: https://www.arduino.cc/en/Tutorial/PWM

## C++ you will actually use

From https://www.w3schools.com/cpp/default.asp, focus on: variables and types,
if/else, loops, functions, arrays, structs, and classes (for later). You do
not need templates or the standard library containers to start.

## Notes from the team

(Add findings here with links.)
