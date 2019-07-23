#ifndef __SETUP_H__
#define __SETUP_H__

#include <string>

#include "common.h"
#include "ISubManager.h"
#include "IEventPublish.h"
#include "AgentsContainer.h"

class SetUp:private Ucopyable
{
public:
	SetUp(const std::string& _configFile, ISubManager& _subManager, IEventPublish& _eventPublish);
	void Connect();
private:
	AgentsContainer m_agents;
};

#endif //__SETUP_H__
