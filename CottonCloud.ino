// This is a demonstration on how to use an input device to trigger changes on your neo pixels.
// You should wire a momentary push button to connect from ground to a digital IO pin.  When you
// press the button it will change to a new pixel animation.  Note that you need to press the
// button once to start the first animation!

#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN   10    // Digital IO pin connected to the button.  This will be
                          // driven with a pull-up resistor so the switch should
                          // pull the pin to ground momentarily.  On a high -> low
                          // transition the button press logic will execute.

#define PIXEL_PIN    4    // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 22

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState = HIGH;
int showType = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Get current button state.
  bool newState = digitalRead(BUTTON_PIN);

  // Check if state changed from high to low (button press).
  if (newState == LOW && oldState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);
    if (newState == LOW) {
      showType++;
      if (showType > 9)
        showType=0;
      startShow(showType);
    }
  }

  // Set the last button state to the old state.
  oldState = newState;
}

void startShow(int i) {
  switch(i){
    case 0: colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
    break;
    case 1: colorWipe(strip.Color(5, 5, 80), 50);  // Bluone
    break;
    case 2: colorWipe(strip.Color(35, 35, 200), 50);  // AzzurroCielo
    break;
    case 3: colorWipe(strip.Color(250, 80, 10), 50);  // Tramonto
    break;
    case 4: rainbow(100);
    break;
    case 5: theaterChase(strip.Color(127, 127, 127), 50); // White
    break;
    case 6: temporale(strip.Color(010, 10, 80), strip.Color(25, 25, 220), 2000, 50);  // AzzurroCielo
    break;
//    case 4: theaterChase(strip.Color(127, 127, 127), 50); // White
//            break;
//    case 5: theaterChase(strip.Color(127,   0,   0), 50); // Red
//            break;
//    case 6: theaterChase(strip.Color(  0,   0, 127), 50); // Blue
//            break;

//    case 8: rainbowCycle(20);
//            break;
//    case 8: theaterChaseRainbow(500);
//            break;
  }
}
void temporale(uint32_t c,uint32_t z, uint32_t wait, uint8_t wait2){
  int old1,old2,lululu,lululu1,lululu2 = 0;
  F:
  delay(random(wait));
  int a = random(120);
  if(random(2) == 1){
  strip.setPixelColor(a,c);
  }
  else{
    strip.setPixelColor(a,z);
  }
  strip.show();
  lululu=random(25);
  if(random(5)==1){
    if(random(2) == 1){
    strip.setPixelColor(lululu,c);
  }
  else{
    strip.setPixelColor(lululu,z);
  }
  }
  strip.show();
  delay(random(wait2));
  if(random(4)==1){
    strip.setPixelColor(a,0);
  }
  strip.setPixelColor(lululu2,0);
  lululu2=lululu1;
  lululu1=lululu;
  strip.setPixelColor(old2,0);
  old2 = old1;
  old1 = a;
  int b =random(22);
  strip.setPixelColor(b, 0);
  int d =random(22);
  strip.setPixelColor(d, 0);
  int e =random(22);
  strip.setPixelColor(e, 0);
  int f =random(22);
  strip.setPixelColor(f, 0);
  int g =random(22);
  strip.setPixelColor(g, 0);
  int h =random(22);
  strip.setPixelColor(h, 0);
  int i =random(22);
  strip.setPixelColor(i, 0);
  int j =random(22);
  strip.setPixelColor(j, 0);
  int k =random(22);
  strip.setPixelColor(k, 0);
  int l =random(22);
  strip.setPixelColor(l, 0);
    int m =random(22);
  strip.setPixelColor(m, 0);
  int n =random(22);
  strip.setPixelColor(n, 0);
  int o =random(22);
  strip.setPixelColor(o, 0);
  int p =random(22);
  strip.setPixelColor(p, 0);
  int q =random(22);
  strip.setPixelColor(q, 0);
  oldState == LOW;
bool newState = digitalRead(BUTTON_PIN);
  if (newState == LOW && oldState == HIGH) {
      delay(200);
      newState = digitalRead(BUTTON_PIN);
      if (newState == LOW) {
        i++;
        return;
      }
    }
  goto F;
 
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;
  A:
  j=0;
  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);


//break   
oldState == LOW;
bool newState = digitalRead(BUTTON_PIN);
  if (newState == LOW && oldState == HIGH) {
      delay(200);
      newState = digitalRead(BUTTON_PIN);
      if (newState == LOW) {
        i++;
        return;
      }
    }
   
  }
      goto A;
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<1; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
