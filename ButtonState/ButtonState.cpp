/*
  ButtonState.h - Library for reading the state of buttons.
  Created by Martin P. Pawlowski, January 28, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ButtonState.h"

ButtonState::ButtonState(short pin, unsigned long minMilSecShort, unsigned long maxMilSecShort, unsigned long minMilSecLong, unsigned long maxMilSecLong, unsigned long minMilSecBetween)
{
  _pin = pin;
  _minMilSecShort = minMilSecShort; 
  _maxMilSecShort = maxMilSecShort;
  _minMilSecLong = minMilSecLong;
  _wasPressed = false;
  _milSecReleased = 0;
  _minMilSecBetween = minMilSecBetween;
  _buttonPushType = ButtonState::WAS_NOT_PRESSED;
  _maxMilSecLong = maxMilSecLong;
}

void ButtonState::Init()
{
  pinMode(_pin, INPUT);
}

void ButtonState::_getButtonPushType(unsigned long milSecPressed, unsigned long milSecReleased)
{
	//TOO_SHORT_FOR_SHORT
	if(milSecReleased - milSecPressed < _minMilSecShort)
	{
		_buttonPushType = ButtonState::TOO_SHORT_FOR_SHORT;
	}
	//WAS_SHORT_PRESSED
	//else 
	if(milSecReleased - milSecPressed > _minMilSecShort && milSecReleased - milSecPressed < _maxMilSecShort)
	{
		_buttonPushType = ButtonState::WAS_SHORT_PRESSED;
	}
	//TOO_SHORT_FOR_LONG
	//else 
	if(milSecReleased - milSecPressed > _maxMilSecShort && milSecReleased - milSecPressed < _minMilSecLong)
	{
		_buttonPushType = ButtonState::TOO_SHORT_FOR_LONG;
	}
	//TOO_LONG_FOR_LONG
	//else 
	if(milSecReleased - milSecPressed > _minMilSecLong && milSecReleased - milSecPressed < _maxMilSecLong)
	{
		_buttonPushType = ButtonState::WAS_LONG_PRESSED;
	}
	//TOO_LONG_FOR_LONG
	if (millis() - _milSecPressed > _maxMilSecLong )
		  _buttonPushType = ButtonState::TOO_LONG_FOR_LONG;
}

void ButtonState::CheckButton()
{
  //button was not pressed
  if (_wasPressed == false &&  digitalRead(_pin) == LOW)
  {
	   _buttonPushType = ButtonState::WAS_NOT_PRESSED;
  }
  
  //button still pressed
  if (_wasPressed == true &&  digitalRead(_pin) == HIGH && (millis() - _milSecReleased > _minMilSecBetween))
  {
	  //check if it is a "long press"
	  if (millis() - _milSecPressed > _maxMilSecLong )
		  _buttonPushType = ButtonState::TOO_LONG_FOR_LONG;
  }
  
  //button pressed event
  if (_wasPressed == false &&  digitalRead(_pin) == HIGH && (millis() - _milSecReleased > _minMilSecBetween))
  {
	  _wasPressed = true;
	  _milSecPressed = millis();
  }
  
  //button released event
  if (_wasPressed == true &&  digitalRead(_pin) == LOW)
  {
	  _wasPressed = false;
	  _milSecReleased = millis();
	  _getButtonPushType(_milSecPressed, _milSecReleased);
  }
  
}

short ButtonState::GetButtonState()
{
  switch (digitalRead(_pin)) {
  case HIGH:
    return ButtonState::IS_PRESSED;
    break;
  case LOW:
    return ButtonState::IS_NOT_PRESSED;
    break;
  default: 
    return ButtonState::IS_NOT_PRESSED;
  }
}

short ButtonState::GetButtonPushType()
{
  return _buttonPushType;
}

//static 
const short ButtonState::IS_NOT_PRESSED = 1;
const short ButtonState::IS_PRESSED = 2;
const short ButtonState::WAS_NOT_PRESSED = 3;
const short ButtonState::WAS_LONG_PRESSED = 4 ;
const short ButtonState::WAS_SHORT_PRESSED = 5;
const short ButtonState::TOO_SHORT_FOR_SHORT = 6;
const short ButtonState::TOO_SHORT_FOR_LONG = 7;
const short ButtonState::TOO_LONG_FOR_LONG = 8;