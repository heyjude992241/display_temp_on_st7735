#include<Adafruit_GFX.h>
#include<Adafruit_ST7789.h>
#include<SPI.h>

#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello!! ST7789 test");
  tft.init(240, 240);
  tft.setCursor(0, 0);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
}

float pi = 3.1415926;

void loop() {
  // put your main code here, to run repeatedly:
  tft.print("Pi is:");
  tft.setCursor(0, 20);
  tft.print(pi);
}
