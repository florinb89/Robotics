/*
 * HCSR04Ultrasonic.h
 *
 *  Created on: Oct 14, 2015
 *      Author: florin
 */

#ifndef SRC_HCSR04ULTRASONIC_H_
#define SRC_HCSR04ULTRASONIC_H_

namespace Sensors {

class HCSR04Communication;
class HCSR04Ultrasonic;

class HCSR04Communication
{
private:
void (*triggerFunction) (unsigned short, unsigned short);
unsigned long (*pulseFunction)(unsigned short, unsigned short);
void (*delay)(unsigned int);

public:
    HCSR04Communication();
	HCSR04Communication(void (*triggerFunction)(unsigned short pin,unsigned short value),
			unsigned long (*pulseFunction)(unsigned short pin, unsigned short value),
	void (*delay)(unsigned int));
	virtual ~HCSR04Communication();
	unsigned long Pulse(unsigned short echoPin);
	void Trigger(unsigned short triggerPin, bool value);
	void Delay(unsigned short);
};

class HCSR04Ultrasonic {
private:
	bool isInitialized;
	HCSR04Communication communication;
	unsigned short triggerPort;
	unsigned short pulsePort;
public:
	HCSR04Ultrasonic();
	HCSR04Ultrasonic(unsigned short triggerPort, unsigned short pulsePort, HCSR04Communication hcsr04Communication);
	virtual ~HCSR04Ultrasonic();
	double Read();

};

} /* namespace Sensors */

#endif /* SRC_HCSR04ULTRASONIC_H_ */
