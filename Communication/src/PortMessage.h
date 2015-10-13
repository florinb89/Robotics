/*
 * PortMessage.h
 *
 *  Created on: Oct 13, 2015
 *      Author: florin
 */

#ifndef PORTMESSAGE_H_
#define PORTMESSAGE_H_

namespace Communication {

class PortMessage {
private:
	unsigned short port;
	unsigned short data;
	bool isSet;
public:
	PortMessage();
	virtual ~PortMessage();

	int GetData() const {
		return data;
	}

	void SetData(int data) {
		this->data = data;
	}

	unsigned short GetPort() const {
		return port;
	}

	void SetPort(unsigned short port) {
		this->port = port;
	}

	int IsSet() const {
			return isSet;
		}
};

} /* namespace Communcation */

#endif /* PORTMESSAGE_H_ */
