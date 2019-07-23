#ifndef __FAGENT_H__
#define __FAGENT_H__

#include <string>

#include "IDynamicLoader.h"
#include "ISubManager.h"
#include "IEventPublish.h"
#include "AgentData.h"
#include "Agent.h"
#include "common.h"

template<class T>
class FAgent:private Ucopyable
{
public:
	FAgent(IDynamicLoader<T>& _loader);
	Agent* newAgent(const AgentData& _data, ISubManager& _subManager, IEventPublish& _eventPublish)const;
private:
	IDynamicLoader<T>& m_loader;
};

#include "FAgent.hpp"

#endif //__FAGENT_H__
