#ifndef __EVENTKEY_H__
#define __EVENTKEY_H__

#include <string>

class EventKey
{
public:
	EventKey();
	EventKey(std::string _type, std::string _floor, std::string _room);
    bool		operator< (const EventKey& _param)const;
    
    void Print()const;
    
    std::string  m_type;
    std::string  m_floor;
    std::string  m_room;
};

#endif // __EVENTKEY_H__

