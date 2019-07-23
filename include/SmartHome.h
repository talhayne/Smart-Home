#ifndef __SMARTHOME_H__
#define __SMARTHOME_H__

#include "common.h"
#include "Dispatcher.h"
#include "SubManager.h"
#include "EventStore.h"
#include "Server.h"
#include "SetUp.h"

class SmartHome:private Ucopyable
{
public:
	SmartHome(const std::string& _fileName);
	void Connect();
private:       
	Dispatcher			m_dis;
	SubManager			m_subManager;
	EventStore			m_eventStore;
	Server				m_server;
	SetUp				m_setUp;
	static bool			m_runFlag;
};

#endif //__SMARTHOME_H__

