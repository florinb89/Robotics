/*
 * LED.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: florin
 */

#include "LED.h"

namespace Actuators {

LED::LED() {
	// TODO Auto-generated constructor stub

}

LED::~LED() {
	// TODO Auto-generated destructor stub
}

LED::LED(unsigned short port,
		void (*pinWrite)(unsigned short pin, unsigned short value)) {
	this->pinWrite = pinWrite;
	this->port = port;
}

void LED::TurnOn() {
	isOn = true;
	pinWrite(port, 1);
}
void LED::TurnOff() {
	isOn = false;
	pinWrite(port, 0);
}
bool LED::IsOn() {
	return isOn;
}

} /* namespace Actuators */
