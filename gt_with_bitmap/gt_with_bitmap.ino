#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#include <Adafruit_ST7789.h>
#include <Adafruit_ST77xx.h>
#include"bitmap.h"
#include"Menu.h"

const uint8_t TFT_CS = 10;
const uint8_t TFT_RST = 8;
const uint8_t TFT_DC = 9;
uint8_t btnHorizontal = 0, btnVertical = 0;
enum BTN {BTN_RIGHT = 6, BTN_LEFT = 7, BTN_DOWN = 4, BTN_UP = 3, BTN_SELECT = 5};
const char menu_title[Menu::Count][9] PROGMEM={"Home", "GPS", "Setting"};

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("Initializing TFT ..."));
  tft.init(240, 240, SPI_MODE2);
  tft.setRotation(2);
  tft.fillScreen(ST77XX_BLACK);
  Serial.println(F("Done"));

  pinMode(INPUT, BTN_RIGHT);
  pinMode(INPUT, BTN_LEFT);
  pinMode(INPUT, BTN_DOWN);
  pinMode(INPUT, BTN_SELECT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BTN_RIGHT) == HIGH){
    btnVertical = btnVertical > Menu::Count-1 ? 0 : btnVertical+1;
  }else if(digitalRead(BTN_LEFT) == HIGH){
    btnVertical = btnVertical < 0 ? Menu::Count-1 : btnVertical-1;
  }

  tft.fillScreen(ST77XX_BLACK);
  tft.drawBitmap(88, 88, bitmaps[btnVertical], 32, 32, ST77XX_BLUE);
  delay(200);
  
}
