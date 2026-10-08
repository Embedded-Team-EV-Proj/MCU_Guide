# Group 4 Embedded Systems: MCU Research

DawgDrive Innovators, UGA Cardboard EV Project, Fall 2026.

This repo is shared by both Group 4 teams. Its first job is to help us pick the
microcontroller(s) for our cars. After that, it becomes the place we keep our
notes, test results and the decision we made.

Nothing here is decided yet. ESP32 with the Arduino framework is the current
leaning, but this research is how we confirm it or change it.

## What we are choosing

Each car can use more than one microcontroller. The setup we are researching:

- **RC MCU**: receives commands from the driver (handheld controller, phone, or
  RC transmitter) and passes them on.
- **Drive MCU**: takes those commands and controls the motors (PWM to a motor
  driver), and later reads sensors like wheel encoders.

One board might be able to do both jobs. Part of the research is deciding
whether two is worth the extra wiring. See
[docs/01-what-the-car-needs.md](docs/01-what-the-car-needs.md).

## Start here

1. Read [GUIDE.md](GUIDE.md). It has your assignment, what to turn in and the
   dates.
2. Work through [docs/](docs/) in order. Each page is short and links to the
   official sources.
3. Fill in the report template for your assigned board:
   [templates/board-report.md](templates/board-report.md).
4. Bring your report to the comparison meeting. We score every board in
   [decision/decision-matrix.md](decision/decision-matrix.md).

## Layout

```
GUIDE.md                 assignments, deliverables, timeline
docs/                    background reading, in order
  01-what-the-car-needs.md
  02-embedded-basics.md
  03-motor-control.md
  04-wireless-control.md
  05-linking-two-mcus.md
  06-power-and-wiring.md
  07-reading-datasheets.md
boards/                  one page per candidate board, with official links
decision/                requirements, scoring matrix, lab inventory, final decision
templates/               board report and bench test log
examples/blink-pwm/      PlatformIO starter project (ESP32, Uno, Pico)
```

## Tools

- C++ (Arduino framework). Learning resource: https://www.w3schools.com/cpp/default.asp
- VS Code with the PlatformIO extension: https://docs.platformio.org/en/latest/
- Wokwi simulator, so you can test code without hardware: https://wokwi.com/
- Git and GitHub for sharing work (see "How to add your work" in GUIDE.md)

## A note on datasheets

We link to datasheets and schematics on the vendor's own site instead of
committing PDFs. Vendor links are always the latest revision and keep the repo
small. If a link breaks, search the part number on the vendor's site and fix
the link in a pull request.
