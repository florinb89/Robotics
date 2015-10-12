

#include "ServoMessageParser.h"
#include "StringUtils.h"


namespace RobotFramework
{
	ServoCommand::ServoCommand(){};

	ServoCommand::ServoCommand(int servoId, int commandId, int value)
	{
		this->CommandId = commandId;
		this->CommandValue = value;
		this->ServoId = servoId;
	};

	ServoMessageParser::ServoMessageParser(int (*atoi)(char* message)){
		this->atoiFunction = atoi;
	}

	ServoCommand ServoMessageParser::ParseCommand(char* commandString){
		
		char tokens[MAX_TOKEN_LENGTH][MAX_TOKEN_LENGTH];
	
		const char separators[] = {COMMAND_TOKEN_END, COMMAND_END, '\0'};
		unsigned short tokensCount;
		unsigned short count;
		StringUtils::Split(commandString, separators, tokens, &count);

		if (count == 3){
			int servoId = atoiFunction(tokens[0]);
			int commandId = atoiFunction(tokens[1]);
			int value = atoiFunction(tokens[2]);

			ServoCommand command(servoId, commandId, value);

			return command;
		}
		else
		{
			ServoCommand command(ServoCommand::NONE,0,0);
			return command;
		}
		
	};

	void ServoMessageParser::ParseMultipleCommands(char* message, ServoCommand commands[MaxServos], int* count){
		
		unsigned short commandsCount = 0;
	    
		char tokens[MAX_TOKEN_LENGTH][MAX_TOKEN_LENGTH];
	
		const char separators[] = {COMMAND_END, '\0'};
	
		StringUtils::Split(message, separators, tokens, &commandsCount);

		for (int i=0; i < commandsCount; i++){
			commands[i] = ParseCommand(tokens[i]);
		}
		
		*count = commandsCount;

	};
};