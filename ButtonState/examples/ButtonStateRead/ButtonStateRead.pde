#include <ButtonState.h>

//button
const int buttonPin = 2; 
ButtonState but1(buttonPin, 50, 250, 2000, 3000, 150);

//button state led
const int ledPin =  13; 

//button push type leds
const int ledPinWAS_LONG_PRESSED =  4; 
const int ledPinWAS_SHORT_PRESSED =  5; 

int ledPinWAS_LONG_PRESSEDState;
int ledPinWAS_SHORT_PRESSEDState;

void setup()
{
  pinMode(ledPin, OUTPUT); 
  pinMode(ledPinWAS_LONG_PRESSED, OUTPUT); 
  pinMode(ledPinWAS_SHORT_PRESSED, OUTPUT); 
  
  int ledPinWAS_LONG_PRESSEDState = 0;
  int ledPinWAS_SHORT_PRESSEDState = 0;
  
  but1.Init();
}

void loop()
{
  but1.CheckButton();
  
  if(but1.GetButtonState() == ButtonState::IS_PRESSED)
  {
   digitalWrite(ledPin, HIGH);  
  }
  if(but1.GetButtonState() == ButtonState::IS_NOT_PRESSED)
  {
   digitalWrite(ledPin, LOW);  
  }
  
  if(but1.GetButtonPushType() == ButtonState::WAS_LONG_PRESSED)
  {
    if(ledPinWAS_LONG_PRESSEDState == 0)
    {
      digitalWrite(ledPinWAS_LONG_PRESSED, HIGH);
      ledPinWAS_LONG_PRESSEDState = 1;
    }
    else
    {
      digitalWrite(ledPinWAS_LONG_PRESSED, LOW);
      ledPinWAS_LONG_PRESSEDState = 0;
    }
  }

  if(but1.GetButtonPushType() == ButtonState::WAS_SHORT_PRESSED)
  {
    if(ledPinWAS_SHORT_PRESSEDState == 0)
    {
      digitalWrite(ledPinWAS_SHORT_PRESSED, HIGH); 
      ledPinWAS_SHORT_PRESSEDState = 1;
    }
    else
    {
      digitalWrite(ledPinWAS_SHORT_PRESSED, LOW); 
      ledPinWAS_SHORT_PRESSEDState = 0;
    }
  }


}