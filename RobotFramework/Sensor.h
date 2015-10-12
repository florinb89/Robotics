#ifndef ROBOTFRAMEWORK_SENSOR_H
#define ROBOTFRAMEWORK_SENSOR_H

#include "Pin.h"

namespace RobotFramework
{
	class DetectionSensor
	{
	protected:
		unsigned char sensorPort;
		PinReader<int>* pinReader;
	public:
		DetectionSensor(unsigned char sensorPort, PinReader<int>* pinReader);
		~DetectionSensor();

		virtual bool IsDetected() = 0;
	private:

	};

	class DigitalSharp : public DetectionSensor
	{
	public:
		DigitalSharp(unsigned char sensorPort, PinReader<int>* pinReader);
		~DigitalSharp();

		bool IsDetected();
	};
}

#endif