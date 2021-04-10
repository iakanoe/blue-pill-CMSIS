/*
 * InputPin.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ianicknoejovich
 */

#ifndef DR_H_HAL_INPUTPIN_H_
#define DR_H_HAL_INPUTPIN_H_

#include <System.h>
#include <HAL/Pin.h>
#include <Hardware/DR_GPIO.h>
//#include "OutputPin.h"

class InputPin : Pin {

public:
	enum Mode {PULLUP, PULLDOWN, FLOATING, ANALOG};
	InputPin(uint8_t port, uint8_t pin, Mode mode = Mode::PULLDOWN);
	void init(void);
	inline bool read() {return GPIO_getPin(_port, _pin);}
//	OutputPin toOutputPin(OutputPin::Mode mode);

private:
	uint8_t _mode;
};

/*
bool operator << (bool val, const InputPin &pin){
	val = pin.read();;
}*/

#endif /* DR_H_HAL_INPUTPIN_H_ */
