
#pragma once

#include "Arduino.h"  //defines byte

/**
 * Color represneted as RGB values[0-255] with a few common predefined colors.
 * Color is immutable.
 */
class Color {
    public:
        const byte red;
        const byte green;
        const byte blue;

    public:
        Color (byte r, byte g, byte b)
            :red{r}, green{g}, blue{b} {}

    //definition of a few common colors
    public:
      static const Color BLACK;
      static const Color RED;
      static const Color GREEN;
      static const Color BLUE;
      static const Color WHITE;
};
