# 04. Wireless control

How does the driver's input get to the car? This choice affects which MCU the
RC side needs.

## Options

### ESP-NOW (ESP32 to ESP32)

Espressif's own protocol. Two ESP32 boards send small packets directly, no
router. Low latency, simple code, decent range. Needs ESP32-family chips on
both ends, so the handheld controller would also be an ESP32 with a joystick.

- Docs: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/network/esp_now.html
- Arduino tutorial: https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/

### Bluetooth Low Energy (phone app)

The car advertises a BLE service and a phone app sends commands. No
handheld hardware to build. Supported by ESP32, ESP32-S3, Nano ESP32, Uno R4
WiFi and Pico W. Range is shorter, and we would need an app (a generic BLE
controller app, or one we write).

### Wi-Fi (web page or UDP)

The car runs a small web server or listens for UDP packets; a phone or laptop
connects. Easy to build a control page. Latency can spike, especially on a
crowded campus network, so test it before relying on it.

### nRF24L01+ radio modules

Cheap 2.4 GHz radio modules on SPI. Work with any MCU, including ones without
built-in wireless (Uno R3, STM32, Teensy). Need a stable 3.3 V supply and
usually a capacitor across power to work reliably.

- Product spec: https://docs.nordicsemi.com/bundle/nRF24L01P_PS_v1.0/resource/nRF24L01P_PS_v1.0.pdf

### Hobby RC transmitter and receiver

The most proven option for driving a vehicle: a hand transmitter with sticks
and a receiver on the car. The receiver outputs servo PWM, PPM, or a serial
protocol such as SBUS or CRSF that the RC MCU reads. It costs more than the
other options, so check the lab first.

## Comparing them

| | Extra hardware | Latency | Works with | Effort |
|---|---|---|---|---|
| ESP-NOW | Second ESP32 + joystick | Low | ESP32 family only | Low |
| BLE | None (phone) | Medium | ESP32, Nano ESP32, R4 WiFi, Pico W | Medium (app side) |
| Wi-Fi | None (phone/laptop) | Variable | Same as BLE | Low to medium |
| nRF24L01+ | 2 radio modules + controller MCU | Low | Any MCU with SPI | Medium |
| RC TX/RX | Transmitter + receiver | Low | Any MCU | Low (code), higher cost |

Fill in the "Latency" column with real numbers once we test. Write how you
measured.

## Failsafe is not optional

Whatever we pick, the car must stop if it stops hearing the controller.
Common method: the controller sends a packet every 20 to 50 ms; if the car
has not received one in 250 ms, it sets throttle to zero.

## Notes from the team

(Add findings here with links.)
