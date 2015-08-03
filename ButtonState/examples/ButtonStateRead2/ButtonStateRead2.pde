#include <ButtonState.h>

const unsigned char redLedPin = 3;
const unsigned char greenLedPin = 4;
const unsigned char yellowLedPin = 5;
const unsigned char buttonPin = 2;

unsigned char greenLedState = 0;
unsigned char yellowLedState = 0;

ButtonState but1(buttonPin, 20, 200, 300, 1000, 100);

void setup() {

  // initialize the led pins as an output
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  but1.CheckButton();
  
  if(but1.GetButtonState() == ButtonState::IS_PRESSED)
  {
    digitalWrite(redLedPin,HIGH);
  }
  else
  {
    digitalWrite(redLedPin,LOW);
  }
  
  //long pressed GREEN
  if(but1.GetButtonPushType() == ButtonState::WAS_LONG_PRESSED)
  {
    if (greenLedState == 0)
    {
      greenLedState = 1;
      digitalWrite(greenLedPin,HIGH);
    }
    else
    {
      greenLedState = 0;
      digitalWrite(greenLedPin,LOW);
    }
  }
  
  if(but1.GetButtonPushType() == ButtonState::WAS_SHORT_PRESSED)
  {
    if (yellowLedState == 0)
    {
      yellowLedState = 1;
      digitalWrite(yellowLedPin,HIGH);
    }
    else
    {
      yellowLedState = 0;
      digitalWrite(yellowLedPin,LOW);
    }
  }

}