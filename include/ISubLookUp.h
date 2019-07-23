#ifndef __ISUBLOOKUP_H__
#define __ISUBLOOKUP_H__

#include <set>

#include "common.h"
#include "EventKey.h"

class Agent;

class ISubLookUp:private Ucopyable
{
public:
	virtual ~ISubLookUp() = 0;
	virtual const std::set<Agent*>& GetSubAgents(const EventKey& _key) = 0;
};

#endif //__ISUBLOOKUP_H__
