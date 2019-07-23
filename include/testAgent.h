#ifndef __TESTAGENT_H__
#define __TESTAGENT_H__

#include "Agent.h"
#include "SharedPtr.h"

class TestAgent:public Agent
{
public:
	static Agent* Create(ISubManager& _subManager, IEventPublish& _eventPublish);
	TestAgent(ISubManager& _subManager, IEventPublish& _eventPublish);
	~TestAgent(){}
	virtual	void 		Init(const AgentData& _data);
    virtual void		Destroy();
    virtual void		Connect();
    virtual void		GetEvent(shared_ptr<Event> _event);
};

#endif //__TESTAGENT_H__
