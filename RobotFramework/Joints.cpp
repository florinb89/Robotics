#include "Joints.h"

namespace RobotFramework
{
	//Servo
	JointServo::JointServo(){
		min = 0;
		max = 180;
		currentValue = 0;
	}

	JointServo::~JointServo(){}

	JointServo::JointServo(bool isInverseRotation, int servoId, void (*write)(int value), void (*delay)(unsigned int value))
	{
		min = 0;
		max = 180;
		this->isInverseRotation = isInverseRotation;
		this->delay = delay;
		this->write = write;
		currentValue = 0;
		this->servoId = servoId;
	}

	void JointServo::ApplyCommand(ServoCommand command, int delay){
		if (command.ServoId == this->servoId && command.CommandId != ServoCommand::NONE){
			if (command.CommandId == ServoCommand::RESET){
				Rotate(0, delay);
			}
			if (command.CommandId == ServoCommand::ROTATE){
				Rotate(command.CommandValue, delay);
			}
		}
	}
	
	void JointServo::Rotate(int angle, int delay)
	{
		if (angle != currentValue)
		{
			if (!IsBetweenRange(angle))
			return;

			if (isInverseRotation)
				write(max-angle);
			else
				write(angle);
			this->delay(delay);

			this->currentValue = angle;
		}
		
	}

	bool JointServo::IsBetweenRange(int angle)
	{
		if (angle >= min && angle <= max)
			return true;
		return false;
	}

	//Servo END

	//Joint

	Joint::Joint(){}
	Joint::~Joint(){}

	Joint::Joint(void (*delayFunction)(unsigned int delay), JointServo servoMotors[3], int servoCount)
	{
		this->servoCount = servoCount;
		
		for (int i=0; i < servoCount; i++)
		{
			this->servoMotors[i] = servoMotors[i];
		}

		this->delayFunction = delayFunction;

	}

	void Joint::Initialize(void (*delayFunction)(unsigned int delay), JointServo servos[3], int noOfServos)
	{
		this->servoCount = noOfServos;
		
		for (int i=0; i < servoCount; i++)
		{
			this->servoMotors[i] = servos[i];
		}

		this->delayFunction = delayFunction;

	}

	void Joint::Rotate(int angle, int delay)
	{
		for (int i=0; i < this->servoCount; i++){
			//servoMotors[i].Rotate(angle,0);
		}

		delayFunction(delay);
	}

	//Joint END

}
