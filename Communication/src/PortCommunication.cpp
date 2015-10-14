/*
 * PortCommunication.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: florin
 */

#include "PortCommunication.h"
#include "PortMessage.h"

namespace Communication {

PortCommunication::PortCommunication() {
	canRead = false;
	canWrite = false;
}

PortCommunication::~PortCommunication() {
	// TODO Auto-generated destructor stub
}

PortCommunication::PortCommunication(void (*writeFunction)(unsigned short pin, unsigned short value)) {
	this->writeFunction = writeFunction;
	canWrite = true;
}

PortCommunication::PortCommunication(unsigned short (*readFunction)(unsigned short)){
	this->readFunction = readFunction;
	canRead = true;
}

PortCommunication::PortCommunication(void (*writeFunction)(unsigned short, unsigned short), unsigned short (*readFunction)(unsigned short)){
	this->writeFunction = writeFunction;
	this->readFunction = readFunction;
	canRead = true;
	canWrite = true;
}

PortMessage PortCommunication::Read(unsigned short port)
{
	unsigned short value = 0;
	PortMessage portMessage;
	portMessage.SetPort(port);

	if (canRead)
	{
		value = readFunction(port);

	}
	portMessage.SetData(value);

	return portMessage;
}

void PortCommunication::Send(PortMessage message) {
	if (canWrite)
		this->writeFunction(message.GetPort(), message.GetData());


}

}

/* namespace Communication */
