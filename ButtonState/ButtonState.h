/*
  ButtonState.h - Library for reading the state of buttons.
  Created by Martin P. Pawlowski, January 28, 2015.
  Released into the public domain.
  developed on Arduino 1.0.5 r2
  Ver. 1.0
*/

#ifndef ButtonState_h
#define ButtonState_h

#include "Arduino.h"

class ButtonState
{
  public:
    ButtonState(short pin, unsigned long minMilSecShort, unsigned long maxMilSecShort, unsigned long minMilSecLong, unsigned long maxMilSecLong, unsigned long minMilSecBetween);
    void Init();
    void CheckButton();
    short GetButtonState();
    short GetButtonPushType();
	const static short IS_NOT_PRESSED;
	const static short IS_PRESSED;
	const static short WAS_NOT_PRESSED;
	const static short WAS_LONG_PRESSED;
	const static short WAS_SHORT_PRESSED;
	const static short TOO_SHORT_FOR_SHORT;
	const static short TOO_SHORT_FOR_LONG;
	const static short TOO_LONG_FOR_LONG;
  private:
	void _getButtonPushType(unsigned long milSecPressed, unsigned long milSecReleased);
	short _pin;
	unsigned long _minMilSecShort;
	unsigned long _maxMilSecShort;
	unsigned long _minMilSecLong;
	unsigned long _milSecPressed;
	unsigned long _milSecReleased;
	unsigned long _minMilSecBetween;
	unsigned long _maxMilSecLong;
	boolean _wasPressed;
	short _buttonPushType;
	  
	  
};

#endif