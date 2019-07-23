#include <iostream>
#include <exception>

#include "EventStore.h"

void EventStore::PublishEvent(shared_ptr<Event> _event)
{
	try
	{
		m_eventsQueue.Push(_event);
	}
	catch(std::exception& e)
	{
		throw;
	}
}

void EventStore::GetEvent(shared_ptr<Event>& _event)
{
	try
	{
		m_eventsQueue.Pop(_event);
	}
	catch(std::exception& e)
	{
		throw;
	}		
}
