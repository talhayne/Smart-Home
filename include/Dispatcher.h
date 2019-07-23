#ifndef __DISPATCHER_H__
#define __DISPATCHER_H__

#include <set>

#include "IDispatcher.h"
#include "SharedPtr.h"
#include "Agent.h"
#include "common.h"

class Dispatcher:public IDispatcher
{
public:
	virtual void Work(const std::set<Agent*>& _agents, shared_ptr<Event> _event)const;
};

#endif //__DISPATCHER_H__
