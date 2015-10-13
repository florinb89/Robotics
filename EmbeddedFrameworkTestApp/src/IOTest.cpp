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
	cout << "Digital Write port: " << port << "value: " << value;
}

} /* namespace IO */
