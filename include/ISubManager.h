#ifndef __ISUBMANAGER_H__
#define __ISUBMANAGER_H__

#include "common.h"
#include "EventKey.h"

class Agent;

class ISubManager:private Ucopyable
{
public:
	virtual ~ISubManager() = 0;
	virtual void RemoveSubscriber(Agent*_agent, const EventKey& _key) = 0;
	virtual void AddSubscriber(Agent*_agent, const EventKey& _key) = 0;
};

#endif //__ISUBMANAGER_H__
