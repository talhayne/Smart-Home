#include <iostream>
#include <vector>

#include "testAgent.h"

TestAgent::TestAgent(ISubManager& _subManager, IEventPublish& _eventPublish)
: Agent(_subManager, _eventPublish)
{
}


void TestAgent::Destroy()
{
	delete this;
}

void TestAgent::Init(const AgentData& _data)
{
	m_id = _data.m_id;
    m_room = _data.m_room;
    m_floor = _data.m_floor;
    m_type = _data.m_type;
    
    for(std::vector<EventKey>::const_iterator it = _data.m_configData.begin(); it !=  _data.m_configData.end(); ++it)
    {
		m_subManager.AddSubscriber(this, (*it));
	}
}

void TestAgent::Connect()
{
}

void TestAgent::GetEvent(shared_ptr<Event> _event)
{
	std::cout << "TestAgent::GetEvent---> type:" << _event->m_key.m_type << ", time: " << _event->m_time << std::endl;
}

extern "C" Agent* Create(ISubManager& _subManager, IEventPublish& _eventPublish)
{
	return new TestAgent(_subManager, _eventPublish);	
}

