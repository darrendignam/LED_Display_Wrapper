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
    void ScrollText(String _message);
    void PushChar(char c);
    void FillTextBuffer(String _message);
    void BLINK();
    char displaybuffer[6];
    Adafruit_AlphaNum4 alpha4;

  private:
    // int translateAngleToStepperSteps(float angle);
    // float _leftWheelDiamater;
};
#endif