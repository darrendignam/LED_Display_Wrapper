#include "Arduino.h"
#include "LED_Display_Wrapper.h"

#include <string>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

LED_Display_Wrapper::LED_Display_Wrapper()
{
    // displaybuffer[5] = {' ', ' ', ' ', ' ', ' '};
    displaybuffer[0] = ' ';
    displaybuffer[1] = ' ';
    displaybuffer[2] = ' ';
    displaybuffer[3] = ' ';
    displaybuffer[4] = ' ';

    alpha4 = Adafruit_AlphaNum4();

    //display setup
    alpha4.begin(0x70); // pass in the address
    alpha4.clear();
    alpha4.writeDisplay();
    alpha4.setBrightness(8); /////pull this from persistent memory, and make it a varible
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

void LED_Display_Wrapper::PushChar(char c)
{
    // scroll down display
    displaybuffer[0] = displaybuffer[1];
    displaybuffer[1] = displaybuffer[2];
    displaybuffer[2] = displaybuffer[3];
    displaybuffer[3] = displaybuffer[4];
    displaybuffer[4] = c;

    // set every digit to the buffer
    alpha4.writeDigitAscii(0, displaybuffer[0]);
    alpha4.writeDigitAscii(1, displaybuffer[1]);
    alpha4.writeDigitAscii(2, displaybuffer[2]);
    alpha4.writeDigitAscii(3, displaybuffer[3]);
    alpha4.writeDigitAscii(4, displaybuffer[4]);

    // write it out!
    alpha4.writeDisplay();
}

void LED_Display_Wrapper::BLINK()
{
    //   digitalWrite(LED, HIGH);
    alpha4.writeDigitRaw(7, 0xFFFF);
    for (int L = 0; L < 6; L++)
    {
        alpha4.writeDigitRaw(L, 0xFFFF);
        alpha4.writeDisplay();
    }
    for (int x = 16; x >= 0; x--)
    {
        alpha4.setBrightness(x);
        delay(15);
    }
    //   digitalWrite(LED, LOW);
    //alpha4.writeDigitRaw(7, 0x0000);
    for (int x = 0; x <= 6; x++)
    {
        alpha4.setBrightness(x);
        delay(15);
    }
    //   digitalWrite(LED, HIGH);
    //alpha4.writeDigitRaw(7, 0xFFFF);
    for (int L = 0; L < 6; L++)
    {
        alpha4.writeDigitRaw(L, 0x0000);
        alpha4.writeDisplay();
    }
    alpha4.setBrightness(8); /////pull this from persistent memory, and make it a varible
}