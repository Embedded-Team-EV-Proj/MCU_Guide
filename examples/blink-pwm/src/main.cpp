// Blink the on-board LED and ramp PWM up and down on one pin.
// Put an LED (with a resistor) or a scope on PWM_PIN to see the ramp.
// Every second it prints the current duty cycle over USB serial.

#include <Arduino.h>

#ifndef PWM_PIN
#define PWM_PIN 9
#endif

// The ESP32-S3 DevKitC-1 LED is an RGB LED on GPIO 48, so the S3 build
// blinks a plain pin instead. Other boards use their built-in LED.
#ifndef LED_PIN
#define LED_PIN LED_BUILTIN
#endif

const unsigned long BLINK_MS = 500;
const unsigned long RAMP_STEP_MS = 10;

unsigned long lastBlink = 0;
unsigned long lastStep = 0;
unsigned long lastPrint = 0;
bool ledOn = false;
int duty = 0;      // 0..255
int stepDir = 1;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  analogWrite(PWM_PIN, 0);
}

void loop() {
  unsigned long now = millis();

  // Non-blocking timing with millis(). The real car code needs this style
  // so the failsafe check is never stuck behind a delay().
  if (now - lastBlink >= BLINK_MS) {
    lastBlink = now;
    ledOn = !ledOn;
    digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
  }

  if (now - lastStep >= RAMP_STEP_MS) {
    lastStep = now;
    duty += stepDir;
    if (duty >= 255 || duty <= 0) {
      stepDir = -stepDir;
    }
    analogWrite(PWM_PIN, duty);
  }

  if (now - lastPrint >= 1000) {
    lastPrint = now;
    Serial.print("duty: ");
    Serial.print(duty * 100 / 255);
    Serial.println("%");
  }
}
