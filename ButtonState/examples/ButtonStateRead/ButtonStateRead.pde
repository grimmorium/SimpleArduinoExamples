/*
  ButtonState.h - Library for reading the state of buttons.
  Created by Martin P. Pawlowski for simplearduinoexamples.com, September 30, 2016.
  Released into the public domain.
  developed on Arduino 1.6.0
  
  Schema and description on www.simplearduinoexamples.com/Buttons
*/


#include <ButtonState.h>

//button
const int buttonPin = 2; 
ButtonState but1(buttonPin);

//LEDs
const int ledWasPressed = 5 ; 
const int ledIsPressed = 6; 
const int ledWasReleased = 7; 
const int ledLongPressed = 8; 
const int ledShortPressed = 9; 

void setup()
{
  pinMode(ledWasPressed, OUTPUT); 
  pinMode(ledIsPressed, OUTPUT); 
  pinMode(ledWasReleased, OUTPUT); 
  pinMode(ledLongPressed, OUTPUT); 
  pinMode(ledShortPressed, OUTPUT); 

  but1.Init();
}

void loop()
{
  but1.CheckButton();
  digitalWrite(ledWasPressed, LOW);
  digitalWrite(ledIsPressed, LOW);
  digitalWrite(ledWasReleased, LOW);
  digitalWrite(ledLongPressed, LOW);
  digitalWrite(ledShortPressed, LOW);
  
  if(but1.WasPressed()){
    digitalWrite(ledWasPressed, HIGH);
  }
  if(but1.WasReleased()){
    digitalWrite(ledWasReleased, HIGH);
  }
  if(but1.IsPressed()){
    digitalWrite(ledIsPressed, HIGH);
  }
  
  if(but1.WasReleased() && but1.PushType() == but1.LONG_PRESSED){
    digitalWrite(ledLongPressed, HIGH);
  }
  if(but1.WasReleased() && but1.PushType() == but1.SHORT_PRESSED){
    digitalWrite(ledShortPressed, HIGH);
  }
  
  delay(80);
}