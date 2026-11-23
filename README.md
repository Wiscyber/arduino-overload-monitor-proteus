# Arduino Overload Monitor (Proteus Simulation)

A simulated load-current monitor on Arduino Uno. A potentiometer stands in for a current sensor; readings show on a 16x2 I2C LCD, and an LED turns on when current reaches the overload limit.

## Tools
- Proteus (simulation), Arduino IDE, C++

## Components (simulated)
- Arduino Uno
- Potentiometer (simulates a 0–30 A current sensor on A0)
- 16x2 I2C LCD (address 0x27)
- LED + resistor on pin 13 (represents a relay/overload alarm)
- Virtual terminal (Serial monitor output)

## How it works
- Reads the pot on A0 and scales it to 0–30 A.
- Shows "LOAD: x.x A" on row 1 of the LCD.
- If current ≥ 20 A, row 2 shows "STATUS: OVERLOAD", pin 13 goes HIGH, and an alert is sent to the serial terminal.
- Otherwise it shows "STATUS: NORMAL".
- Updates every 0.5 s.

## Wiring
| Part | Arduino pin |
|------|-------------|
| Potentiometer wiper | A0 |
| LED (via resistor) | D13 |
| LCD SDA / SCL | A4 / A5 |

## Code
See `overload_monitor.ino`

## Result
Demo video:
https://youtu.be/3coMiEUMQ5w?si=adOJ0Cc_qf3UmbGV

## What I learned
- Reading analog input and scaling it to real units
- Driving an I2C LCD
- Threshold-based alarm logic and serial debugging

## Next step
Build it on real hardware with an ACS712 current sensor.
