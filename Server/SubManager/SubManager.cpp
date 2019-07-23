#include <exception>
#include <iostream>

#include "SubManager.h"

void SubManager::RemoveSubscriber(Agent* _agent, const EventKey& _key)
{
	try
	{
		m_subContainer[_key].erase(_agent);
	}
	catch(std::exception& e)
	{
		throw;
	}
}

void SubManager::AddSubscriber(Agent* _agent, const EventKey& _key)
{
	_key.Print();
	std::cout << "***********************************" << std::endl;
	
	try
	{
		m_subContainer[_key].insert(_agent);
	}
	catch(std::exception& e)
	{
		throw;
	}
}

const std::set<Agent*>& SubManager::GetSubAgents(const EventKey& _key)
{	
	return m_subContainer[_key];
}

