/*
 * ServoMechanismTest.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: florin
 */

#include "ServoMechanismTest.h"
#include "ServoMechanism.h"
#include "IOTest.h"

using namespace IO;
using namespace Actuators;

namespace Test {

ServoMechanismTest::ServoMechanismTest() {
	// TODO Auto-generated constructor stub

}

ServoMechanismTest::~ServoMechanismTest() {
	// TODO Auto-generated destructor stub
}


void ServoMechanismTest::TestServoMechanismRotate() {
	IOTest io;
	ServoMechanism servoMechanism(&io.ServoWrite, &io.Delay, 0, 180);
	servoMechanism.Rotate(30, 40);
}

} /* namespace Test */
