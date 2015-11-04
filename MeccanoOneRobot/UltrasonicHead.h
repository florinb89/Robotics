#ifndef _UltrasonicHead_
#define _UltrasonicHead_

#include "ServoMechanism.h"
#include "HCSR04Ultrasonic.h"
#include "LED.h"

#define DIRECTION_LEFT 0
#define DIRECTION_RIGHT 1

using namespace Sensors;
using namespace Actuators;

namespace Components
{
	class UltrasonicHead{
	private:
		ServoMechanism servo;
		HCSR04Ultrasonic sensor;
		LED led;
		void(*callback)(double distance);

		bool isInitialized;
		bool isScanning;
		bool hasCallback;
		unsigned short minDetectDistance;
		unsigned short maxDetectDistance;

		unsigned short step;
		unsigned short currentAngle;
		unsigned short direction;

		unsigned short GetRotationAngle();
		double SensorScan();


	public:
		UltrasonicHead();
		UltrasonicHead(ServoMechanism servo, HCSR04Ultrasonic sensor, LED led, unsigned short minDetectDistance = 0, unsigned short maxDetectDistance = 400);
		~UltrasonicHead();

		void StartScanning(unsigned short step);
		void Scan();
		void StopScanning();
		void RegisterCallback(void(*callback)(double distance));

		bool IsInitialized() const
		{
			return isInitialized;
		}
	};
}

#endif