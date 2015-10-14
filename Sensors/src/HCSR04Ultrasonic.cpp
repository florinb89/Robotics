/*
 * HCSR04Ultrasonic.cpp
 *
 *  Created on: Oct 14, 2015
 *      Author: florin
 */

#include "HCSR04Ultrasonic.h"

namespace Sensors {

HCSR04Communication::HCSR04Communication(PortCommunication trigger, PortCommunication pulse, void (*delay)(unsigned short)){
	this->pulse = pulse;
	this->trigger = trigger;
	this->delay = delay;

}

HCSR04Ultrasonic::HCSR04Ultrasonic() {
	isInitialized = false;
}

HCSR04Ultrasonic::HCSR04Ultrasonic(unsigned short port, HCSR04Communication hcsr04Communication)
{
	this->communication = hcsr04Communication;
	this->port = port;
	isInitialized = true;

}

HCSR04Ultrasonic::~HCSR04Ultrasonic() {
	// TODO Auto-generated destructor stub
}



} /* namespace Sensors */
