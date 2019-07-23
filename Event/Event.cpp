#include <iostream>
#include "Event.h"

Event::Event()
{
}

Event::Event(std::string _type, std::string _floor, std::string _room, std::string _time, std::string _data)
: m_key(_type, _floor, _room)
, m_time(_time)
, m_data(_data)
{
}

const EventKey Event::GetKey()const
{
	return m_key;
}
 
void Event::Print()const
{
	std::cout << "type:" << m_key.m_type << " floor:" << m_key.m_floor << " room:" << m_key.m_room << " time:" << m_time << " data:" << m_data << std::endl; 
}

