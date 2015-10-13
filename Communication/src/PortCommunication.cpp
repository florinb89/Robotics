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
	isInitialized = false;
}

PortCommunication::~PortCommunication() {
	// TODO Auto-generated destructor stub
}

PortCommunication::PortCommunication(void (*writeFunction)(unsigned short pin, unsigned short value)) {
	this->writeFunction = writeFunction;
	isInitialized = true;
}

void PortCommunication::Send(PortMessage message) {
	if (isInitialized)
		this->writeFunction(message.GetPort(), message.GetData());


}

}

/* namespace Communcation */
