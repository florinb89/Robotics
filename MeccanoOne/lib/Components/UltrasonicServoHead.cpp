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
	isInitialized = false;
	hasDetectionCallback = false;
	isReverseRotating = false;
	stepAngle = 10;
}

UltrasonicServoHead::UltrasonicServoHead(HCSR04Ultrasonic sensor,
		ServoMechanism servo, LED led) {
	this->servo = servo;
	this->sensor = sensor;
	this->led = led;

	this->minRotationAngle = servo.GetMinAngle();
	this->maxRotationAngle = servo.GetMaxAngle();

	isInitialized = true;
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
	if (!isInitialized)
		return;

	if (isScanning) {
		unsigned short angle = GetNextRotationAngle();

		currentAngle = angle;
		servo.Rotate(angle);

		double distance = sensor.Read();

		if (distance > minDetectedValue && distance < maxDetectedValue) {
			led.TurnOn();
		} else {
			led.TurnOff();
		}

		if (hasDetectionCallback) {
			detectedCallback(distance);

		}
	}
}

void UltrasonicServoHead::SetupDetectionRange(unsigned short minDetectedValue,
		unsigned short maxDetectedValue) {
	this->minDetectedValue = minDetectedValue;
	this->maxDetectedValue = maxDetectedValue;
}

unsigned short UltrasonicServoHead::GetNextRotationAngle() {
	if (isReverseRotating) {
		unsigned short nextAngle = currentAngle - stepAngle;

		if (nextAngle < minRotationAngle) {
			isReverseRotating = false;
			return minRotationAngle;
		} else {
			return nextAngle;
		}
	}
	else
	{
		unsigned short nextAngle = currentAngle + stepAngle;

		if (nextAngle > maxRotationAngle) {
			isReverseRotating = true;
			return maxRotationAngle;
		} else {
			return nextAngle;
		}
	}
}

void UltrasonicServoHead::NotifyDetection(
		void (*detectedCallback)(double distance)) {
	this->detectedCallback = detectedCallback;
	this->hasDetectionCallback = true;
}

} /* namespace Components */
