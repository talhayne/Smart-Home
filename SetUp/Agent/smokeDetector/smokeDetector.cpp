#include <iostream> //print debugger
#include <unistd.h>

#include "smokeDetector.h"


SmokeDetector::SmokeDetector(ISubManager& _subManager, IEventPublish& _eventPublish)
: Agent(_subManager, _eventPublish)
{
}

void SmokeDetector::Destroy()
{
	delete this;
}

void SmokeDetector::Init(const AgentData& _data)
{
	m_id = _data.m_id;
    m_room = _data.m_room;
    m_floor = _data.m_floor;
    m_type = _data.m_type;
}

void SmokeDetector::Connect()
{
	std::string type = "SIGUSER2";
	std::string floor = "0";
	std::string room =  "0";
	std::string time = "12:34:44";
	std::string data = "thisIsData";
	
	try
	{
		shared_ptr<Event> event = shared_ptr<Event> (new Event(type, floor, room, time, data));
		m_eventPublish.PublishEvent(event);
	}
	catch(...)
	{
		throw;
	}
    
    sleep(3);
        
    type = "test";
	floor = "1";
	room =  "room_1_c";
	time = "12:34:47";
	
	try
	{
		shared_ptr<Event> event = shared_ptr<Event> (new Event(type, floor, room, time, data));
		m_eventPublish.PublishEvent(event);
	}
	catch(...)
	{
		throw;
	}
    
    while(1)
    {
	}
}

void SmokeDetector::GetEvent(shared_ptr<Event> _event)
{
}

extern "C" Agent* Create(ISubManager& _subManager, IEventPublish& _eventPublish)
{
	return new SmokeDetector(_subManager, _eventPublish);
}

