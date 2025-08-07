#include "Arduino_LED_Matrix.h"
#include "game_def.h"

ArduinoLEDMatrix matrix;

byte myMap[8][12];
uint8_t py = 0;

PinStatus now = HIGH;
PinStatus last = HIGH;

void setup()
{
  Serial.begin(9600);
  matrix.begin();
  
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  py = 7 - GROUND_HEIGHT;

  for(int line = 0; line < 8;line++)
  {
    for(int chr = 0; chr < 12; chr++)
    {
      if((8 - line) <= GROUND_HEIGHT || 
        (line == py && chr == PLAYER_X))
      {
        myMap[line][chr] = 1;
      }
      else
      {
        myMap[line][chr] = 0;
        
      }
    }
  }
}

void loop()
{
  now = digitalRead(BUTTON_A);
  matrix.renderBitmap(myMap, 8, 12);
  if(now == HIGH && last == LOW)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(120);
    myMap[py][PLAYER_X] = 0;
    py--;
    myMap[py][PLAYER_X] = 1;
    matrix.renderBitmap(myMap, 8, 12);
    delay(120);
    myMap[py][PLAYER_X] = 0;
    py++;
    myMap[py][PLAYER_X] = 1;
    matrix.renderBitmap(myMap, 8, 12);
    delay(120);


  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  last = now;
  /*
  if(!digitalRead(BUTTON_B))
  {
    Serial.println("Button B Pressed");
  }

  
  delay(250);*/
}
