#ifndef ROBOTFRAMEWORK_MOTOR_H
#define ROBOTFRAMEWORK_MOTOR_H

namespace RobotFramework
{
	class DCMotorParameters
	{
	public:
		unsigned char PortA;
		unsigned char PortB;
	};

	class DCMotor
	{
	public:
		DCMotor();
		~DCMotor();

		DCMotorParameters GetParameters();
		void SetParameters(DCMotorParameters parameters);

	private:
		DCMotorParameters motorParameters;
	};


}


#endif