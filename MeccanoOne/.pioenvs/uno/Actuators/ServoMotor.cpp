/*
 * ServoMotor.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: florin
 */

#include "ServoMotor.h"

namespace Actuators {

ServoMotor::ServoMotor() {
	isInitialized = false;
	currentAngle = 0;
}

ServoMotor::ServoMotor(void (*writeFunction)(unsigned int value)) {
	this->servoWrite = writeFunction;
	isInitialized = true;
	currentAngle = 0;
}

void ServoMotor::Rotate(unsigned int value) {
	if (isInitialized)
		servoWrite(value);
}

bool ServoMotor::IsInitialized() {
	return isInitialized;
}

ServoMotor::~ServoMotor() {

}

}
