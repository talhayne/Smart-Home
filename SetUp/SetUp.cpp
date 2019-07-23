#include "SetUp.h"
#include "Parser.h"
#include "SoLoader.h"
#include "FAgent.h"
#include "AgentData.h"

SetUp::SetUp(const std::string& _configFile, ISubManager& _subManager, IEventPublish& _eventPublish)
{
	Parser parser(_configFile);
	SoLoader<void*> loader;
	FAgent<void*> agentFactory(loader);
	bool retVal = 1;
	
	while(retVal)
	{
		AgentData newAgentData;
		retVal = parser.ParserLines(newAgentData);
		if(retVal)
		{
			m_agents.addAgent(agentFactory.newAgent(newAgentData, _subManager, _eventPublish));
		}
	}
}

void SetUp::Connect()
{
	std::cout << "start SetUp::Connect" << std::endl;
	try
	{
		m_agents.Connect();
	}
	catch(...)
	{
		throw;
	}
	std::cout << "finish SetUp::Connect" << std::endl;
}



