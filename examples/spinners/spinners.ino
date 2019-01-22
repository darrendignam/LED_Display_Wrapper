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
  Serial.begin(115200);       //Serial speedd for ESP32, try lower 9600 for Arduino UNO
  Serial.println();
  Serial.println("LED_Display_Wrapper library test application.");
}

void loop() {
  LEDdisplay.clear();
  LEDdisplay.writeDisplay();
  
  LEDdisplay.SPINNER_OUTER(6);
  LEDdisplay.SPINNER_OUTER2(6);
  LEDdisplay.SPINNER_INNER(6);
  LEDdisplay.SPINNER_INNER_NEGATIVE(6);
  LEDdisplay.SPINNER_INNER_FADE(6);
  LEDdisplay.SPINNER_INNER_OUTER(6);

  LEDdisplay.clear();
  LEDdisplay.writeDisplay();

  //Do something with the other LEDs
  for(uint8_t i = 0; i<6; i++){
    LEDdisplay.writeDigitRaw(6, 0b0000000000000011); LEDdisplay.writeDisplay();delay(100);
    LEDdisplay.writeDigitRaw(6, 0b0000000000001100); LEDdisplay.writeDisplay();delay(100);
    LEDdisplay.writeDigitRaw(6, 0b0000000000110000); LEDdisplay.writeDisplay();delay(100);
    LEDdisplay.writeDigitRaw(6, 0b0000000011000000); LEDdisplay.writeDisplay();delay(100);
    LEDdisplay.writeDigitRaw(6, 0b0000001100000000); LEDdisplay.writeDisplay();delay(100);
    LEDdisplay.writeDigitRaw(6, 0b0000110000000000); LEDdisplay.writeDisplay();delay(100);
  }

  //this weird count down...
  for(uint8_t i = 65535; i>=0; i=i-100){
    LEDdisplay.writeDigitRaw(0, i);
    LEDdisplay.writeDigitRaw(1, i);
    LEDdisplay.writeDigitRaw(2, i);
    LEDdisplay.writeDigitRaw(3, i);
    LEDdisplay.writeDigitRaw(4, i);
    LEDdisplay.writeDigitRaw(5, i);
    LEDdisplay.writeDigitRaw(6, i); 
    LEDdisplay.writeDisplay();
  }
}