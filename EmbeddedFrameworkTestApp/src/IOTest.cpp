/*
 * IOTest.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: florin
 */

#include "IOTest.h"
#include <iostream>

using namespace std;

namespace IO {

IOTest::IOTest() {
	// TODO Auto-generated constructor stub

}

IOTest::~IOTest() {
	// TODO Auto-generated destructor stub
}

void IOTest::ServoWrite(unsigned int angle) {
	cout << "Servo write angle: " << angle << endl;
}

void IOTest::Delay(unsigned int delay) {
	cout << "Delay value: " << delay << endl;
}

void IOTest::DigitalWrite(unsigned short port, unsigned short value) {
	cout << "Digital Write port: " << port << " value: " << value << endl;
}

unsigned short IOTest::DigitalRead(unsigned short port){
	unsigned short testValue = 100;
	cout << "Digital Read port: " << port << " value: " << testValue << endl;
	return testValue;

}

unsigned long IOTest::PulseIn(unsigned short pin, unsigned short value) {
	unsigned long duration = 34;
	cout << "Pulse in port: " << pin << " value: " << value << endl;
	return duration;
}

} /* namespace IO */


