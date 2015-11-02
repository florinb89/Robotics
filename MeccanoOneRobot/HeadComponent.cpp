#include "HeadComponent.h"


HeadComponent::HeadComponent()
{
}


HeadComponent::~HeadComponent()
{
}

HeadComponent::HeadComponent(ServoMechanism servo, HCSR04Ultrasonic sensor, LED led, unsigned short minDetectDistance = 0, unsigned short maxDetectDistance = 400){}

void HeadComponent::StartScanning(unsigned short step){}
void HeadComponent::Scan(){}
void HeadComponent::StopScanning(){}
void HeadComponent::RegisterCallback(void(*callback)){}

