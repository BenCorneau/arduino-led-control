/**
 * Arduino program to fade an RGB light strip between multiple colors.
 */
#include <limits.h>

#include "color.h"
#include "pwm_rgb_led.h"
#include "led_controller.h"

int LED_RED   = 3;
int LED_GREEN = 5;
int LED_BLUE  = 6;

PwmRgbLed rgbLed(LED_RED, LED_GREEN, LED_BLUE);
LedController ledController(rgbLed);

//list of colors to cycle between, list is initilized in setup
const Color *colorList[4];

void setup() {
    Serial.begin(9600);//user Serial for debugging
    rgbLed.init(); 
    
    colorList[0] = &Color::RED;
    colorList[1] = &Color::GREEN;
    colorList[2] = &Color::BLUE;
    colorList[3] = &Color::WHITE;
}

int FADE_TIME = 2000;
int REST_TIME = 1000;
int currentColor = 0;
void loop(){
    ledController.transition(*colorList[currentColor], FADE_TIME);
    delay(REST_TIME);

    currentColor = (currentColor +1)%4;
}
