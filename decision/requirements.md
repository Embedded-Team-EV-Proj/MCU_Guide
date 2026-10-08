# Requirements

What the MCUs must do. Update this as other groups make their choices.
"Must" items rule a board out if it fails them. "Want" items go into the
scoring matrix.

## RC MCU

| # | Requirement | Type | Notes |
|---|---|---|---|
| R1 | Receive driver commands wirelessly (or from an RC receiver) | Must | See docs/04 |
| R2 | Detect lost signal within 250 ms and command a stop | Must | |
| R3 | Send commands to the drive MCU at 50 Hz or faster | Must | UART is the default |
| R4 | Status LED for link up / link lost | Want | |
| R5 | Battery voltage reading for telemetry | Want | Needs an ADC pin usable with radio on |

## Drive MCU

| # | Requirement | Type | Notes |
|---|---|---|---|
| D1 | At least 2 PWM outputs plus direction pins for the motor driver | Must | More if 4 motors or a steering servo |
| D2 | PWM frequency adjustable to about 20 kHz | Want | Quieter motors |
| D3 | Stop motors on its own if no valid command for 250 ms | Must | Second failsafe layer |
| D4 | Read 2 wheel encoders | Want | Depends on Sensors group |
| D5 | I2C for sensors | Want | Depends on Sensors group |
| D6 | Logic level compatible with chosen motor driver | Must | Or add level shifting |

## Both

| # | Requirement | Type | Notes |
|---|---|---|---|
| B1 | Programmable in C++ with PlatformIO in VS Code | Must | Group tool choice |
| B2 | Runs from the car's 5 V (or 3.3 V) logic rail | Must | Ask Power/BMS |
| B3 | Can be simulated in Wokwi | Want | Lets people work without hardware |
| B4 | Fits group budget, ideally already in the lab | Must | About $200 per group total |
| B5 | Enough examples and docs for beginners | Want | |
| B6 | Fits and mounts on the cardboard chassis | Must | Ask Mechanical |
