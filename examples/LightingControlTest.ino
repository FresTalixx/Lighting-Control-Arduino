#include "LightingControl.h"

// Define hardware connections
int ledPins[] = {9, 10, 11}; // LED pins
int servoPin = 6;            // Servo pin
int piezoPin = 8;            // Piezo pin
int potPin = A0;             // Potentiometer pin

// Create an instance of the LightingControl class
LightingControl lightingControl(ledPins, 3, servoPin, piezoPin, potPin);

void setup() {
    lightingControl.initialize(); // Initialize the library
}

void loop() {
    lightingControl.update();     // Continuously update the system
}
