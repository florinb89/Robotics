#include "HeadComponent.h"

namespace Components
{
	HeadComponent::HeadComponent()
	{
		isInitialized = false;
		hasCallback = false;
	}


	HeadComponent::~HeadComponent()
	{
	}

	HeadComponent::HeadComponent(ServoMechanism servo, HCSR04Ultrasonic sensor, LED led, unsigned short minDetectDistance = 0, unsigned short maxDetectDistance = 400)
	{
		this->servo = servo;
		this->sensor = sensor;
		this->led = led;
		
		this->minDetectDistance = minDetectDistance;
		this->maxDetectDistance = maxDetectDistance;
	}

	void HeadComponent::StartScanning(unsigned short step){}
	void HeadComponent::Scan(){}
	void HeadComponent::StopScanning(){}
	void HeadComponent::RegisterCallback(void(*callback)(double distance))
	{
		this->callback = callback;
		hasCallback = true;
	}

}


