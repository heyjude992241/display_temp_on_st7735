/**
 * @author wannaikedo
 * Reference: ST7789/35 example graphic test
 * from Adafruit Industries
 */
#include <TinyGPS++.h>        // GPS parsing library
#include<SoftwareSerial.h>    // UART communication library
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>            // Serial Peripheral Interface (SPI) communication library

const uint8_t TFT_CS = 10;
const uint8_t TFT_RST = 8; // Or set to -1 and connect to Arduino RESET pin
const uint8_t TFT_DC = 9;
const uint8_t RXPin = 4, TXPin = 3;

/**
   * Initilizing TinyGPS++ object.
   * Requires use of SoftwareSerial, and assuming 
   * GPS module with 9600 baud rate
 */
 TinyGPSPlus gps;
 SoftwareSerial ss(RXPin, TXPin);

// Use the HARDWARE SPI pins, which are unique
// to each board and not reassignable. For Arduino Uno: MOSI = pin 11 and
// SCLK = pin 13. This is the fastest mode of operation and is required if
// using the breakout board's microSD card.

// For 1.14", 1.3", 1.54", and 2.0" TFT with ST7789:
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

float p = 3.1415926;

void setup(void) {
  Serial.begin(115200);
  //Init software serial
  Serial.println(F("Software serial begin..."));
  ss.begin(9600);
  //Init ST7789
  Serial.print(F("ST7789 begin..."));
  // OR use this initializer (uncomment) if using a 1.3" or 1.54" 240x240 TFT:
  // If dispay comes with CS pin, use SPI_MODE0
  tft.init(240, 240, SPI_MODE2);           // Init ST7789 240x240
  tft.setRotation(2);
  // SPI speed defaults to SPI_DEFAULT_FREQ defined in the library, you can override it here
  // Note that speed allowable depends on chip and quality of wiring, if you go too fast, you
  // may end up with a black screen some times, or all the time.
  //tft.setSPISpeed(40000000);
  Serial.println(F("Program starting..."));
}

void loop() {
  
}
