#include "LightingControl.h"

// Constructor
LightingControl::LightingControl(int ledPins[], int ledCount, int servoPin, int piezoPin, int potPin) {
    _ledPins = ledPins;       // Assign LED pins
    _ledCount = ledCount;     // Assign number of LEDs
    _servoPin = servoPin;     // Assign servo pin
    _piezoPin = piezoPin;     // Assign piezo pin
    _potPin = potPin;         // Assign potentiometer pin
    _currentBrightness = 0;   // Initialize brightness to 0
}

// Initialize all components
void LightingControl::initialize() {
    // Set LED pins as output
    for (int i = 0; i < _ledCount; i++) {
        pinMode(_ledPins[i], OUTPUT);
    }
    // Attach the servo and set piezo pin as output
    _servo.attach(_servoPin);
    pinMode(_piezoPin, OUTPUT);

    Serial.begin(9600); // Optional: For debugging
}

// Update components based on potentiometer input
void LightingControl::update() {
    int potValue = analogRead(_potPin);              // Read potentiometer value
    int brightness = map(potValue, 0, 1023, 0, 255); // Map to brightness (0–255)
    int servoAngle = map(potValue, 0, 1023, 0, 180); // Map to servo angle (0–180)

    // Update LED brightness if it has changed significantly
    if (abs(brightness - _currentBrightness) > 5) {
        changeLedBrightness(brightness);
        // Play tone when brightness hits max or min
        if (brightness == 0 || brightness == 255) {
            tonePiezo();
        }
        _currentBrightness = brightness; // Update current brightness
    }

    // Update servo angle
    rotateServoAngle(servoAngle);

    // Debugging: Print values to Serial Monitor
    Serial.print("Pot: ");
    Serial.print(potValue);
    Serial.print(" | Brightness: ");
    Serial.print(brightness);
    Serial.print(" | Servo Angle: ");
    Serial.println(servoAngle);
}

// Adjust the brightness of LEDs
void LightingControl::changeLedBrightness(int brightness) {
    for (int i = 0; i < _ledCount; i++) {
        analogWrite(_ledPins[i], brightness); // Write brightness to each LED
    }
}

// Rotate servo to a specific angle
void LightingControl::rotateServoAngle(int angle) {
    _servo.write(angle); // Write angle to the servo
}

// Play a tone on the piezo buzzer
void LightingControl::tonePiezo() {
    tone(_piezoPin, 1000, 200); // 1 kHz tone for 200 ms
}
