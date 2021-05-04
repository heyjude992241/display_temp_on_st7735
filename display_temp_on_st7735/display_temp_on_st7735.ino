#include <dht.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include "class.h"

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8
#define DHT11_PIN      7
#define array_length   15

uint8_t curr_pos = 0;

void repaintGraph(Disp* ptr);

Disp data[array_length] = {
  {3, 27},
  {8, 27},
  {13, 27},
  {18, 27},
  {23, 28},
  {28, 28},
  {33, 29},
  {38, 29},
  {43, 30},
  {48, 30},
  {53, 30},
  {58, 30},
  {63, 28},
  {68, 28},
  {73, 28},
};

// For Arduino Uno: MOSI = pin 11 and SCLK = pin 13
// For 1.44" and 1.8" TFT with ST7735 use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
dht DHT;
uint8_t counter = 1;

void setup(void) {
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));
  // OR use this initializer (uncomment) if using a 1.44" TFT:
  tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab
  Serial.println(F("Microcontroller is starting..."));
  tft.fillScreen(ST77XX_BLACK);
}

void loop() {
  //put your code here
  tft.fillScreen(ST77XX_BLACK);
  uint8_t chk = DHT.read11(DHT11_PIN);
  tft.setCursor(0,0);
  tft.print(DHT.temperature);
  if(curr_pos < array_length){
    data[curr_pos].temp = DHT.temperature;
  }else{
    //for loop: swap, and then re-assign the array
    for(int a=0; a<(array_length-2); a++){ //this for loop is for swapping
      data[a].temp = (a+1)==(array_length-1) ? DHT.temperature : data[a+1].temp;
    }
  }
  curr_pos = (curr_pos < array_length) ? curr_pos+1 : array_length+1;
  repaintGraph(data);
  delay(1000);
}

void repaintGraph(Disp* ptr){
  //recall: name of the array is also the pointer to the first element of the array
  for(int i=0; i<curr_pos+1; i++){
    tft.fillRect(ptr->x_coor+1, 128-(ptr->temp+1), 3, 3, ST77XX_GREEN);
    ptr++;
  }
}
