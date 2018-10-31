#include <SPI.h>
#include <MFRC522.h>
#include <FastLED.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <JQ6500_Serial.h>

#define LED_PIN D8
#define NUM_LEDS    30
#define SS_PIN D4
#define RST_PIN D3
JQ6500_Serial mp3(D0,D1);

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 CRGB leds[NUM_LEDS];
 
void setup() 
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  mp3.playFileByIndexNumber(1);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Driver Ready...");
  Serial.println();
  Serial.begin(9600);
  mp3.begin(9600);
  mp3.reset();
  mp3.setVolume(20);
  mp3.setLoopMode(MP3_LOOP_NONE);
  mp3.playFileByIndexNumber(1);
}

void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
 
  content.toUpperCase();
  
  if (content.substring(1) == "D4 EE 27 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Rabbit ");
    Serial.println();
    leds[0] = CRGB(255, 0, 0);
leds[1] = CRGB(255, 0, 0);
leds[2] = CRGB(255, 0, 0);
leds[3] = CRGB(255, 0, 0);
leds[4] = CRGB(255, 0, 0);
leds[5] = CRGB(255, 0, 0);
leds[6] = CRGB(255, 0, 0);
leds[7] = CRGB(255, 0, 0);
leds[8] = CRGB(255, 0, 0);
leds[9] = CRGB(255, 0, 0);
leds[10] = CRGB(255, 0, 0);
leds[11] = CRGB(255, 0, 0);
leds[12] = CRGB(255, 0, 0);
leds[13] = CRGB(255, 0, 0);
leds[14] = CRGB(255, 0, 0);
  FastLED.show();
  mp3.playFileByIndexNumber(14);
  }

  if (content.substring(1) == "D5 1C 29 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Tank ");
    Serial.println();
  leds[15] = CRGB(0, 0, 255);
leds[16] = CRGB(0, 0, 255);
leds[17] = CRGB(0, 0, 255);
leds[18] = CRGB(0, 0, 255);
leds[19] = CRGB(0, 0, 255);
leds[20] = CRGB(0, 0, 255);
leds[21] = CRGB(0, 0, 255);
leds[22] = CRGB(0, 0, 255);
leds[23] = CRGB(0, 0, 255);
leds[24] = CRGB(0, 0, 255);
leds[25] = CRGB(0, 0, 255);
leds[26] = CRGB(0, 0, 255);
leds[27] = CRGB(0, 0, 255);
leds[28] = CRGB(0, 0, 255);
leds[29] = CRGB(0, 0, 255);
FastLED.show();
mp3.playFileByIndexNumber(16);
  } 
   if (content.substring(1) == "01 C8 28 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Ninja");
    Serial.println();
    leds[0] = CRGB(148, 0, 211);
leds[1] = CRGB(148, 0, 211);
leds[2] = CRGB(148, 0, 211);
leds[3] = CRGB(148, 0, 211);
leds[4] = CRGB(148, 0, 211);
leds[5] = CRGB(148, 0, 211);
leds[6] = CRGB(148, 0, 211);
leds[7] = CRGB(148, 0, 211);
leds[8] = CRGB(148, 0, 211);
leds[9] = CRGB(148, 0, 211);
leds[10] = CRGB(148, 0, 211);
leds[11] = CRGB(148, 0, 211);
leds[12] = CRGB(148, 0, 211);
leds[13] = CRGB(148, 0, 211);
leds[14] = CRGB(148, 0, 211);
FastLED.show();
mp3.playFileByIndexNumber(11);
  } 

  if (content.substring(1) == "A9 06 28 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Comic");
    Serial.println();
    leds[15] = CRGB(255, 255, 0);
leds[16] = CRGB(255, 255, 0);
leds[17] = CRGB(255, 255, 0);
leds[18] = CRGB(255, 255, 0);
leds[19] = CRGB(255, 255, 0);
leds[20] = CRGB(255, 255, 0);
leds[21] = CRGB(255, 255, 0);
leds[22] = CRGB(255, 255, 0);
leds[23] = CRGB(255, 255, 0);
leds[24] = CRGB(255, 255, 0);
leds[25] = CRGB(255, 255, 0);
leds[26] = CRGB(255, 255, 0);
leds[27] = CRGB(255, 255, 0);
leds[28] = CRGB(255, 255, 0);
leds[29] = CRGB(255, 255, 0);
FastLED.show();
mp3.playFileByIndexNumber(3);
  }
  if (content.substring(1) == "E1 09 29 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Rocket");
    Serial.println();
    leds[15] = CRGB(100, 149, 237);
leds[16] = CRGB(100, 149, 237);
leds[17] = CRGB(100, 149, 237);
leds[18] = CRGB(100, 149, 237);
leds[19] = CRGB(100, 149, 237);
leds[20] = CRGB(100, 149, 237);
leds[21] = CRGB(100, 149, 237);
leds[22] = CRGB(100, 149, 237);
leds[23] = CRGB(100, 149, 237);
leds[24] = CRGB(100, 149, 237);
leds[25] = CRGB(100, 149, 237);
leds[26] = CRGB(100, 149, 237);
leds[27] = CRGB(100, 149, 237);
leds[28] = CRGB(100, 149, 237);
leds[29] = CRGB(100, 149, 237);
FastLED.show();
mp3.playFileByIndexNumber(15);
  }
  if (content.substring(1) == "B0 00 2A 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Panda");
    Serial.println();
    leds[0] = CRGB(255, 255, 255);
leds[1] = CRGB(255, 255, 255);
leds[2] = CRGB(255, 255, 255);
leds[3] = CRGB(255, 255, 255);
leds[4] = CRGB(255, 255, 255);
leds[5] = CRGB(255, 255, 255);
leds[6] = CRGB(255, 255, 255);
leds[7] = CRGB(255, 255, 255);
leds[8] = CRGB(255, 255, 255);
leds[9] = CRGB(255, 255, 255);
leds[10] = CRGB(255, 255, 255);
leds[11] = CRGB(255, 255, 255);
leds[12] = CRGB(255, 255, 255);
leds[13] = CRGB(255, 255, 255);
leds[14] = CRGB(255, 255, 255);
FastLED.show();
mp3.playFileByIndexNumber(12);
  }
  
  if (content.substring(1) == "A6 6D 4C 54") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" gorilla ");
    Serial.println();
leds[0] = CRGB(139, 69, 19);
leds[1] = CRGB(139, 69, 19);
leds[2] = CRGB(139, 69, 19);
leds[3] = CRGB(139, 69, 19);
leds[4] = CRGB(139, 69, 19);
leds[5] = CRGB(139, 69, 19);
leds[6] = CRGB(139, 69, 19);
leds[7] = CRGB(139, 69, 19);
leds[8] = CRGB(139, 69, 19);
leds[9] = CRGB(139, 69, 19);
leds[10] = CRGB(139, 69, 19);
leds[11] = CRGB(139, 69, 19);
leds[12] = CRGB(139, 69, 19);
leds[13] = CRGB(139, 69, 19);
leds[14] = CRGB(139, 69, 19);
  FastLED.show();
  mp3.playFileByIndexNumber(8);
  }
  
  if (content.substring(1) == "3B C2 29 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Diamond");
    Serial.println();
leds[15] = CRGB(0, 192, 255);
leds[16] = CRGB(0, 192, 255);
leds[17] = CRGB(0, 192, 255);
leds[18] = CRGB(0, 192, 255);
leds[19] = CRGB(0, 192, 255);
leds[20] = CRGB(0, 192, 255);
leds[21] = CRGB(0, 192, 255);
leds[22] = CRGB(0, 192, 255);
leds[23] = CRGB(0, 192, 255);
leds[24] = CRGB(0, 192, 255);
leds[25] = CRGB(0, 192, 255);
leds[26] = CRGB(0, 192, 255);
leds[27] = CRGB(0, 192, 255);
leds[28] = CRGB(0, 192, 255);
leds[29] = CRGB(0, 192, 255);
FastLED.show();
mp3.playFileByIndexNumber(4);
  }
  if (content.substring(1) == "1D 9E 29 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" kaka ");
    Serial.println();
leds[0] = CRGB(255, 140, 0);
leds[1] = CRGB(255, 140, 0);
leds[2] = CRGB(255, 140, 0);
leds[3] = CRGB(255, 140, 0);
leds[4] = CRGB(255, 140, 0);
leds[5] = CRGB(255, 140, 0);
leds[6] = CRGB(255, 140, 0);
leds[7] = CRGB(255, 140, 0);
leds[8] = CRGB(255, 140, 0);
leds[9] = CRGB(255, 140, 0);
leds[10] = CRGB(255, 140, 0);
leds[11] = CRGB(255, 140, 0);
leds[12] = CRGB(255, 140, 0);
leds[13] = CRGB(255, 140, 0);
leds[14] = CRGB(255, 140, 0);
  FastLED.show();
  mp3.playFileByIndexNumber(10);
  }
   if (content.substring(1) == "80 F4 28 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" gatling");
    Serial.println();
leds[15] = CRGB(220, 220, 220);
leds[16] = CRGB(220, 220, 220);
leds[17] = CRGB(220, 220, 220);
leds[18] = CRGB(220, 220, 220);
leds[19] = CRGB(220, 220, 220);
leds[20] = CRGB(220, 220, 220);
leds[21] = CRGB(220, 220, 220);
leds[22] = CRGB(220, 220, 220);
leds[23] = CRGB(220, 220, 220);
leds[24] = CRGB(220, 220, 220);
leds[25] = CRGB(220, 220, 220);
leds[26] = CRGB(220, 220, 220);
leds[27] = CRGB(220, 220, 220);
leds[28] = CRGB(220, 220, 220);
leds[29] = CRGB(220, 220, 220);
FastLED.show();
mp3.playFileByIndexNumber(9);
  }
}

void ChangeLedColor(int r, int g, int b, int _delay, bool isMegaman)
{
  int count = 1;
  if (isMegaman)
  {
    for(int i = 0; i <= 30; i++)
    {
      leds[i] = CRGB(r,g,b);
      FastLED.show();
      delay(_delay);
    }
  }
  else
{
  for (int i =0; i <= 30; i++)
    { 
      switch(count)
      {
        case 1:
        leds[i] = CRGB(255, 0, 0);
        break;
      }
      count++;
      if(count >1)
        count = 1;
      FastLED.show();
      delay(_delay);   
    }
  }
    
    delay(500);
}

