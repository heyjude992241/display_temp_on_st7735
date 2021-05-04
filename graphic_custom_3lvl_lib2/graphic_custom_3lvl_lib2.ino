/***************************************************
  This is a library for the ST7789 IPS SPI display.

  Originally written by Limor Fried/Ladyada for 
  Adafruit Industries.

  Modified by Ananev Ilia
 ****************************************************/

#include <Adafruit_GFX.h>    // Core graphics library by Adafruit
#include <Arduino_ST7789.h> // Hardware-specific library for ST7789 (with or without CS pin)
#include <SPI.h>

#define TFT_DC    8
#define TFT_RST   -1 
#define TFT_CS    10 // only for displays with CS pin
#define TFT_MOSI  11   // for hardware SPI data pin (all of available pins)
#define TFT_SCLK  13   // for hardware SPI sclk pin (all of available pins)

//You can use different type of hardware initialization
//using hardware SPI (11, 13 on UNO; 51, 52 on MEGA; ICSP-4, ICSP-3 on DUE and etc)
Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST); //for display without CS pin

//or you can use software SPI on all available pins (slow)
//Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK); //for display without CS pin
//Arduino_ST7789 tft = Arduino_ST7789(-1, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_CS); //for display with CS pin and DC via 9bit SPI


float p = 3.1415926;

void setup(void) {
  Serial.begin(9600);
  Serial.print("Hello! ST7789 TFT Test");

  tft.init(240, 240);   // initialize a ST7789 chip, 240x240 pixels

  Serial.println("Initialized");

  uint16_t time = millis();
  tft.fillScreen(BLACK);
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);

  // large block of text
  tft.fillScreen(BLACK);
  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
  delay(1000);

  Serial.println("done");
  delay(1000);
}

void loop() {
  tft.invertDisplay(true);
  delay(500);
  tft.invertDisplay(false);
  delay(500);
}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}
