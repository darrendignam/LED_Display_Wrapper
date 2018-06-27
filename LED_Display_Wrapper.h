#ifndef LED_Display_Wrapper_h
#define LED_Display_Wrapper_h

#include "Arduino.h"
class LED_Display_Wrapper
{
  public:
    LED_Display_Wrapper();
    void ScrollText(String _message);
    // void pivotRight(float deg);

  private:
    // int translateAngleToStepperSteps(float angle);
    // float _leftWheelDiamater;
};
#endif