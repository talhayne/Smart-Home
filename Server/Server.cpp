#include <iostream>
#include <vector>
#include <exception>

#include "Server.h"
#include "Event.h"
#include "IEventPublish.h"

Server::Server(const IDispatcher& _dis, ISubLookUp& _subLookUp, IEventRetriever& _eventRet)
: m_dis(_dis)
, m_subLookUp(_subLookUp)
, m_eventRet(_eventRet)
{
}

void Server::Work()
{
	while(1)
	{
		try
		{
			shared_ptr<Event> event(new Event);
			m_eventRet.GetEvent(event);
			const std::set<Agent*>& agentsSet = m_subLookUp.GetSubAgents(event->m_key);
			m_dis.Work(agentsSet, event);
		}
		catch(std::exception& e)
		{
			throw;
		}
	}
}
