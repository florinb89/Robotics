#include "UltrasonicHead.h"

namespace Components
{
	UltrasonicHead::UltrasonicHead()
	{
		isInitialized = false;
		hasCallback = false;
	}


	UltrasonicHead::~UltrasonicHead()
	{
	}

	UltrasonicHead::UltrasonicHead(ServoMechanism servo, HCSR04Ultrasonic sensor, LED led, unsigned short minDetectDistance, unsigned short maxDetectDistance)
	{
		this->servo = servo;
		this->sensor = sensor;
		this->led = led;

		this->minDetectDistance = minDetectDistance;
		this->maxDetectDistance = maxDetectDistance;
	}

	void UltrasonicHead::StartScanning(unsigned short step){
		this->step = step;
		isScanning = true;

		servo.Rotate(0, 20);
		direction = DIRECTION_RIGHT; // to 180
	}
	void UltrasonicHead::Scan(){
		if (isScanning){
			currentAngle = GetRotationAngle();

			servo.Rotate(currentAngle, 0);
			

			double distance = SensorScan();

			if (hasCallback)
				callback(distance);


		}
	}
	void UltrasonicHead::StopScanning(){
		isScanning = false;
	}
	void UltrasonicHead::RegisterCallback(void(*callback)(double distance))
	{
		this->callback = callback;
		hasCallback = true;
	}

	unsigned short UltrasonicHead::GetRotationAngle(){
		//to 0 LEFT
		unsigned short angle = currentAngle;
		if (direction == DIRECTION_LEFT){
			angle = currentAngle - step;
			if (angle <= servo.GetMinAngle())
			{
				direction = DIRECTION_RIGHT;
				return servo.GetMinAngle();
			}
			else
			{
				return angle;
			}
		}
		else{
			angle = currentAngle + step;
			if (angle >= servo.GetMaxAngle())
			{
				direction = DIRECTION_LEFT;
				return servo.GetMaxAngle();;
			}
			else
			{
				return angle;
			}
		}
		
		
	}
	double UltrasonicHead::SensorScan(){
		double distance = sensor.Read();

		if (distance > minDetectDistance && distance < maxDetectDistance){
			led.TurnOn();
		}
		else{
			led.TurnOff();
		}

		return distance;
	}

}


