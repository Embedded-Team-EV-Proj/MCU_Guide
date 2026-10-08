# 03. Motor control

The drive MCU never powers a motor directly. A pin can supply a few
milliamps; a motor needs amps. A motor driver sits in between.

## Brushed DC motors: H-bridge drivers

An H-bridge lets a small logic signal switch a big motor current in either
direction. Typical control: one PWM pin for speed plus one or two direction
pins per motor.

Drivers you will see a lot. Check each against the motor voltage and current
the Motors group picks.

| Driver | Motors | Motor voltage | Current per channel | Notes | Link |
|---|---|---|---|---|---|
| L298N | 2 | up to 46 V | 2 A | Old bipolar design, drops about 2 V and gets hot. Very common in kits and labs | https://www.st.com/resource/en/datasheet/l298.pdf |
| TB6612FNG | 2 | up to 13.5 V | 1.2 A continuous, 3.2 A peak | Efficient, small. Good for small motors | https://www.pololu.com/product/713 |
| DRV8833 | 2 | 2.7 to 10.8 V | about 1.5 A RMS | Small, cheap, low voltage | https://www.ti.com/product/DRV8833 |
| DRV8871 | 1 | 6.5 to 45 V | 3.6 A peak | Higher voltage, single motor | https://www.ti.com/product/DRV8871 |
| BTS7960 modules | 1 | up to about 27 V | tens of amps | For large motors | (search the module, use the Infineon BTS7960 datasheet) |

Confirm every number against the datasheet before buying. Board breakouts
(Pololu, Adafruit) often have lower ratings than the bare chip because of heat.

## Brushless motors: ESCs

An ESC (electronic speed controller) drives a brushless motor. It takes a
servo signal: a pulse every 20 ms (50 Hz), 1000 to 2000 microseconds wide.
Any of our boards can generate this with the Servo library or a hardware
timer. Many ESCs need an "arming" sequence at startup. Read the ESC manual.

## What to compare on each MCU

- Number of independent PWM channels. Two motors need at least 2, plus
  steering servo if we use one.
- PWM frequency. Motors are quieter above about 20 kHz. The Uno R3's default
  `analogWrite()` runs at about 490 or 980 Hz, which is audible; changing it
  means touching timer registers. ESP32 lets you set frequency per channel.
- Dedicated motor PWM hardware. ESP32 and ESP32-S3 have an MCPWM peripheral
  with dead time and fault inputs:
  https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/mcpwm.html
  STM32 has advanced timers built for motor control.
- Encoder input. Wheel speed feedback needs fast pulse counting. Look for
  ESP32 PCNT, STM32 timer encoder mode, or RP2040 PIO.

## Safety

- Always share ground between the MCU, motor driver and battery.
- Put a physical kill switch on motor power.
- On startup, set PWM to zero before enabling the driver.
- If commands stop arriving, stop the motors (see doc 05).

## Notes from the team

(Add findings here with links.)
