#ifndef ROBOTFRAMEWORK_JOINTS_H
#define ROBOTFRAMEWORK_JOINTS_H

#include "ServoMessageParser.h"

namespace RobotFramework
{

	typedef void (*writeFunction)(int value);
	typedef void (*delayFunction)(unsigned int delay);

	class JointServo
	{
	private:
		bool isInverseRotation;
		int currentValue;
		void (*write)(int value);
		void (*delay)(unsigned int delay);
		int min, max;
		int servoId;
	


	public:
		JointServo();
		~JointServo();
		JointServo(bool isInverseRotation, int servoId, void (*writeFunction)(int value), void (*delayFunction)(unsigned int delay));
		void ApplyCommand(ServoCommand command, int delay = 0);
		void Rotate(int angle, int delay);

	private:
		bool IsBetweenRange(int angle);
		
	};

	class Joint
	{

	private:
		JointServo servoMotors[3];
		void (*delayFunction)(unsigned int delay);
		int servoCount;

	public:
		Joint();
		~Joint();
		Joint(void (*delayFunction)(unsigned int delay), JointServo servoMotors[3], int servoCount);
		void Rotate(int angle, int delay); 
		void Initialize(void (*delayFunction)(unsigned int delay), JointServo servoMotors[3], int servoCount);
		void Reset(int angle);

	};

};

#endif