#ifndef ROBOTFRAMEWORK_L298MOTORSHIELD_H
#define ROBOTFRAMEWORK_L298MOTORSHIELD_H

#include "Pin.h"
#include "Motor.h"

namespace RobotFramework
{
	#define MOTOR2_PIN1 3
	#define MOTOR2_PIN2 5
	#define MOTOR1_PIN1 6
	#define MOTOR1_PIN2 9

	class L298MotorShield
	{
	public:
		L298MotorShield(PinWriter<int>* pinWriter);
		~L298MotorShield();

		void Motor1Forward(int speed);
		void Motor1Backward(int speed);
		void Motor1Break();

		void Motor2Forward(int speed);
		void Motor2Backward(int speed);
		void Motor2Break();

	private:
		PinWriter<int>* pinWriter;
		DCMotor motor1;
		DCMotor motor2;
		
		void InitializeMotors();
		void WritePort(unsigned char port, int data);
	};
};

#endif
