#ifndef ROBOTFRAMEWORK_STRINGUTILS_H
#define ROBOTFRAMEWORK_STRINGUTILS_H

#include <string.h>
#define MAX_TOKEN_LENGTH 100

namespace RobotFramework
{
	class StringUtils
	{
	public:
		static void Split(char* value, const char* delimiters, char buffer[][MAX_TOKEN_LENGTH], unsigned short* tokensCount);
	
	};

};



#endif