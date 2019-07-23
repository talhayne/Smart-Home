#ifndef __SUBMANAGER_H__
#define __SUBMANAGER_H__

#include <set>
#include <map>

#include "common.h"
#include "EventKey.h"
#include "ISubManager.h"
#include "ISubLookUp.h"

class Agent;

class SubManager:public ISubLookUp, public ISubManager
{
public:
	void RemoveSubscriber(Agent*_agent, const EventKey& _key);
	void AddSubscriber(Agent*_agent, const EventKey& _key);
	const std::set<Agent*>& GetSubAgents(const EventKey& _key);
private:
	std::map<const EventKey, std::set<Agent*> > m_subContainer;
};

#endif //__SUBMANAGER_H__
