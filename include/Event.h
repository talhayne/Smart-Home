#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include "EventKey.h"

class Event
{
public:
	Event();
	Event(std::string _type, std::string _floor, std::string _room, std::string _time, std::string _data);
	
	void Print()const;
    const EventKey	GetKey()const;
    
    EventKey		m_key;
    std::string     m_time;
    std::string     m_data;
};

#endif // __EVENT_H__
