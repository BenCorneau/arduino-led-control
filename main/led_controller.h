
#pragma once

#include "rgb_led.h"

/**
 * LedController handles fadding an led between colors 
 */
class LedController {
    private:
        RgbLed& rgbLed;

        byte red;
        byte green;
        byte blue;

    public:
        LedController (RgbLed& rgbLed)
            :rgbLed{rgbLed}{}

        void setColor(const Color& c){
           setColor(c.red, c.green, c.blue);
        }

        void setColor(byte red, byte green, byte blue){
            this->red = red;
            this->green = green;
            this->blue = blue;
            rgbLed.setColor(red, green, blue);
        }

        void transition(const Color& dstColor, int transitionDuration){
          Color srcColor(red,green,blue);
          transition(srcColor, dstColor, transitionDuration);
        }

    private:
        void transition(const Color& srcColor, const Color& dstColor, int transitionDuration){
  
            short redDelta =   dstColor.red   - srcColor.red;
            short greenDelta = dstColor.green - srcColor.green;
            short blueDelta =  dstColor.blue  - srcColor.blue;
        
            const unsigned long startTime = millis();
            unsigned long delta = 0; 
            while(delta < transitionDuration){
        
                delta = lapsedTime(startTime);
                float percentComplete = float(delta) / float(transitionDuration);
                if(percentComplete > 1){percentComplete = 1.0;}
        
                setColor(byte(srcColor.red   + float(redDelta)   * percentComplete),
                         byte(srcColor.green + float(greenDelta) * percentComplete),
                         byte(srcColor.blue  + float(blueDelta)  * percentComplete)); 
            }
            
            setColor(dstColor);
        }       

    private:
        unsigned long lapsedTime(const unsigned long startTime){
            const unsigned long now = millis();
      
            //detect timer roll over
            if(startTime > now){
                return now + (ULONG_MAX - startTime);
            }
          
            return now - startTime;
        }      
};
