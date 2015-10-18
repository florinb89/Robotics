/*
 * ServoMotor.h
 *
 *  Created on: Oct 11, 2015
 *      Author: florin
 */

#ifndef SRC_SERVOMOTOR_H_
#define SRC_SERVOMOTOR_H_

namespace Actuators {

class ServoMotor {
private:
	void (*servoWrite)(unsigned int value);
	bool isInitialized;
	unsigned int currentAngle;
public:
	ServoMotor();
	ServoMotor(void (*writeFunction)(unsigned int value));
	void Rotate(unsigned int value);
	bool IsInitialized();
	virtual ~ServoMotor();
};

}

#endif /* SRC_SERVOMOTOR_H_ */
