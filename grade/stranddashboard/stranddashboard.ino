
#include "SPI.h"
#include "Adafruit_WS2801.h"

/*****************************************************************************
Example sketch for driving Adafruit WS2801 pixels!


  Designed specifically to work with the Adafruit RGB Pixels!
  12mm Bullet shape ----> https://www.adafruit.com/products/322
  12mm Flat shape   ----> https://www.adafruit.com/products/738
  36mm Square shape ----> https://www.adafruit.com/products/683

  These pixels use SPI to transmit the color data, and have built in
  high speed PWM drivers for 24 bit color per pixel
  2 pins are required to interface

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

*****************************************************************************/

// Choose which 2 pins you will use for output.
// Can be any valid output pins.
// The colors of the wires may be totally different so
// BE SURE TO CHECK YOUR PIXELS TO SEE WHICH WIRES TO USE!
uint8_t dataPin  = 2;    // Yellow wire on Adafruit Pixels
uint8_t clockPin = 3;    // Green wire on Adafruit Pixels

// Don't forget to connect the ground wire to Arduino ground,
// and the +5V wire to a +5V supply

// Set the first variable to the NUMBER of pixels. 25 = 25 pixels in a row
Adafruit_WS2801 strip = Adafruit_WS2801(32, dataPin, clockPin);

// Optional: leave off pin numbers to use hardware SPI
// (pinout is then specific to each board and can't be changed)
//Adafruit_WS2801 strip = Adafruit_WS2801(25);

// For 36mm LED pixels: these pixels internally represent color in a
// different format.  Either of the above constructors can accept an
// optional extra parameter: WS2801_RGB is 'conventional' RGB order
// WS2801_GRB is the GRB order required by the 36mm pixels.  Other
// than this parameter, your code does not need to do anything different;
// the library will handle the format change.  Examples:
//Adafruit_WS2801 strip = Adafruit_WS2801(25, dataPin, clockPin, WS2801_GRB);
//Adafruit_WS2801 strip = Adafruit_WS2801(25, WS2801_GRB);
uint32_t green = Color(0, 255, 0);
uint32_t orange = Color(0x00, 0x19, 0xC1);
uint32_t black = 0;
uint32_t white = Color(255,255,255);
uint32_t red = Color(0,0,255);
uint32_t yellow = Color(0,255,255);

int STATE_PUMPKIN_RUN  = 1;
int STATE_PUMPKIN_STOP = 2;
int STATE_FLASHING = 3;
int STATE_WHITE = 4;
int STATE_GRADE = 5;
int state = STATE_GRADE;


void showGrades() {
       loadColor(black);
      //strip.show();
      
      strip.setPixelColor(0, yellow);
      strip.setPixelColor(1, yellow);
      strip.setPixelColor(2, yellow);
      strip.setPixelColor(3, yellow);
 
 
 
     strip.setPixelColor(29, red);
     strip.setPixelColor(30, green);
     strip.setPixelColor(31, yellow);
     // strip.setPixelColor(4, green);
                
      strip.show();
}

void setup() {
    
  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
}

uint32_t pixels[32];

void loadColor(uint32_t color) {
  int i;
  for (i=0; i < strip.numPixels(); i++) {
     strip.setPixelColor(i,color);
  }  
}


void runScaryFlash() 
{
  int fw1[10] = { random(1000), 12, 32, 23, 1, 50, 3, 10, 500, 10 };
  int i, j;
  for ( j = 0 ; j < 12; j++ ) {
  
  for (i=0; i < 10; i++) {
    loadColor(white);
    strip.show();
    delay(random(fw1[i]));

    loadColor(black);
    strip.show();
    delay(random(10));
    
    loadColor(white);
    strip.show();
    delay(random(50));
    
    loadColor(black);
    strip.show();
    delay(random(10));

  }
  }
}


void runGreen() {
  loadColor(orange);
  strip.show();
  delay(1000);
  colorWipe(orange, 1);
  colorWipe( green, 50); //green
  colorWipe(orange, 1);
  

  
}

int greenpos = random(32);
void loop() {
  // Some example procedures showing how to display to the pixels
  
    //colorWipe(Color(255, 0, 0), 50); //blue

    // colorWipe(Color(25, 118, 255), 50); //pumpkin
 // colorWipe(Color(0x00, 0x19, 0xC1), 50);



  //colorWipe(Color(0x00, 0x19, 0xC1), 50);
    
  //colorWipe(Color(0, 0, 255), 50); //red
  //colorWipe(Color(0, 255, 0), 50); //blue
  
    if ( state == STATE_FLASHING ) {
      runScaryFlash();
      state = STATE_GRADE;
    }
    if ( state == STATE_PUMPKIN_RUN ) {
       runGreen();
       state = STATE_PUMPKIN_STOP;
    }
    if ( state == STATE_PUMPKIN_STOP ) {
        loadColor( orange); 
        strip.setPixelColor(greenpos, green);
        if ( random(1,3) == 1 ) {
         greenpos -= 1;
         if ( greenpos < 0 ) greenpos = 31;
        }
        else {
          greenpos += 1;
          if ( greenpos > 31 ) greenpos = 0;
        }
        
        strip.show();
        delay(5000);
        
    }
    if ( state == STATE_WHITE ) {
      loadColor(white);
      strip.show();

       delay(500);
    }
   if ( state == STATE_GRADE ) {
     
     showGrades();
 
    }

    
    

    
  //rainbow(20);
  //rainbowCycle(20);
}

void rainbow(uint8_t wait) {
  int i, j;
   
  for (j=0; j < 256; j++) {     // 3 cycles of all 256 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 255));
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

//void cycle(uint8_t wait, 

// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 96-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 96 is to make the wheel cycle around
      strip.setPixelColor(i, Wheel( ((i * 256 / strip.numPixels()) + j) % 256) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
