#include "Motor.h"

namespace RobotFramework
{
	DCMotor::DCMotor()
	{
		
	};

	DCMotor::~DCMotor(){};

	DCMotorParameters DCMotor::GetParameters()
	{
		return this->motorParameters;
	};

	void DCMotor::SetParameters(DCMotorParameters parameters)
	{
		this->motorParameters.PortA = parameters.PortA;
		this->motorParameters.PortB = parameters.PortB;
	};
}
