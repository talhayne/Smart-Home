#include <iostream>
#include <exception>

#include "AgentsContainer.h"
#include "thread.h"
#include "DeviceRunable.h"
#include "runable.h"

/***************************************************************
							addAgent
****************************************************************/

void AgentsContainer::addAgent(Agent*_agent)
{
	m_agents.insert(_agent);
}

/***************************************************************
						removeAgent
***************************************************************/

void AgentsContainer::removeAgent(Agent*_agent)
{
	std::set<Agent*>::iterator it = m_agents.find(_agent);
	m_agents.erase(it);
}

/***************************************************************
							DTOR
***************************************************************/

AgentsContainer::~AgentsContainer()
{
	for (std::vector<Thread*>::iterator it = m_threads.begin() ; it != m_threads.end(); ++it)
	{
		delete (*it);
	} 
	m_threads.clear();

    for (std::set<Agent*>::iterator it = m_agents.begin() ; it != m_agents.end(); ++it)
	{
		delete (*it);
	} 
	m_agents.clear();
	
}

/***************************************************************
						AgentConnect
***************************************************************/

void AgentsContainer::Connect()
{
	for (std::set<Agent*>::iterator it = m_agents.begin(); it != m_agents.end(); ++it)
	{
		try
		{
			shared_ptr<Runable> d(new DeviceRunable(*it));
			m_threads.push_back(new Thread(d));
			std::cout << "AgentsContainer::Connect " << (*it)->getType() << std::endl;
		}
		catch(std::exception& e)
		{
			throw;
		}
	}
}

/***************************************************************
							print
***************************************************************/

void AgentsContainer::print()
{
	for (std::set<Agent*>::iterator it = m_agents.begin(); it != m_agents.end(); ++it)
	{
    	std::cout << (*it)->getID() << std::endl;
	}
}

