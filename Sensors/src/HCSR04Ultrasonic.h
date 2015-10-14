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

class HCSR04Ultrasonic {
private:
	PortCommunication portCommunication;

public:
	HCSR04Ultrasonic();
	HCSR04Ultrasonic(unsigned short port, PortCommunication portCommunication);
	virtual ~HCSR04Ultrasonic();
};

} /* namespace Sensors */

#endif /* SRC_HCSR04ULTRASONIC_H_ */
