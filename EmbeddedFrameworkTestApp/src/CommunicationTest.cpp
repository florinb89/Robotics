/*
 * CommunicationTest.cpp
 *
 *  Created on: Oct 14, 2015
 *      Author: florin
 */

#include "CommunicationTest.h"
#include "PortCommunication.h"
#include "PortMessage.h"
#include "IOTest.h"

using namespace IO;

namespace Test {

CommunicationTest::CommunicationTest() {
	// TODO Auto-generated constructor stub

}

CommunicationTest::~CommunicationTest() {
	// TODO Auto-generated destructor stub
}

void CommunicationTest::PortSendTest(unsigned short port,
		unsigned short value) {
	IOTest io;
	Communication::PortCommunication comm(&io.DigitalWrite);
	Communication::PortMessage message;
	message.SetPort(port);
	message.SetData(value);
	comm.Send(message);

}

void CommunicationTest::PortReadTest(unsigned short port)
{
	IOTest io;
	Communication::PortCommunication comm(&io.DigitalRead);
	Communication::PortMessage message = comm.Read(10);

}

} /* namespace Test */
