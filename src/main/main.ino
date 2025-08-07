#include "Arduino_LED_Matrix.h"
#include "game_def.h"

ArduinoLEDMatrix matrix;

byte myMap[8][12];
uint8_t py = 0;
int frame = 0;

void setup()
{
  Serial.begin(9600);
  matrix.begin();
  
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);

  py = 7 - GROUND_HEIGHT;
  

  
}

void renderMap()
{
  for(int line = 0; line < 8;line++)
  {
    for(int chr = 0; chr < 12; chr++)
    {
      if((8 - line) <= GROUND_HEIGHT || 
        ((line == py || line == (py - 1)) && chr == PLAYER_X))
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
  Serial.print("FRAME:");
  Serial.println(frame);
  frame++;
  if(frame > 5000)
  {
    frame = 0;
  }
  /*matrix.renderBitmap(myMap, 8, 12);
  if(!digitalRead(BUTTON_A))
  {
    py += 3;
    renderMap();
    matrix.renderBitmap(myMap, 8, 12);
    
    delay(1000);
    py -= 3;
  }
  if(!digitalRead(BUTTON_B))
  {
    Serial.println("Button B Pressed");
  }

  
  delay(250);*/
}
