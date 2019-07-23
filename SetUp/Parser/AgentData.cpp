#include <iostream>

#include "AgentData.h"

void AgentData::Print()const
{
	std::cout << m_id << std::endl;
	std::cout << m_room << std::endl;
	std::cout << m_floor << std::endl;
	std::cout << m_type << std::endl;
	std::cout << m_log << std::endl;
}

