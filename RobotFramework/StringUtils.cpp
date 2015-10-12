#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "StringUtils.h"
#include <string.h>


namespace RobotFramework
{
	void StringUtils::Split(char* value, const char* delimiters, char buffer[][100], unsigned short* tokensCount)
	{
		char * pch;
		char* context	= NULL;

		pch = strtok(value,delimiters);
		int count = 0;



		while (pch != NULL)
		{
			strcpy(buffer[count++],pch);

			pch = strtok(NULL, delimiters);

		}

		*tokensCount = count;
	};






};