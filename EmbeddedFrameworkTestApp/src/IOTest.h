/*
 * IOTest.h
 *
 *  Created on: Oct 12, 2015
 *      Author: florin
 */

#ifndef IOTEST_H_
#define IOTEST_H_

namespace IO {

class IOTest {
public:
	IOTest();
	virtual ~IOTest();
	static void ServoWrite(unsigned int angle);
	static void Delay(unsigned int delay);
	static void DigitalWrite(unsigned short port, unsigned short value);
	static unsigned short DigitalRead(unsigned short port);
	static unsigned long PulseIn(unsigned short pin, unsigned short value);
};

} /* namespace IO */

#endif /* IOTEST_H_ */
