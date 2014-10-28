/*
 * This is Color Box
 * A keypad is connected to a 1.8"TFT LCD Screen
 * Each key on the pad is associated with a color
 * Press each key and see the colors flash
 */
 
//Graphics card library 
#include <Adafruit_GFX.h> 
#include <Adafruit_ST7735.h>
#include <SPI.h>
//
#define TFT_CS     10
#define TFT_RST    9 
#define TFT_DC     8
//
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

#define TFT_SCLK 13
#define TFT_MOSI 11
/////////////////////////////

//Key Pad:

// analog pin connected to keypad
#define KEYPAD_PIN A1 
// milliseconds to wait, to make sure key is pressed
#define TIME_TO_WAIT 50
/////////////////////////////

 
void setup()
{
  Serial.begin(9600);
  analogWrite(6, 255);

  tft.initR(INITR_BLACKTAB);
  uint16_t time = millis();
  tft.fillScreen(ST7735_BLACK);
  time = millis() - time;
}
 
void loop()
{
    // reading once
    int r4 = analogRead(KEYPAD_PIN);
    Serial.println(r4);
    int r1 = analogRead(KEYPAD_PIN) / 10 * 10;
    
    // waiting
    delay(TIME_TO_WAIT);
    // reading 2nd time - to make sure key is pressed for at least TIME_TO_WAIT milliseconds
    int r2 = analogRead(KEYPAD_PIN) / 10 * 10;
    if (r1 == r2) {
      if(r4 < 66 && r4 >=62 ) {
          tft.fillScreen(ST7735_RED);
          Serial.println("0"); 

      }else if(r4 < 340 && r4 > 327){
        tft.fillScreen(ST7735_YELLOW);
          Serial.println("1"); 

      }
      else if(r4 < 520 && r4 > 495){
        tft.fillScreen(ST7735_GREEN);
          Serial.println("2"); 

      }
      else if(r4 < 986 && r4 > 980){
        tft.fillScreen(ST7735_BLUE);
          Serial.println("3"); 

      }
      else if(r4 < 145 && r4 > 130){
        tft.fillScreen(ST7735_MAGENTA);
          Serial.println("4"); 

      }
      else if(r4 < 165 && r4 > 150){
        tft.fillScreen(ST7735_WHITE);
          Serial.println("5"); 

      }
      else if(r4 < 199 && r4 > 175){
        tft.fillScreen(ST7735_RED);
          Serial.println("6"); 

      }
      else if(r4 < 87 && r4 > 80){
        tft.fillScreen(ST7735_GREEN);
          Serial.println("7"); 

      }
      else if(r4 < 95 && r4 > 87){
        tft.fillScreen(ST7735_YELLOW);
          Serial.println("8"); 

      }
      else if(r4 < 105 && r4 > 95){
        tft.fillScreen(ST7735_MAGENTA);
          Serial.println("9"); 

      }
      else if(r4 < 62 && r4 > 55){
      tft.fillScreen(ST7735_BLUE);
          Serial.println("*"); 

      }
      else if(r4 < 71 && r4 >=66){
        tft.fillScreen(ST7735_WHITE);
          Serial.println("#"); 

      }
      
        
    } 
}

void testfillrects(uint16_t color1, uint16_t color2) {
  tft.fillScreen(ST7735_YELLOW);

}


