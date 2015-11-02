/*
 * ServoMechanism.h
 *
 *  Created on: Oct 11, 2015
 *      Author: florin
 */

#ifndef SRC_SERVOMECHANISM_H_
#define SRC_SERVOMECHANISM_H_

#include "ServoMotor.h"

namespace Actuators {

class ServoMechanism {
private:
ServoMotor servoMotor;
void (*delayFunction)(unsigned int);
unsigned int minAngle;
unsigned int maxAngle;
public:
	ServoMechanism();
	ServoMechanism(void (*servoWrite)(unsigned int), void (*delayFunction)(unsigned int), unsigned int minAngle, unsigned int maxAngle);
    virtual ~ServoMechanism();
	void Rotate(unsigned int angle, unsigned int delay);

	unsigned int GetMinAngle() const
	{
		return minAngle;
	}

	unsigned int GetMaxAngle()
	{
		return maxAngle;
	}
};

}

#endif /* SRC_SERVOMECHANISM_H_ */
