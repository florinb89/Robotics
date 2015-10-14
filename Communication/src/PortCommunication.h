/*
 * PortCommunication.h
 *
 *  Created on: Oct 13, 2015
 *      Author: florin
 */

#ifndef PORTCOMMUNICATION_H_
#define PORTCOMMUNICATION_H_

#include "PortMessage.h"

namespace Communication {

class PortCommunication {
private:
	bool canRead;
	bool canWrite;
	void (*writeFunction)(unsigned short,unsigned short);
	unsigned short (*readFunction)(unsigned short);
public:
	PortCommunication();
	PortCommunication(void (*writeFunction)(unsigned short, unsigned short));
	PortCommunication(unsigned short (*readFunction)(unsigned short));
	PortCommunication(void (*writeFunction)(unsigned short, unsigned short), unsigned short (*readFunction)(unsigned short));
	virtual ~PortCommunication();
	void Send(PortMessage message);
	PortMessage Read(unsigned short port);
};

} /* namespace Communication */

#endif /* PORTCOMMUNICATION_H_ */
