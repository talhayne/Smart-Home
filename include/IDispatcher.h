#ifndef __IDISPATCHER_H__
#define __IDISPATCHER_H__

#include <set>

#include "common.h"
#include "SharedPtr.h"
#include "Agent.h"
#include "SharedPtr.h"

class IDispatcher:private Ucopyable
{
public:
	virtual ~IDispatcher() = 0;
	virtual void Work(const std::set<Agent*>& _agents, shared_ptr<Event> _event)const = 0;
};

#endif //__IDISPATCHER_H__
