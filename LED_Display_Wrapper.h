/****************************************************************************************************** 
  This library is for controlling multiple 14-Segment displays.

  Designed specifically to work with the Tickertape Retro Display
        http://tickertape.cc/


  These displays use I2C to communicate, 2 pins are required to 
  interface.

  This library is a wrapper of the AdaFriut LED Backbackpack and GFX libraries:
        https://github.com/adafruit/Adafruit-GFX-Library
        https://github.com/adafruit/Adafruit_LED_Backpack

  The Adafruit Backpack library dosnt support the '.' full stop, and I didnt like some of their font
  choices for the number digits, so I have created a modified version:
        https://github.com/darrendignam/Adafruit_LED_Backpack


  (c) Darren Dignam 2019 
  MIT license, all text above must be included in any redistribution
 *******************************************************************************************************/

#ifndef LED_Display_Wrapper_h
#define LED_Display_Wrapper_h

#include "Arduino.h"

//string was causing compile errors on non ESP boards...
// #include <string>
#include <string.h>


#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

class LED_Display_Wrapper
{
  public:
    LED_Display_Wrapper();
    void setBrightness(uint8_t b);
    void writeDigitRaw(uint8_t n, uint16_t bitmask);
    void writeDisplay();
    void ScrollText(String _message);
    void PushChar(char c);
    void FillTextBuffer(String _message);

    void BLINK();
    void SPINNER_OUTER(uint8_t num);
    
    char displaybuffer[6];
    Adafruit_AlphaNum4 alpha4;
    uint8_t brightness;

  private:
    static const uint16_t _outer[];
    static const uint16_t _outer2[];
    static const uint16_t _inner[];
    static const uint16_t _inner_negative[];
    static const uint16_t _inner_outer[];
};
#endif