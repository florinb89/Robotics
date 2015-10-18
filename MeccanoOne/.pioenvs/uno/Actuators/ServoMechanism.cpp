/*
 * ServoMechanism.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: florin
 */

#include "ServoMechanism.h"
#include "ServoMotor.h"

namespace Actuators {

ServoMechanism::ServoMechanism() {
	minAngle = 0;
	maxAngle = 180;
}

ServoMechanism::ServoMechanism(void (*servoWrite)(unsigned int), void (*delayFunction)(unsigned int), unsigned int minAngle, unsigned int maxAngle){
	ServoMotor servoMotor(servoWrite);
	this->servoMotor = servoMotor;
	this->delayFunction = delayFunction;
	this->minAngle = minAngle;
	this->maxAngle = maxAngle;

}

ServoMechanism::~ServoMechanism() {

}

void ServoMechanism::Rotate(unsigned int angle, unsigned int delay = 20){
	if (servoMotor.IsInitialized()){
		if (angle >= minAngle && angle <= maxAngle){
			servoMotor.Rotate(angle);
			delayFunction(delay);
		}
	}
}

}
