#include <exception>
#include "DeviceRunable.h"

DeviceRunable::DeviceRunable(Agent* _agent)
: m_agent(_agent)
{
}

void DeviceRunable::Connect()
{
	try
	{
		m_agent->Connect();
	}
	catch(std::exception& e)
	{
		throw;
	}
}
