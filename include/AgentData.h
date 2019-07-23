#ifndef __AGENTDATA_H__
#define __AGENTDATA_H__

#include <string>
#include <vector>

#include "EventKey.h"

struct AgentData
{
public:
    std::string   			m_id;
    std::string   			m_room;
    std::string   			m_floor;
    std::string   			m_log;
    std::string   			m_type;
    std::vector<EventKey>	m_configData;
public:
    void Print()const;
};


#endif //__AGENTDATA_H__
