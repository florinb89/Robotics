#ifndef ROBOTFRAMEWORK_SERVOMESSAGEPARSER_H
#define ROBOTFRAMEWORK_SERVOMESSAGEPARSER_H

#define SERVO_RESET 1
#define SERVO_ANGLE 2 
#define SERVO_NONE 3
#define COMMAND_END '#'
#define COMMAND_TOKEN_END ','

//command 0,126#

namespace RobotFramework
{
	class ServoCommand
	{
	public:
		int CommandId;
		int CommandValue;
		int ServoId;

		ServoCommand();
		ServoCommand(int servoId, int commandId, int value);

		static const int RESET = SERVO_RESET;
		static const int ROTATE = SERVO_ANGLE;
		static const int NONE = SERVO_NONE;
	};

	class ServoMessageParser
	{
	public:
		static const int MaxServos = 20;

		ServoMessageParser(int (*atoiFunction)(char* command));
		ServoCommand ParseCommand(char* command);
		void ParseMultipleCommands(char* commandLine, ServoCommand commands[MaxServos], int* count);

	private:
		int (*atoiFunction)(char* command);
	};
};

#endif

