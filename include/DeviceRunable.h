#ifndef __DEVICERUNABLE_H__
#define __DEVICERUNABLE_H__

#include <stdexcept>

#include "runable.h"
#include "Agent.h"

class DeviceRunable:public Runable
{
public:
	DeviceRunable(Agent* _agent);
	virtual void Connect();
private:
	Agent* m_agent;
};

#endif //__DEVICERUNABLE_H__
