# LED_Display_Wrapper
Wrapper for the Adafruit LED Segment display library, to treat the display as a single multiple character display. 
Adding scrolling text features, loading spinners.

# The wrapper was created for the Tickertap Retro Display

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
