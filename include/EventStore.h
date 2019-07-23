#ifndef __EVENTSTORE_H__
#define __EVENTSTORE_H__

#include <queue>
#include "SharedPtr.h"
#include "Event.h"
#include "IEventPublish.h"
#include "IEventRetriever.h"
#include "common.h"
#include "waitableQueue.h"

class EventStore:public IEventPublish, public IEventRetriever
{
public:
	virtual void PublishEvent(shared_ptr<Event> _event);
	virtual void GetEvent(shared_ptr<Event>& _event);
private:
	WaitableQueue<shared_ptr<Event> > m_eventsQueue;	
};

#endif //__EVENTSTORE_H__
