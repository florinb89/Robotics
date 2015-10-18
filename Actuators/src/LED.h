/*
 * LED.h
 *
 *  Created on: Oct 18, 2015
 *      Author: florin
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_

namespace Actuators {

class LED {
private :
	bool isOn;
	void (*pinWrite)(unsigned short, unsigned short);
	unsigned short port;
public:
	LED();
	LED(unsigned short port, void(*pinWrite)(unsigned short pin, unsigned short value));
	virtual ~LED();
	void TurnOn();
	void TurnOff();
	bool IsOn();
};

} /* namespace Actuators */

#endif /* SRC_LED_H_ */
