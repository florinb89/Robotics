#include "L298MotorShield.h"
#include "Pin.h"
#include "Motor.h"

namespace RobotFramework
{
	L298MotorShield::L298MotorShield(PinWriter<int>* pinWriter)
	{
		this->pinWriter = pinWriter;
		InitializeMotors();
	};

	L298MotorShield::~L298MotorShield(){};

	void L298MotorShield::Motor1Forward(int speed)
	{
		DCMotorParameters parameters = motor1.GetParameters();

		WritePort(parameters.PortA, speed);
	    WritePort(parameters.PortB, 0);
	};

	void L298MotorShield::Motor2Forward(int speed)
	{
		DCMotorParameters parameters = motor2.GetParameters();

		WritePort(parameters.PortA, speed);
	    WritePort(parameters.PortB, 0);
	};

	void L298MotorShield::Motor1Backward(int speed)
	{
		DCMotorParameters parameters = motor1.GetParameters();

		WritePort(parameters.PortA, 0);
	    WritePort(parameters.PortB, speed);
	};

	void L298MotorShield::Motor2Backward(int speed)
	{
		DCMotorParameters parameters = motor2.GetParameters();

		WritePort(parameters.PortA, 0);
	    WritePort(parameters.PortB, speed);
	};

	void L298MotorShield::Motor1Break()
	{
		DCMotorParameters parameters = motor1.GetParameters();

		WritePort(parameters.PortA, 0);
	    WritePort(parameters.PortB, 0);
	};

	void L298MotorShield::Motor2Break()
	{
		DCMotorParameters parameters = motor2.GetParameters();

		WritePort(parameters.PortA, 0);
	    WritePort(parameters.PortB, 0);
	};

	void L298MotorShield::InitializeMotors()
	{
		DCMotorParameters motorParameters;
		motorParameters.PortA = MOTOR1_PIN1;
		motorParameters.PortB = MOTOR1_PIN2;

		this->motor1.SetParameters(motorParameters);

		motorParameters.PortA = MOTOR2_PIN2;
		motorParameters.PortB = MOTOR2_PIN1;

		this->motor2.SetParameters(motorParameters);
	};

	void L298MotorShield::WritePort(unsigned char port, int data)
	{
		this->pinWriter->Write(port, data);
	};
};