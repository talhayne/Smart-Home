#ifndef __IAGENT_H__
#define __IAGENT_H__

#include "ISubManager.h"
#include "IEventPublish.h"
#include "SharedPtr.h"
#include "AgentData.h"
#include "Event.h"

class Server;

class IAgent
{
public:
    static IAgent* Create(ISubManager& _subManager, IEventPublish& _eventPublish);
	IAgent(ISubManager& _subManager, IEventPublish& _eventPublish);
    virtual ~IAgent();
    
    virtual  void 		Init(const AgentData& _data) = 0;
    virtual  void		Destroy() = 0;
    virtual  void		GetEvent(shared_ptr<Event> _event) = 0;
private:
	ISubManager&	m_subManager;
	IEventPublish&	m_eventPublish;
};

#endif //__IAGENT_H__
