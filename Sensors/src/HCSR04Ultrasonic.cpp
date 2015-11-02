/*
 * HCSR04Ultrasonic.cpp
 *
 *  Created on: Oct 14, 2015
 *      Author: florin
 */

#include "HCSR04Ultrasonic.h"

namespace Sensors {

HCSR04Communication::HCSR04Communication(){}

HCSR04Communication::HCSR04Communication(void (triggerFunction) (unsigned short, unsigned short),
		unsigned long (*pulseFunction) (unsigned short, unsigned short),
		void (*delay) (unsigned int))
{
	this->triggerFunction = triggerFunction;
	this->pulseFunction = pulseFunction;
	this->delay = delay;
}

HCSR04Communication::~HCSR04Communication(){}

unsigned long HCSR04Communication::Pulse(unsigned short echoPin)
{
	return pulseFunction(echoPin, 1);
}
void HCSR04Communication::Trigger(unsigned short triggerPin, bool value)
{
	if (value)
	{
		triggerFunction(triggerPin, 1);
	}
	else
	{
		triggerFunction(triggerPin, 0);
	}

}
void HCSR04Communication::Delay(unsigned short microseconds)
{
	delay(microseconds);
}

HCSR04Ultrasonic::HCSR04Ultrasonic(){
	isInitialized = false;
}

HCSR04Ultrasonic::~HCSR04Ultrasonic() {

}

HCSR04Ultrasonic::HCSR04Ultrasonic(unsigned short triggerPort, unsigned short pulsePort, HCSR04Communication hcsr04Communication)
{
	this->communication = hcsr04Communication;
	this->pulsePort = pulsePort;
	this->triggerPort = triggerPort;
	isInitialized = true;

}

double HCSR04Ultrasonic::Read() {
	/* The following trigPin/echoPin cycle is used to determine the
	 distance of the nearest object by bouncing soundwaves off of it. */

	 this->communication.Trigger(triggerPort, false);
	 this->communication.Delay(2);

	 this->communication.Trigger(triggerPort, true);
	 this->communication.Delay(10);

	 this->communication.Trigger(triggerPort, false);

	 unsigned long duration = this->communication.Pulse(pulsePort);
     //Calculate the distance (in cm) based on the speed of sound.
	 double distance = duration/58.2;

	 return distance;
}

} /* namespace Sensors */
