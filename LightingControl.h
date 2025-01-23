#ifndef LightingControl_h
#define LightingControl_h

#include <Servo.h>
#include <Arduino.h>

class LightingControl {
public:
    // Constructor
    LightingControl(int ledPins[], int ledCount, int servoPin, int piezoPin, int potPin);

    // Public methods
    void initialize();       // Initialize components
    void update();           // Update the state (LED brightness, servo, piezo)

private:
    // Private helper methods
    void changeLedBrightness(int brightness);  // Adjust LED brightness
    void rotateServoAngle(int angle);          // Adjust servo angle
    void tonePiezo();                          // Play a tone on the piezo buzzer

    // Member variables
    int* _ledPins;            // Array of LED pins
    int _ledCount;            // Number of LEDs
    int _servoPin;            // Pin controlling the servo
    int _piezoPin;            // Pin connected to the piezo buzzer
    int _potPin;              // Pin connected to the potentiometer
    int _currentBrightness;   // Current brightness value
    Servo _servo;             // Servo object
};

#endif // LightingControl_h
