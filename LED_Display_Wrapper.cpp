#include "Arduino.h"
#include "LED_Display_Wrapper.h"



//string was messing things up wit an arduino mini
// #include <string>
#include <string.h>

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
    displaybuffer[5] = ' ';

    alpha4 = Adafruit_AlphaNum4();
    brightness = 8;

    //display setup
    alpha4.begin(0x70); // pass in the address
    alpha4.clear();
    alpha4.writeDisplay();
    alpha4.setBrightness(brightness); /////pull this from persistent memory, and make it a varible
}

void LED_Display_Wrapper::setBrightness(uint8_t b) {
    brightness = b;
    alpha4.setBrightness(b);
}
// Public Methods implementation
void LED_Display_Wrapper::writeDigitRaw(uint8_t n, uint16_t bitmask){
    alpha4.writeDigitRaw(n, bitmask);
}

void LED_Display_Wrapper::writeDisplay(){
    alpha4.writeDisplay();
}

void LED_Display_Wrapper::ScrollText(String _message)
{
	//srd::String not working on pro mini
    // for (std::string::size_type i = 0; i < _message.length(); ++i)
    for (int i = 0; i < _message.length(); ++i)
    {
        PushChar(_message[i]);
        alpha4.writeDisplay();
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
    displaybuffer[4] = displaybuffer[5];
    displaybuffer[5] = c;

    // set every digit to the buffer
    alpha4.writeDigitAscii(0, displaybuffer[0]);
    alpha4.writeDigitAscii(1, displaybuffer[1]);
    alpha4.writeDigitAscii(2, displaybuffer[2]);
    alpha4.writeDigitAscii(3, displaybuffer[3]);
    alpha4.writeDigitAscii(4, displaybuffer[4]);
    alpha4.writeDigitAscii(5, displaybuffer[5]);

    // write it out!
    // alpha4.writeDisplay();  //this is causing blinking... remove in future!
}

void LED_Display_Wrapper::FillTextBuffer(String _message)
{
    for (int i = 0; i < _message.length(); ++i)
    {
        PushChar(_message[i]);
    }
    alpha4.writeDisplay();
}

void LED_Display_Wrapper::BLINK()
{
    //   digitalWrite(LED, HIGH);
    alpha4.writeDigitRaw(7, 0xFFFF);
    for (int L = 0; L < 7; L++)
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
    for (int x = 0; x <= 7; x++)
    {
        alpha4.setBrightness(x);
        delay(15);
    }
    //   digitalWrite(LED, HIGH);
    //alpha4.writeDigitRaw(7, 0xFFFF);
    for (int L = 0; L < 7; L++)
    {
        alpha4.writeDigitRaw(L, 0x0000);
        alpha4.writeDisplay();
    }
    alpha4.setBrightness(brightness); //  reset back to brightness before blinking. This can be stored in the main app code as a user parameter
}

void LED_Display_Wrapper::SPINNER_OUTER(uint8_t num){
    for (int x = 0; x < num; x++){
        for (int i = 0; i < 8; i++){
            for (int L = 0; L < 5; L++){
                alpha4.writeDigitRaw(L, _inner[i]);
                alpha4.writeDisplay();
            }
            delay(100);
        }
    }
}


/*
    These are some pre-defined patterns for the LCD to display;
*/

static const uint16_t _outer[] = {
    0b0000000000000001, //1
    0b0000000000000010, //2
    0b0000000000000100, //4
    0b0000000000001000, //8
    0b0000000000010000, //16 
    0b0000000000100000, //32
};

static const uint16_t _outer2[] = {
    0b0000011100000001, //1
    0b0000010010000010, //2
    0b0010000010000100, //4
    0b0011100000001000, //8
    0b0010100000010000, //16
    0b0000000101100000, //32
};

//Spinner_Inner
static const uint16_t _inner[] = {
     0b0000001000000000, //512             10
     0b0000010000000000, //1024            11
     0b0000000010000000, //128             8
     0b0010000000000000, //8192            14
     0b0001000000000000, //4096            13
     0b0000100000000000, //2048            12
     0b0000000001000000, //64              7
     0b0000000100000000, //256             9
 };

//Spinner_Inner_negative
static const uint16_t _inner_negative[] = {
    0b1111110111111111, //502             01
    0b1111101111111111, //0124            00
    0b1111111101111111, //028             8
    0b1101111111111111, //8092            04
    0b1110111111111111, //4196            03
    0b1111011111111111, //2148            02
    0b1111111110111111, //64              7
    0b1111111011111111, //256             9
};

//Spinner_Outer_Inner
static const uint16_t _inner_outer[] = {
    0b0000001000000001,
    0b0000010000000011,
    0b0000000010000110,
    0b0010000000001100,
    0b0001000000001000,
    0b0000100000011000,
    0b0000000001110000,
    0b000000010100001,
};