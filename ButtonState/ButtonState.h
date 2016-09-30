/*
  ButtonState.h - Library for reading the state of buttons.
  Created by Martin P. Pawlowski for simplearduinoexamples.com, September 30, 2016.
  Released into the public domain.
  developed on Arduino 1.6.0
*/

#ifndef ButtonState_h
#define ButtonState_h

#include "Arduino.h"

class ButtonState
{
  public:
    ButtonState(short pin);
	ButtonState(short pin, unsigned long minMilSecShort, unsigned long maxMilSecShort);
    void Init();
    void CheckButton();
    boolean WasPressed();
	boolean WasReleased();
	boolean IsPressed();
	short PushType();
	const static short LONG_PRESSED;
	const static short SHORT_PRESSED;
	const static short TRESHOLD;
  private:
	short _pin;
	unsigned long _minMilSecShort;
	unsigned long _maxMilSecShort;
	unsigned long _milSecPressed;
	unsigned long _milSecReleased;
	boolean _isPressed;
	boolean _wasPressed;
	boolean _wasReleased;
	short _prevState;
	short _curState;
};

#endif