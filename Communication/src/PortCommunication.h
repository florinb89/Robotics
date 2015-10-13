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
	bool isInitialized;
	void (*writeFunction)(unsigned short,unsigned short);
public:
	PortCommunication();
	PortCommunication(void (*writeFunction)(unsigned short, unsigned short));
	virtual ~PortCommunication();
	void Send(PortMessage message);
};

} /* namespace Communcation */

#endif /* PORTCOMMUNICATION_H_ */
