# 01. What the car needs from us

Group 4 writes the firmware that turns a driver's input into motor movement.
Before comparing boards, it helps to know what jobs the boards have to do.

## The signal path

```
 Driver input            Car
 ------------            ------------------------------------------------
 phone / handheld  --->  RC MCU  --(UART/I2C/SPI)-->  Drive MCU  --PWM-->  motor driver --> motors
 controller / RC          |                             |
 transmitter              |                             +-- encoders, current sense (Sensors group)
                          +-- status LED, kill switch
```

### RC MCU (command side)

- Receives commands wirelessly: throttle, steering, maybe a stop button.
- Checks that commands are fresh. If nothing arrives for a short time (for
  example 250 ms), it tells the drive side to stop. This is the failsafe.
- Sends clean commands to the drive MCU.

### Drive MCU (motor side)

- Generates PWM for the motor driver, and direction signals.
- Ramps speed up and down so the car does not jerk or brown out the battery.
- Later: reads wheel encoders or current sensors and adjusts output.

### The handheld side

Someone has to hold the controls. The options, covered in
[04-wireless-control.md](04-wireless-control.md):

- A phone app over Bluetooth or Wi-Fi (no extra hardware to build).
- A handheld controller we build with its own MCU and a joystick.
- A hobby RC transmitter and receiver (the receiver talks to the RC MCU).

## One MCU or two?

| | One MCU does both | Two MCUs (RC + drive) |
|---|---|---|
| Wiring | Less | More (a link between them, two power feeds) |
| Code | One program, has to juggle radio and motors | Two smaller programs, easier to split work between people |
| Failure | Radio code can stall motor timing if written badly | A stuck radio does not freeze motor control, and the drive MCU can stop on its own |
| Cost | Lower | Higher, though cheap boards are a few dollars |
| Learning | Less to learn | We learn board-to-board communication, which is a useful skill |

Neither answer is wrong. Write down which you would pick and why in your
board report.

## What other groups decide that affects us

Talk to these groups early. Their choices change which boards will work.

- **Motors/Drivetrain**: brushed DC or brushless? How many motors? Brushed
  motors need an H-bridge driver; brushless motors need an ESC that takes a
  servo-style PWM signal.
- **Power/BMS**: battery voltage, and whether there is a 5 V or 3.3 V rail
  for logic. Our boards must run from it.
- **Sensors/Control**: which sensors, and whether they speak I2C, SPI, UART
  or analog. That sets how many pins and buses we need.
- **Mechanical**: how much room there is and where boards mount on cardboard.

## Questions to answer as a group

1. Two MCUs per car, or one?
2. Phone, built controller, or RC transmitter?
3. Brushed or brushless (ask Motors), and which motor driver?
4. What logic voltage does the rest of the car use?

## Notes from the team

(Add findings here with links.)
