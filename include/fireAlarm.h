#ifndef __FIREALARM_H__
#define __FIREALARM_H__

#include "Agent.h"

class FireAlarm:public Agent
{
public:
	static Agent*Create(ISubManager& _subManager, IEventPublish& _eventPublish);
	FireAlarm(ISubManager& _subManager, IEventPublish& _eventPublish);
	~FireAlarm(){}
	virtual	void 		Init(const AgentData& _data);
    virtual void		Destroy();
    virtual void		Connect();
    virtual void		GetEvent(shared_ptr<Event> _event);
};

#endif //__FIREALARM_H__
