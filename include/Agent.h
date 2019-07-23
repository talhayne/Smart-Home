#ifndef __AGENT_H__
#define __AGENT_H__

#include <iostream>

#include "ISubManager.h"
#include "IEventPublish.h"
#include "SharedPtr.h"
#include "AgentData.h"
#include "Event.h"

class Server;

class Agent
{
    static Agent* Create(ISubManager& _subManager, IEventPublish& _eventPublish);
public:
	
	Agent(ISubManager& _subManager, IEventPublish& _eventPublish): m_subManager(_subManager)
, m_eventPublish(_eventPublish){}
    
    virtual ~Agent(){}
    virtual  void 		Init(const AgentData& _data) = 0;
    virtual  void		Destroy() = 0;
    virtual  void		Connect() = 0;
    virtual  void		GetEvent(shared_ptr<Event> _event) = 0;
    
    std::string& getID(){return m_id;}
    std::string& getType(){return m_type;}
protected:
    std::string		m_id;
    std::string		m_room;
    std::string		m_floor;
    std::string		m_type;
    
	ISubManager&	m_subManager;
	IEventPublish&	m_eventPublish;
};

#endif //__AGENT_H__
