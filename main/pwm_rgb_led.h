#pragma once

#include "rgb_led.h"

/**
 * An implemetnion of an RGB led controlled by 3 PWM (Pulse Width Modified) pins. 
 */
class PwmRgbLed : public RgbLed  {
    private:
        const byte redPin;
        const byte greenPin;
        const byte bluePin;

    public:
        PwmRgbLed (byte redPin_PWM, byte greenPin_PWM, byte bluePin_PWM)
            :redPin{redPin_PWM}, greenPin{greenPin_PWM}, bluePin{bluePin_PWM} {}

    public:
      void init(){
          pinMode(redPin,   OUTPUT);
          pinMode(greenPin, OUTPUT);
          pinMode(bluePin,  OUTPUT);
      }


    void setColor(byte red, byte green, byte blue){
       //analogWrite will set the PWM duty cylce so a value of 0 is always on and 255 is off
       analogWrite(redPin,   255 - red);
       analogWrite(greenPin, 255 - green);
       analogWrite(bluePin,  255 - blue);  
    }
     
};
