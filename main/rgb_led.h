#pragma once

#include "Arduino.h"

/**
 * Interface for controlling an RGB Led.  It is very basic and only allows setting the color.
 * 
 * TODO: Currently the LedController tracks current state of an LED. Should the led 
 * be responsible for tracking its own state and provide a method for reading the 
 * current color value?
 */
class RgbLed{
  public:
  virtual void setColor(byte red, byte green, byte blue){};
};
