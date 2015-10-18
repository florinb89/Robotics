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
public:
	UltrasonicServoHead();
	UltrasonicServoHead(HCSR04Ultrasonic sensor, ServoMechanism servo, LED led);
	virtual ~UltrasonicServoHead();
	void Scan(unsigned short stepAngle);
};

} /* namespace Components */

#endif /* LIB_COMPONENTS_ULTRASONICSERVOHEAD_H_ */
