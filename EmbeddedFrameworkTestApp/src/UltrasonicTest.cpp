/*
 * UltrasonicTest.cpp
 *
 *  Created on: Oct 17, 2015
 *      Author: florin
 */

#include "UltrasonicTest.h"
#include "HCSR04Ultrasonic.h"
#include <iostream>

#include "IOTest.h"

using namespace std;
using namespace IO;
using namespace Sensors;

namespace Test {

UltrasonicTest::UltrasonicTest() {
	// TODO Auto-generated constructor stub

}

UltrasonicTest::~UltrasonicTest() {
	// TODO Auto-generated destructor stub
}

void UltrasonicTest::TestHCSR04Ultrasonic() {
	IOTest io;
	HCSR04Communication communication(&io.DigitalWrite, &io.PulseIn, &io.Delay);
	HCSR04Ultrasonic sensor(10, 20, communication);

	cout << "Distance: " << sensor.Read() << endl;
}

} /* namespace Test */
