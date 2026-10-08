# Board report: <board name>

Researcher: <your name>
Date:

Copy this file to `reports/<board>-<yourname>.md`. Every number needs a
source link (datasheet page number is best).

## Summary

Two or three sentences: what is this board, and would you use it on our car?

## Specs

| Item | Value | Source |
|---|---|---|
| Chip and clock speed | | |
| Flash / RAM | | |
| Logic voltage | | |
| 5 V tolerant pins? | | |
| Board input voltage range | | |
| Usable GPIO count | | |
| PWM channels and max frequency | | |
| Motor PWM peripheral? | | |
| Encoder / pulse counter hardware? | | |
| UART / I2C / SPI count | | |
| ADC pins and resolution | | |
| Built-in wireless | | |
| USB connector type | | |
| Size (mm) | | |
| Price and where | | |
| In Dr. Ye's lab? How many? | | |

## Pins to avoid

List input-only, boot/strapping, flash, USB, or LED pins, from the schematic
and datasheet.

## Tooling

- PlatformIO board ID:
- Did the starter project build? (yes / no / errors)
- Wokwi support:
- Arduino libraries we would need (motor, radio, encoder):

## Pin plan (draft)

Assign pins for 2 motors (PWM + direction), 2 encoders, UART link, I2C, and a
status LED.

| Function | Pin | Why this pin |
|---|---|---|
| Motor A PWM | | |
| Motor A DIR | | |
| Motor B PWM | | |
| Motor B DIR | | |
| Encoder A | | |
| Encoder B | | |
| UART TX / RX | | |
| I2C SDA / SCL | | |
| Status LED | | |

## Recommendation

- RC side: yes / no / maybe, because ...
- Drive side: yes / no / maybe, because ...

## Notes and open questions

