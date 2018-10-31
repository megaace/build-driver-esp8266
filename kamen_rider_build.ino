#include <SPI.h>
#include <MFRC522.h>
#include <FastLED.h>

#define LED_PIN     D8
#define NUM_LEDS    30
#define SS_PIN 2
#define RST_PIN 0

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 CRGB leds[NUM_LEDS];

 
void setup() 
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Driver Ready...");
  Serial.println();

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
    Serial.println(" Rabbit");
    Serial.println();
    CRGB(255, 0, 0);
    delay (1000);
  }
 
  if (content.substring(1) == "D5 1C 29 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Tank");
    Serial.println();
    CRGB(0, 0, 255);
    delay (1000);
  }
  
  if (content.substring(1) == "12 34 56 78") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" idk");
    Serial.println();
    CRGB(0, 0, 255);
    delay (1000);
  } 

  if (content.substring(1) == "01 C8 28 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Ninja");
    Serial.println();
    CRGB(148, 0, 211);
    delay (1000);
  }
  
  if (content.substring(1) == "A9 06 28 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Comic");
    Serial.println();
    CRGB(255, 255, 0);
    delay (1000);
  }
  
  if (content.substring(1) == "E1 09 29 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Rocket");
    Serial.println();
    CRGB(100, 149, 237);
    delay (1000);
  }
    
  if (content.substring(1) == "B0 00 2A 83") //change here the UID of the card/cards that you want to give access
  {
    Serial.println(" Panda");
    Serial.println();
    CRGB(255, 255, 255);
    delay (1000);
  }
}
