#include "ServoMechanism.h"
#include "HCSR04Ultrasonic.h"

/*#include "../arduino/Arduino.h"*/
#include "Arduino.h"

#define NECK_SERVO_PIN 10
#define NECK_ULTRASONIC_TRIGGER_PIN 8
#define NECK_ULTRASONIC_PULSE_PIN 7
#define FRONT_LED_PIN 13

using namespace Sensors;
using namespace Actuators;

int maximumRange = 40; // Maximum range needed
int minimumRange = 20; // Minimum range needed
long distance; // Duration used to calculate distance

unsigned long Pulse(unsigned short pin, unsigned short value);
void DigitalWrite(unsigned short pin, unsigned short value);
void DelayMicroseconds(unsigned int value);

HCSR04Communication ultrasonicComm(&DigitalWrite, &Pulse, &DelayMicroseconds);
HCSR04Ultrasonic neckSenzor(NECK_ULTRASONIC_TRIGGER_PIN, NECK_ULTRASONIC_PULSE_PIN, ultrasonicComm);

void setup()
{
	Serial.begin (9600);
	pinMode(NECK_SERVO_PIN, OUTPUT);
	pinMode(NECK_ULTRASONIC_TRIGGER_PIN, OUTPUT);
	pinMode(NECK_ULTRASONIC_PULSE_PIN, INPUT);
	pinMode(FRONT_LED_PIN, OUTPUT);
}

void loop()
{
	distance = neckSenzor.Read();
	if (distance <= maximumRange && distance >= minimumRange)
	{
		digitalWrite(FRONT_LED_PIN, HIGH);

	}
	else
	{
		digitalWrite(FRONT_LED_PIN, LOW);

	}

	delay(50);
}

unsigned long Pulse(unsigned short pin, unsigned short value)
{
	long val =  pulseIn(pin, value);
	return val;
}

void DigitalWrite(unsigned short pin, unsigned short value){

	digitalWrite(pin, value);

}

void DelayMicroseconds(unsigned int value)
{

	delayMicroseconds(value);
}
