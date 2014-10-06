#ifndef SingleMC33926MotorModule_h
#define SingleMC33926MotorModule_h

#include <Arduino.h>

class SingleMC33926MotorModule
{
  public:  
    // CONSTRUCTORS
    SingleMC33926MotorModule(); // Default pin selection.
    SingleMC33926MotorModule(unsigned char DIR_INV, unsigned char PWM, unsigned char FB,
                            unsigned char nSF); // User-defined pin selection. 
    
    // PUBLIC METHODS
    void init(); // Initialize TIMER 1, set the PWM to 20kHZ. 
    void setSpeed(int speed); // Set speed
    unsigned int getCurrentMilliamps(); // Get current reading
    unsigned char getFault(); // Get fault reading.
    
  private:
    unsigned char _DIR_INV;
    static const unsigned char _PWM = 9;
    unsigned char _nSF;
    unsigned char _FB;
};

#endif