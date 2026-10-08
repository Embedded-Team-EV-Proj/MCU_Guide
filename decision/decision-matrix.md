# Decision matrix

Fill this in at the comparison meeting, once for the RC side and once for the
drive side. Score each board 1 (poor) to 5 (excellent) per criterion, multiply
by the weight, and add up. Boards that fail a "Must" in requirements.md are
crossed out before scoring.

Agree on the weights as a group before anyone scores. The defaults below are
a suggestion.

## Criteria and default weights

| Criterion | RC weight | Drive weight | What a 5 looks like |
|---|---|---|---|
| Built-in wireless that fits our control method | 5 | 1 | Low-latency radio on board, good library |
| Motor PWM and timer hardware | 1 | 5 | Many channels, adjustable frequency, motor PWM peripheral |
| Encoder / pulse counting hardware | 1 | 3 | Dedicated hardware counter |
| Logic level compatibility | 3 | 4 | Works directly with our motor driver and other boards |
| Tooling (PlatformIO + Arduino, Wokwi) | 4 | 4 | Builds first try, simulates in Wokwi |
| Docs and beginner friendliness | 3 | 3 | Official docs plus many good tutorials |
| Cost and availability (lab stock counts as 5) | 4 | 4 | In the lab or under $10 |
| Size and mounting | 2 | 2 | Small, has mounting holes |

## RC side scores

| Board | Wireless | Motor PWM | Encoders | Logic | Tooling | Docs | Cost | Size | Weighted total |
|---|---|---|---|---|---|---|---|---|---|
| ESP32 DevKitC | | | | | | | | | |
| ESP32-S3 DevKitC-1 | | | | | | | | | |
| Arduino Uno R3 | | | | | | | | | |
| Arduino Uno R4 | | | | | | | | | |
| Arduino Nano ESP32 | | | | | | | | | |
| Raspberry Pi Pico (W) | | | | | | | | | |
| STM32 Nucleo-F401RE | | | | | | | | | |
| Teensy 4.0 | | | | | | | | | |

## Drive side scores

| Board | Wireless | Motor PWM | Encoders | Logic | Tooling | Docs | Cost | Size | Weighted total |
|---|---|---|---|---|---|---|---|---|---|
| ESP32 DevKitC | | | | | | | | | |
| ESP32-S3 DevKitC-1 | | | | | | | | | |
| Arduino Uno R3 | | | | | | | | | |
| Arduino Uno R4 | | | | | | | | | |
| Arduino Nano ESP32 | | | | | | | | | |
| Raspberry Pi Pico (W) | | | | | | | | | |
| STM32 Nucleo-F401RE | | | | | | | | | |
| Teensy 4.0 | | | | | | | | | |

## After scoring

The highest score is a starting point, not the answer. Before deciding, ask:

- Does the winner work with the other side's board (logic level, protocol)?
- Can both teams get enough of them, including spares?
- Would picking the same board for both sides make the code and spares
  simpler, even if it scores a little lower on one side?

Write the result in [final-decision.md](final-decision.md).
