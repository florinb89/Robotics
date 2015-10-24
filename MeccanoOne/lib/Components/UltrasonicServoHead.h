/*
 * UltrasonicServoHead.h
 *
 *  Created on: Oct 18, 2015
 *      Author: florin
 */

#ifndef LIB_COMPONENTS_ULTRASONICSERVOHEAD_H_
#define LIB_COMPONENTS_ULTRASONICSERVOHEAD_H_

#include "ServoMechanism.h"
#include "HCSR04Ultrasonic.h"

using namespace Sensors;
using namespace Actuators;

namespace Components {

class UltrasonicServoHead {
private:
	HCSR04Ultrasonic sensor;
	ServoMechanism servo;
	LED led;
	unsigned short minDetectedValue;
	unsigned short maxDetectedValue;
	bool hasDetectionCallback;
	bool isScanning;
	bool isReverseRotating;
	bool isInitialized;
	unsigned short currentAngle;
	unsigned short stepAngle;
	unsigned short minRotationAngle;
	unsigned short maxRotationAngle;

	void (*detectedCallback)(double distance);
	unsigned short GetNextRotationAngle();

public:
	UltrasonicServoHead();
	UltrasonicServoHead(HCSR04Ultrasonic sensor, ServoMechanism servo, LED led);
	virtual ~UltrasonicServoHead();
	void StartScan(unsigned short stepAngle);
	void StopScan();
	void Scan();
	void SetupDetectionRange(unsigned short minDetectedValue, unsigned short maxDetectedValue);
	void NotifyDetection(void (*detectedCallback)(double distance));
};

} /* namespace Components */

#endif /* LIB_COMPONENTS_ULTRASONICSERVOHEAD_H_ */
