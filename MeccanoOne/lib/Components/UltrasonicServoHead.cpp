/*
 * UltrasonicServoHead.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: florin
 */

#include "UltrasonicServoHead.h"

namespace Components {

UltrasonicServoHead::UltrasonicServoHead() {
	isScanning = false;

}

UltrasonicServoHead::UltrasonicServoHead(HCSR04Ultrasonic sensor,
		ServoMechanism servo, LED led) {
	this->servo = servo;
	this->sensor = sensor;
	this->led = led;

	this->minRotationAngle = servo.GetMinAngle();
	this->maxRotationAngle = servo.GetMaxAngle();
}

UltrasonicServoHead::~UltrasonicServoHead() {

}

void UltrasonicServoHead::StartScan(unsigned short stepAngle) {
	this->stepAngle = stepAngle;
	currentAngle = servo.GetMinAngle();

	servo.Rotate(currentAngle);
	isScanning = true;
}

void UltrasonicServoHead::StopScan() {
	isScanning = false;
}

void UltrasonicServoHead::Scan() {
	if (isScanning)
	{
		unsigned short angle =
	}
}

void UltrasonicServoHead::SetupDetectionRange(unsigned short minDetectedValue,
		unsigned short maxDetectedValue) {
}

unsigned short UltrasonicServoHead::GetAngle() {
}

void UltrasonicServoHead::NotifyDetection(
		void (*detectedCallback)(double distance)) {
}

} /* namespace Components */
