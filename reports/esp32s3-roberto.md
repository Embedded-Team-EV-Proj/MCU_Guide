# Board report: <esp32s3>

Researcher: <Roberto Gomez>
Date: 10/14/2026

Copy this file to `reports/<board>-<yourname>.md`. Every number needs a
source link (datasheet page number is best).

## Summary

Two or three sentences: Thye ESP32-S3 evaluation board using the Xtensa®dual-core 32-bit LX7 microprocessor, with WIFI, and Bluetooth LE 5. I believe that this is highly suitable to our car, because it has bulit-in wireless for the RC side and the dedicated hardware for the motor control and encoders on the driver side. 

## Specs

| Item | Value | Source |
|---|---|---|
| Chip and clock speed |Xtensa® dual-core 32-bit LX7 microprocessor (with single precision FPU), up to 240 MHz |ESP32-S3-WROOM-1 module datasheet P.2 https://documentation.espressif.com/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf|
| Flash / RAM |Up to 16MB of Flash (depends on version) / Up to 16MB of Ram (depends on version)|ESP32-S3-WROOM-1 module datasheet P.3 https://documentation.espressif.com/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf |
| Logic voltage |3.3V |ESP32-S3 datasheet P.13 https://documentation.espressif.com/esp32-s3_datasheet_en.pdf |
| 5 V tolerant pins? |No(Only 3.3V) |ESP32-S3-WROOM-1 module datasheet P. 10-11 https://documentation.espressif.com/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf|
| Board input voltage range |3.3 - 5V (Through 3.3 or 5 pins or USB) | Board user guide https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/user_guide_v1.1.html|
| Usable GPIO count |36 GPIO pins |ESP32-S3-WROOM-1 module datasheet P.2 https://documentation.espressif.com/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf|
| PWM channels and max frequency | 8 channels whith a max frequency of 40MHz|ESP32-S3 datasheet P.4 https://documentation.espressif.com/esp32-s3_datasheet_en.pdf|
| Motor PWM peripheral? |Yes, two Motor Control PWM units |ESP32-S3 datasheet P.4 https://documentation.espressif.com/esp32-s3_datasheet_en.pdf|
| Encoder / pulse counter hardware? |Yes, has four independent pulse counters units |ESP32-S3-WROOM-1 module datasheet P.25 https://documentation.espressif.com/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf|
| UART / I2C / SPI count |3 UART, 2 I2C, and 4 SPI |ESP32-S3-WROOM-1 module datasheet P.18-19 https://documentation.espressif.com/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf |
| ADC pins and resolution | two 12-bit SAR ADCs and supports measurements on 20 channels |ESP32-S3-WROOM-1 module datasheet P.25 https://documentation.espressif.com/ |
| Built-in wireless |2.4 GHz Wi-Fi and Bluetooth® 5 module |ESP32-S3-WROOM-1 module datasheet P.1 https://documentation.espressif.com/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf |
| USB connector type |Micro-USB (UART bridge) and USB Type-C/Micro-USB | Board user guide https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/user_guide_v1.1.html |
| Size (mm) |7*7  |ESP32-S3 datasheet P.77 https://documentation.espressif.com/esp32-s3_datasheet_en.pdf |
| Price and where |$6-$20 depending on version and seller | https://www.espressif.com/en/contact-us/get-samples|
| In Dr. Ye's lab? How many? | | |

## Pins to avoid

List input-only, boot/strapping, flash, USB, or LED pins, from the schematic
and datasheet.
-GPIO 33-37(flash)
-GPIO 26-32(flash)
-GPIO 0,3,45,46(Strapping)
-GPIO 19-20(USB)
-GPIO 39-42(USB)
-GPIO 38 (LED)

## Tooling

- PlatformIO board ID: esp-s3-devkitc-1
- Did the starter project build? yes 
- Wokwi support: Yes
- Arduino libraries we would need (motor, radio, encoder): ESP-IDF API, BLE, WiFi, Motor PWM, Pulse Counter

## Pin plan (draft)

Assign pins for 2 motors (PWM + direction), 2 encoders, UART link, I2C, and a
status LED.

| Function | Pin | Why this pin |
|---|---|---|
| Motor A PWM |GPIO 4 |It a Priorty 2 pin which mean it could be used without restrictions |
| Motor A DIR |GPIO 5 |It also a Priorty 2 pin and below PWM of this motor |
| Motor B PWM |GPIO 6 | It a Priorty 2 pin which mean it could be used without restrictions|
| Motor B DIR |GPIO 7 |It also a Priorty 2 pin and below PWM of this motor |
| Encoder A |GPIO 8 | It a P2 and further up in the line which reduces to risk of lag|
| Encoder B |GPIO 9 | It a P2 and further up in the line which reduces to risk of lag|
| UART TX / RX |GPIO 43 & 44 |They are the default pin for UART0 |
| I2C SDA / SCL |GPIO 10 & 11 |They are P2. |
| Status LED |GPIO 38 |It the LED pin and P2. |

## Recommendation

- RC side: Yes, because it has built-in WiFi and bluetooth which would eliminate any external radio recevier. This would allow the board to receive commands a phone or custom controller.
- Drive side: Yes, because it has two Motor Control PWM units and four independent pulse counters.

## Notes and open questions
What does the S3 give us that the classic ESP32 does not, for this car specifically?
It provides more GPIO pins, native USB, and Bluetooth LE 5. The extra GPIO pins could be beneficial if we need it, ensuring enough pins for the motor driver, encoders, UART, and sensors.

Which variant (N8, N8R2, N8R8) is cheapest and still enough?
I believe that N8 is the cheapest option and sufficient. We are not writing a long programs, which does require the masive amount RAM.

Is the board too long to mount easily? Note the dimensions.
The dimensions of the board is 66 mm to 70 mm * 28mm. We must commucate with the mechanical group to disscus the available space for the board.  
