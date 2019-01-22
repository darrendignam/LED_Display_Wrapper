/****************************************************************************************************** 
  TickerTape Retro Display Demo Application
        http://tickertape.cc/


  These displays use I2C to communicate, 2 pins are required to 
  interface.

  This project is a dependent on the AdaFriut LED Backbackpack and GFX libraries:
        https://github.com/adafruit/Adafruit-GFX-Library
        https://github.com/adafruit/Adafruit_LED_Backpack

  The Adafruit Backpack library dosnt support the '.' full stop, and I didnt like some of their font
  choices for the number digits, so I have created a modified version:
        https://github.com/darrendignam/Adafruit_LED_Backpack


  (c) Darren Dignam 2019 
  MIT license, all text above must be included in any redistribution
 *******************************************************************************************************/

#include "LED_Display_Wrapper.h"
LED_Display_Wrapper LEDdisplay = LED_Display_Wrapper();

void setup() {
    Serial.begin(115200);       //Serial speed for ESP32, try lower 9600 for Arduino UNO
    Serial.println();
    Serial.println("LED_Display_Wrapper library test application.");

    LEDdisplay.BLINK();         //Flash All LEDs, and at all brightnesses
    LEDdisplay.ScrollText("TICKERTAPE RETRO DISPLAY...       LED_Display_Wrapper LIBRARY TEST APPLICATION. VERSION 1.0       ");
}

void loop() {
    LEDdisplay.ScrollText("SCROLLING TEXT DEMO.......");
}