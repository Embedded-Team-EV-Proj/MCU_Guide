# 06. Power and wiring

Most "my code doesn't work" problems on robots are really power or wiring
problems. Coordinate with the Power/BMS group.

## Powering the boards

- Boards take 5 V on a USB or 5V/VIN pin and make their own 3.3 V. Check each
  board's input range on its datasheet.
- Do not power an MCU straight from a motor battery unless the board's input
  range allows that voltage. Use a buck converter (step-down regulator) to
  make 5 V.
- Motors pull large spikes of current when they start or reverse. That can
  drop the battery voltage and reset the MCU. Fixes: separate regulator for
  logic, capacitors near the motor driver, soft-start ramps in code.

## Ground

All grounds connect: battery negative, motor driver ground, every MCU ground.
Without a shared ground, signals between boards have no reference and behave
randomly.

## 3.3 V vs 5 V

- ESP32, ESP32-S3, Nano ESP32, Pico, Teensy 4.0: 3.3 V logic, pins are not
  5 V tolerant. A 5 V signal can damage them.
- STM32F401: 3.3 V logic, but many pins are marked "FT" (five-volt tolerant)
  in the datasheet. Check the pin before relying on it.
- Uno R3, Uno R4: 5 V logic. A 3.3 V output from another board usually reads
  as high, but check the input-high threshold in the datasheet.

Reference: https://learn.sparkfun.com/tutorials/logic-levels

## On a cardboard car

- Cardboard is not a good insulator when it gets damp. Mount boards on
  standoffs or a plastic plate.
- Keep motor wires away from signal wires, and twist each motor's pair of
  wires together to reduce noise.
- Use connectors (JST, screw terminals) for anything you will unplug. Jumper
  wires fall out when the car bumps.
- Label every wire end.

## Notes from the team

(Add findings here with links.)
