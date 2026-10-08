# blink-pwm starter

Blinks the built-in LED and ramps a PWM output up and down. It is the first
thing to get working on any board, because it proves the toolchain, upload and
serial monitor all work.

## Run it

1. Open this folder (`examples/blink-pwm`) in VS Code with PlatformIO
   installed.
2. Pick an environment: `esp32dev`, `esp32-s3`, `uno` or `pico`.
3. Build, upload, then open the serial monitor at 115200 baud. You should see
   `duty: ...%` once a second.

## In Wokwi

Create a new project at https://wokwi.com/ for your board, paste
`src/main.cpp` into the sketch, add an LED with a resistor on the PWM pin, and
run it. The LED should fade in and out.

| Environment | PWM pin |
|---|---|
| esp32dev | GPIO 25 |
| esp32-s3 | GPIO 4 (blink goes to GPIO 5, since the on-board LED is RGB) |
| uno | D9 |
| pico | GP15 |

## Things to try and write in your test log

- Change `RAMP_STEP_MS` and watch the ramp speed change.
- Find how to change the PWM frequency on your board. Set it to 20 kHz.
- Replace the LED with a motor driver input (with Motors group help, and
  never wire a motor directly to a pin).
