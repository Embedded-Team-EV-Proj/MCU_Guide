# Research Guide

Group lead: Morris Lin. Questions go in the GroupMe or as a GitHub issue on
this repo.

## The goal

By **Monday, Oct 26** we pick:

1. The microcontroller for the **RC side** of each car (receives commands).
2. The microcontroller for the **drive side** of each car (runs the motors).
3. How the driver sends commands (phone, handheld controller we build, or a
   hobby RC transmitter).

Both teams can end up with the same choice or different ones. That is fine,
since we are competing. What matters is that every choice has a reason written
down in [decision/final-decision.md](decision/final-decision.md).

## Your assignment

Everyone does two things: research **one board** in depth and own **one
topic** that you explain to the group at the comparison meeting.

Assignments below are a starting point. Swap with someone if you want, just
update this table in the same pull request.

| Member | Board (boards/) | Topic (docs/) |
|---|---|---|
| Benjamin Ogola | ESP32 DevKitC | Wireless control (04) |
| Roberto David Gomez Garcia | ESP32-S3 DevKitC | Linking two MCUs (05) |
| Paul Nguyen | Arduino Uno R3 | Motor control (03) |
| Shreya Adhikari | Arduino Uno R4 (Minima / WiFi) | Power and wiring (06) |
| Ella Steines | Arduino Nano ESP32 | Wireless control (04) |
| Eli Blondeau | Raspberry Pi Pico family | Motor control (03) |
| Aditya Singh | STM32 Nucleo-F401RE | Reading datasheets (07) |
| Ria Rao | Teensy 4.0 | Power and wiring (06) |

Two people share some topics on purpose. Compare notes before the meeting.

## What to turn in

### 1. Board report (due Mon, Oct 19)

Copy [templates/board-report.md](templates/board-report.md) to
`reports/<board>-<yourname>.md` and fill it in. Use the datasheet and the
board's schematic, not just a blog post. Every number you write down should
have a link to where you found it.

The report should answer, at minimum:

- How many PWM outputs, UARTs, I2C, SPI and ADC pins does it have?
- Is the logic 3.3 V or 5 V? Which pins are input-only, used at boot, or
  otherwise not safe to use?
- Does it have built-in wireless? Which kinds?
- Does it have hardware for reading wheel encoders (pulse counter, timer
  encoder mode)?
- What does it cost, and do we already have it in Dr. Ye's lab?
- Can we program it with PlatformIO and the Arduino framework? Can we
  simulate it in Wokwi?
- Would you put it on the RC side, the drive side, both, or neither? Why?

### 2. Topic notes (due Mon, Oct 19)

Read your docs page and the links in it. Add anything useful you found to
the bottom of that page under "Notes from the team", with links. Be ready to
explain your topic in about 5 minutes at the meeting. No slides needed.

### 3. One small test (due Mon, Oct 26)

Build the starter project in [examples/blink-pwm/](examples/blink-pwm/) for
your board, either on real hardware or in Wokwi. Record what you did in a test
log ([templates/test-log.md](templates/test-log.md)) saved under `tests/`.
If your board is not supported by Wokwi and we do not have one, say so in the
log and try the ESP32 version instead.

## Timeline

Dates are a draft. They move if the whole project schedule moves.

| Week of | What happens |
|---|---|
| Oct 12 | Install VS Code + PlatformIO, accept the GitHub invite, read docs 01 and 02, start your board report |
| Oct 19 | **Reports and topic notes due.** Comparison meeting: each person presents their board and topic |
| Oct 26 | **Decision made.** Score boards in the decision matrix, write final-decision.md, add parts to the materials list. Starter test due |
| Nov 2 | Bench prototypes. Drive side: spin a motor with PWM through a motor driver. RC side: send a command from controller to car |
| Nov 9 | Join the two halves: controller to RC MCU to drive MCU to motor. Add a failsafe that stops the car when signal is lost |
| Nov 16 | Mount on the car with the Power/BMS, Motors and Sensors groups. Fix wiring and noise problems |
| Nov 23 | Thanksgiving week. Light week, only fixes |
| Nov 30 | Testing and tuning on both cars |
| Early Dec | Competition and final write-up |

## How to add your work

1. Accept the invite to the GitHub repo (send Morris your GitHub username if
   you have not yet).
2. Clone it in VS Code: `Ctrl+Shift+P`, "Git: Clone", paste the repo URL.
3. Make a branch named after you, for example `ella-nano-esp32`.
4. Add your files, commit, and push the branch.
5. Open a pull request on GitHub. Someone else in the group reviews it before
   it is merged.

If Git is new to you, GitHub's short guide is enough to get started:
https://docs.github.com/en/get-started/using-github/hello-world

## Rules of thumb

- Cite the source for every spec. Datasheet first, vendor docs second,
  tutorials last.
- Do not buy anything yet. Check the lab inventory first
  ([decision/lab-inventory.md](decision/lab-inventory.md)), then the parts go
  through Morris and the materials list.
- Never connect a 5 V signal to a 3.3 V-only pin. Read
  [docs/06-power-and-wiring.md](docs/06-power-and-wiring.md) before wiring
  anything to a motor or battery.
- If you get stuck for more than an hour, ask in the GroupMe.
