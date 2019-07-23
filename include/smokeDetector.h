#ifndef __SMOKEDETECTOR_H__
#define __SMOKEDETECTOR_H__

#include "Agent.h"
#include "SharedPtr.h"

class SmokeDetector:public Agent
{
public:
	static Agent* Create(ISubManager& _subManager, IEventPublish& _eventPublish);
	SmokeDetector(ISubManager& _subManager, IEventPublish& _eventPublish);
	~SmokeDetector(){}
	virtual	void 		Init(const AgentData& _data);
    virtual void		Destroy();
    virtual void		Connect();
    virtual void		GetEvent(shared_ptr<Event> _event);
};

#endif //__SMOKEDETECTOR_H__
