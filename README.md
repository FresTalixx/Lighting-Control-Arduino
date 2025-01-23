# LightingControl Library

The **LightingControl** library simplifies the control of LEDs, a servo motor, and a piezo buzzer, using a potentiometer for input. It's designed for Arduino projects where multiple components are managed together.

## Features
- Adjust LED brightness using a potentiometer.
- Control a servo motor's angle.
- Play a tone on a piezo buzzer when the brightness reaches its maximum or minimum.

## How to Use
1. **Install the Library**:
   - Copy the `LightingControl` folder into your Arduino `libraries` directory.
   - Restart the Arduino IDE.

2. **Include the Library**:
   In your Arduino sketch, include the library with:
   ```cpp
   #include <LightingControl.h>