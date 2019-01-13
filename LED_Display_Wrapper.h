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
    // int translateAngleToStepperSteps(float angle);
    // float _leftWheelDiamater;
    static const uint16_t _outer[];
    static const uint16_t _outer2[];
    static const uint16_t _inner[];
    static const uint16_t _inner_negative[];
    static const uint16_t _inner_outer[];
};
#endif