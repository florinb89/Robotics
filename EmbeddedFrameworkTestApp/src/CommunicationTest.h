/*
 * CommunicationTest.h
 *
 *  Created on: Oct 14, 2015
 *      Author: florin
 */

#ifndef COMMUNICATIONTEST_H_
#define COMMUNICATIONTEST_H_

namespace Test {

class CommunicationTest {
public:
	CommunicationTest();
	virtual ~CommunicationTest();
	void PortSendTest(unsigned short port, unsigned short value);
	void PortReadTest(unsigned short port);
};

} /* namespace Test */

#endif /* COMMUNICATIONTEST_H_ */
