#include "SingleMC33926MotorModule.h"

// Constructors ////////////////////////////////////////////////////////////////

SingleMC33926MotorModule::SingleMC33926MotorModule()
{
  //Pin map
  _nD2 = 8;
  _DIR = 7;
  _nSF = 10;
  _FB = A0; 
}

SingleMC33926MotorModule::SingleMC33926MotorModule(unsigned char DIR, unsigned char PWM, unsigned char FB,
                                               unsigned char nD2, unsigned char nSF)
{
  //Pin map
  //PWM cannot be remapped because the library assumes PWM is on timer1
  _nD2 = nD2;
  _DIR = DIR;
  _nSF = nSF;
  _FB = FB; 
}

// Public Methods //////////////////////////////////////////////////////////////
void SingleMC33926MotorModule::init()
{
// Define pinMode for the pins and set the frequency for timer1.

  pinMode(_DIR,OUTPUT);
  pinMode(_PWM,OUTPUT);
  pinMode(_FB,INPUT);
  pinMode(_nD2,OUTPUT);
  digitalWrite(_nD2,HIGH); // default to on
  pinMode(_nSF,INPUT);

  #if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
  // Timer 1 configuration
  // prescaler: clockI/O / 1
  // outputs enabled
  // phase-correct PWM
  // top of 400
  //
  // PWM frequency calculation
  // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
  TCCR1A = 0b10100000;
  TCCR1B = 0b00010001;
  ICR1 = 400;
  #endif
}


// Set speed
void SingleMC33926MotorModule::setSpeed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;
  #if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
  OCR1A = speed;
  #else
  analogWrite(_PWM,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
  #endif
  if (reverse)
    digitalWrite(_DIR,HIGH);
  else
    digitalWrite(_DIR,LOW);
}

// Return current value in milliamps.
unsigned int SingleMC33926MotorModule::getCurrentMilliamps()
{
  // 5V / 1024 ADC counts / 525 mV per A = 9 mA per count
  return analogRead(_FB) * 9;
}

// Return error status
unsigned char SingleMC33926MotorModule::getFault()
{
  return !digitalRead(_nSF);
}