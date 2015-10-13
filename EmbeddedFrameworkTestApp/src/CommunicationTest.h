/*
 * CommuncationTest.h
 *
 *  Created on: Oct 13, 2015
 *      Author: florin
 */

#ifndef COMMUNICATIONTEST_H_
#define COMMUNICATIONTEST_H_

namespace Test {

class CommunicationTest {
public:
	CommunicationTest();
	virtual ~CommunicationTest();
    void TestPortWrite(unsigned short pin, unsigned short value);
};

}

#endif /* TEST_H_ */
