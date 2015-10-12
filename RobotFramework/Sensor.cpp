#include "Pin.h"
#include "Sensor.h"

namespace RobotFramework
{
	DetectionSensor::DetectionSensor(unsigned char sensorPort, PinReader<int>* pinReader)
	{
		this->pinReader = pinReader;
		this->sensorPort = sensorPort;
	}

	DetectionSensor::~DetectionSensor(){}

	DigitalSharp::DigitalSharp(unsigned char sensorPort, PinReader<int>* pinReader) : DetectionSensor(sensorPort, pinReader)
	{
		
	}

	DigitalSharp::~DigitalSharp(){}

	bool DigitalSharp::IsDetected()
	{
		int readData = pinReader->Read(sensorPort);

		if (readData <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}