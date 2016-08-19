# Arduino library for the Pololu Dual MC33926 Motor Driver Shield

Version: 2.0.0 <br>
Release date: 2016-08-19 <br>
[![Build Status](https://travis-ci.org/pololu/dual-mc33926-motor-shield.svg?branch=master)](https://travis-ci.org/pololu/dual-mc33926-motor-shield) <br>
[www.pololu.com](https://www.pololu.com/)

## Summary

This is a library for an
[Arduino-compatible controller](https://www.pololu.com/arduino) that
interfaces with the Pololu
[Dual MC33926 Motor Driver Shield](https://www.pololu.com/catalog/product/2503). It
makes it simple to drive two brushed, DC motors.

## Getting started

### Hardware

The
[Dual MC33926 Motor Driver Shield](https://www.pololu.com/catalog/product/2503)
can be purchased on Pololu's website. Before continuing, careful
reading of the product page as well as the
[motor shield user's guide](https://www.pololu.com/docs/0J55) is
recommended.

### Software

If you are using version 1.6.2 or later of the
[Arduino software (IDE)](https://www.arduino.cc/en/Main/Software), you can use
the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then
   "Manage Libraries...".
2. Search for "DualMC33926MotorShield".
3. Click the DualMC33926MotorShield entry in the list.
4. Click "Install".

If this does not work, you can manually install the library:

1. Download the
   [latest release archive from GitHub](https://github.com/pololu/dual-mc33926-motor-shield/releases)
   and decompress it.
2. Rename the folder "dual-mc33926-motor-shield-xxxx" to "DualMC33926MotorShield".
3. Drag the "DualMC33926MotorShield" folder into the "libraries" directory inside your
   Arduino sketchbook directory. You can view your sketchbook location by
   opening the "File" menu and selecting "Preferences" in the Arduino IDE. If
   there is not already a "libraries" folder in that location, you should make
   the folder yourself.
4. After installing the library, restart the Arduino IDE.

## Example program

An example sketch is available that shows how to use the library.  You
can access it from the Arduino IDE by opening the "File" menu,
selecting "Examples", and then selecting "DualMC33926MotorShield".  If
you cannot find these examples, the library was probably installed
incorrectly and you should retry the installation instructions above.


### Demo

The demo ramps motor 1 from stopped to full speed forward, ramps down
to full speed reverse, and back to stopped. Then, it does the same
with the other motor. Both motor's current readings are sent over
serial and can be seen with the serial monitor. If a fault is
detected, a message is sent over serial.

## Documentation

- `DualMC33926MotorShield()` <br> Default constructor, selects the
  default pins as connected by the motor shield.
- `DualMC33926MotorShield(unsigned char M1DIR, unsigned char M1PWM,
  unsigned char M1FB, unsigned char M2DIR, unsigned char M2PWM,
  unsigned char M2FB, unsigned char nD2, unsigned char nSF)` <br>
  Alternate constructor for shield connections remapped by user. M1PWM
  and M2PWM cannot be remapped because the library assumes PWM is on
  timer1.
- `void init()` <br> Initialize pinModes and timer1.
- `void setM1Speed(int speed)` <br> Set speed and direction for
  motor 1. Speed should be between -400 and 400. 400 corresponds to
  motor current flowing from M1A to M1B. -400 corresponds to motor
  current flowing from M1B to M1A.
- `void setM2Speed(int speed)` <br> Set speed and direction for
  motor 2. Speed should be between -400 and 400. 400 corresponds to
  motor current flowing from M2A to M2B. -400 corresponds to motor
  current flowing from M2B to M2A.
- `void setSpeeds(int m1Speed, int m2Speed)` <br> Set speed and
  direction for motor 1 and 2.
- `unsigned int getM1CurrentMilliamps()` <br> Returns current reading
  from motor 1 in milliamps.
- `unsigned int getM2CurrentMilliamps()` <br> Returns current reading
  from motor 2 in milliamps.
- `unsigned char getFault()` <br> Returns 1 if there is a motor driver
  fault, 0 if no fault.

## Version history

* 2.0.0 (2016-08-19): Updated library to work with the Arduino Library Manager.
* 1.0.0 (2012-06-07): Original release.
