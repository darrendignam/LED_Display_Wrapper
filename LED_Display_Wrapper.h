#ifndef LED_Display_Wrapper_h
#define LED_Display_Wrapper_h

#include "Arduino.h"

#include <string>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

class LED_Display_Wrapper
{
  public:
    LED_Display_Wrapper();
    void ScrollText(String _message);
    void PushChar(char c);
    void BLINK();
    char displaybuffer[5];
    Adafruit_AlphaNum4 alpha4;

  private:
    // int translateAngleToStepperSteps(float angle);
    // float _leftWheelDiamater;
};
#endif