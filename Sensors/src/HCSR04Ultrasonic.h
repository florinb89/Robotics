/*
 * HCSR04Ultrasonic.h
 *
 *  Created on: Oct 14, 2015
 *      Author: florin
 */

#ifndef SRC_HCSR04ULTRASONIC_H_
#define SRC_HCSR04ULTRASONIC_H_

#include "PortCommunication.h"

using namespace Communication;

namespace Sensors {

class HCSR04Communication
{
private:
	PortCommunication trigger;
	PortCommunication pulse;
	void (*delay)(unsigned short value);
public:
	HCSR04Communication(PortCommunication trigger, PortCommunication pulse, void (*delay)(unsigned short));
};

class HCSR04Ultrasonic {
private:
	PortCommunication portCommunication;
	bool isInitialized;
	HCSR04Communication communication;
	unsigned short port;
public:
	HCSR04Ultrasonic();
	HCSR04Ultrasonic(unsigned short port, HCSR04Communication hcsr04Communication);
	virtual ~HCSR04Ultrasonic();

};

} /* namespace Sensors */

#endif /* SRC_HCSR04ULTRASONIC_H_ */
