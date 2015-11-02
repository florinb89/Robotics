#ifndef _HEADCOMPONENT_
#define _HEADCOMPONENT_

#include "ServoMechanism.h"
#include "HCSR04Ultrasonic.h"
#include "LED.h"

using namespace Sensors;
using namespace Actuators;

namespace Components
{
	class HeadComponent{
	private:
		ServoMechanism servo;
		HCSR04Ultrasonic sensor;
		LED led;
		void(*callback)(double distance);

		bool isInitialized;
		bool hasCallback;
		unsigned short minDetectDistance;
		unsigned short maxDetectDistance;

		unsigned short step;
		unsigned short currentAngle;
	public:
		HeadComponent();
		HeadComponent(ServoMechanism servo, HCSR04Ultrasonic sensor, LED led, unsigned short minDetectDistance = 0, unsigned short maxDetectDistance = 400);
		~HeadComponent();

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