/*
 * UltrasonicServoHead.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: florin
 */

#include "UltrasonicServoHead.h"

namespace Components {

UltrasonicServoHead::UltrasonicServoHead() {


}

UltrasonicServoHead::UltrasonicServoHead(HCSR04Ultrasonic sensor,
		ServoMechanism servo, LED led) {

}

UltrasonicServoHead::~UltrasonicServoHead() {
	// TODO Auto-generated destructor stub
}

void UltrasonicServoHead::Scan(unsigned short stepAngle) {
	servo.Rotate(0, 0);

	for (int angle = 0; angle <= 180; angle+=stepAngle)
	{
		servo.Rotate(angle);

	}
}

} /* namespace Components */
