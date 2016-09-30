/*
  ButtonState.h - Library for reading the state of buttons.
  Created by Martin P. Pawlowski for simplearduinoexamples.com, September 30, 2016.
  Released into the public domain.
  developed on Arduino 1.6.0
*/

#include "Arduino.h"
#include "ButtonState.h"

ButtonState::ButtonState(short pin)
{
  _pin = pin;
  _minMilSecShort = 20; 
  _maxMilSecShort = 350;
  _prevState = LOW;
}

ButtonState::ButtonState(short pin, unsigned long minMilSecShort, unsigned long maxMilSecShort)
{
  _pin = pin;
  _minMilSecShort = minMilSecShort; 
  _maxMilSecShort = maxMilSecShort;
  _prevState = LOW;
}

void ButtonState::Init()
{
  pinMode(_pin, INPUT);
}

short ButtonState::PushType()
{
	if(_milSecReleased - _milSecPressed > _maxMilSecShort){
		return LONG_PRESSED;
	}
	if(_milSecReleased - _milSecPressed < _minMilSecShort){
		return TRESHOLD;
	}
	if((_milSecReleased - _milSecPressed < _maxMilSecShort) && 
	(_milSecReleased - _milSecPressed > _minMilSecShort)){
		return SHORT_PRESSED;
	}
}

boolean ButtonState::IsPressed()
{
	return _isPressed;
}

boolean ButtonState::WasReleased()
{
	return _wasReleased;
}

boolean ButtonState::WasPressed()
{
	return _wasPressed;
}

void ButtonState::CheckButton()
{
	_isPressed = false;
	_wasReleased = false;
	_wasPressed = false;
	_curState = digitalRead(_pin);
	
	if(_curState==HIGH){
		_isPressed = true;
	}
	
	if(_prevState==HIGH && _curState==LOW){
		_wasReleased = true;
		_milSecReleased = millis();
	}
	
	if(_prevState==LOW && _curState==HIGH){
		_wasPressed = true;
		_milSecPressed = millis();
	}
	
	_prevState = _curState;
}

//static 
const short ButtonState::LONG_PRESSED = 1;
const short ButtonState::SHORT_PRESSED = 2;
const short ButtonState::TRESHOLD = 3;
