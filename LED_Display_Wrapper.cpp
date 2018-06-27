#include "Arduino.h"
#include "LED_Display_Wrapper.h"
LED_Display_Wrapper::LED_Display_Wrapper()
{
    //hmm setup?
}

// Public Methods implementation
void LED_Display_Wrapper::ScrollText(String _message)
{
    for (std::string::size_type i = 0; i < _message.length(); ++i)
    {
        PushChar(_message[i]);
        delay(200);
    }
}