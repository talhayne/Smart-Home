#include <iostream>

#include "AgentData.h"
#include "Parser.h"

int main()
{
	Parser myParser("config.txt");
	bool retVal = 1;
	
	while(retVal)
	{
		AgentData newAgentData;
		retVal = myParser.ParserLines(newAgentData);
		if(retVal)
		{
			newAgentData.Print();
		}
	}
	return 0;
}
