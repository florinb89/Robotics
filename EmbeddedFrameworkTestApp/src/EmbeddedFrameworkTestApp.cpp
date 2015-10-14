//============================================================================
// Name        : EmbeddedFrameworkTestApp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "ServoMechanismTest.h"
#include "CommunicationTest.h"

using namespace std;
using namespace Test;

int main() {
	ServoMechanismTest servoTest;
	servoTest.TestServoMechanismRotate();

	CommunicationTest comm;
	comm.PortSendTest(10, 500);

	comm.PortReadTest(10);


	return 0;
}
