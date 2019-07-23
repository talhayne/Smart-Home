#include <iostream>
#include "EventKey.h"

EventKey::EventKey()
{
}

EventKey::EventKey(std::string _type, std::string _floor, std::string _room)
: m_type(_type)
, m_floor(_floor)
, m_room(_room)
{
}

bool EventKey::operator< (const EventKey& _param)const
{
	if (m_type == _param.m_type)
	{
		if (m_floor == _param.m_floor)
		{
			return (m_room < _param.m_room);
		}
		return (m_floor < _param.m_floor);
	}
	return (m_type < _param.m_type);
}

void EventKey::Print()const
{
	std::cout << "type:" << m_type << " floor:" << m_floor << " room:" << m_room << std::endl; 
}


