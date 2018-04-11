#pragma once

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || \
    defined(__AVR_ATmega328PB__) || defined (__AVR_ATmega32U4__)
  #define DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
#endif

#include <Arduino.h>

class DualMC33926MotorShield
{
  public:
    // CONSTRUCTORS
    // Default pin selection.
    DualMC33926MotorShield();
    // User-defined pin selection.
    DualMC33926MotorShield(unsigned char M1DIR,
                           unsigned char M1PWM,
                           unsigned char M1FB,
                           unsigned char M2DIR,
                           unsigned char M2PWM,
                           unsigned char M2FB,
                           unsigned char nD2,
                           unsigned char nSF);

    // PUBLIC METHODS
    void init(); // Initialize TIMER 1, set the PWM to 20kHZ.
    void setM1Speed(int speed); // Set speed for M1.
    void setM2Speed(int speed); // Set speed for M2.
    void setSpeeds(int m1Speed, int m2Speed); // Set speed for both M1 and M2.
    unsigned int getM1CurrentMilliamps(); // Get current reading for M1.
    unsigned int getM2CurrentMilliamps(); // Get current reading for M2.
    unsigned char getFault(); // Get fault reading.

  private:
    unsigned char _nD2;
    unsigned char _M1DIR;
    unsigned char _M2DIR;
    unsigned char _M1PWM;
    static const unsigned char _M1PWM_TIMER1_PIN = 9;
    unsigned char _M2PWM;
    static const unsigned char _M2PWM_TIMER1_PIN = 10;
    unsigned char _nSF;
    unsigned char _M1FB;
    unsigned char _M2FB;
};
