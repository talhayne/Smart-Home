#ifndef __SERVER_H__
#define __SERVER_H__

#include "IDispatcher.h"
#include "ISubLookUp.h"
#include "IEventRetriever.h"
#include "Agent.h"

class Server
{
public:
	Server(const IDispatcher& _dis, ISubLookUp& _subLookUp, IEventRetriever& _eventRet);
    void Work();
private:
	const IDispatcher& 		m_dis;
	ISubLookUp& 			m_subLookUp;
	IEventRetriever& 		m_eventRet;
};

#endif // __SERVER_H__
