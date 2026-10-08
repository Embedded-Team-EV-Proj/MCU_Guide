# 05. Linking two MCUs

If each car has an RC MCU and a drive MCU, they need to talk.

## Bus choices

| | Wires | Good for | Watch out for |
|---|---|---|---|
| UART | TX, RX, GND | Simplest. One sender to one receiver. Easy to debug by printing | Cross TX to RX. Match baud rate. Match logic levels |
| I2C | SDA, SCL, GND | Adding sensors on the same bus later | Needs pull-up resistors. One MCU must act as a peripheral, which some Arduino cores handle better than others |
| SPI | 4 wires + GND | Speed | More wires; overkill for a few bytes |

UART is the usual first choice for this job.

## A simple message format

Keep it small and check it. Example, sent 50 times a second:

```
byte 0   0xAA            start marker
byte 1   throttle        int8, -100..100
byte 2   steering        int8, -100..100
byte 3   flags           bit 0 = stop button
byte 4   checksum        XOR of bytes 1..3
```

The drive MCU throws away any packet with a bad checksum and stops the motors
if no good packet arrives for 250 ms. This gives a second layer of failsafe:
even if the RC MCU crashes, the car stops.

## Logic levels

If one board is 5 V (Uno) and the other is 3.3 V (ESP32), a 5 V TX into a
3.3 V RX can damage the 3.3 V board. Use a level shifter or a voltage divider
on that line. Both boards on 3.3 V avoids the problem.

## Notes from the team

(Add findings here with links.)
