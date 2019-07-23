#ifndef __IEVENTRETRIEVER_H__
#define __IEVENTRETRIEVER_H__

#include "SharedPtr.h"
#include "common.h"
#include "Event.h"

class IEventRetriever:private Ucopyable
{
public:
	virtual ~IEventRetriever() = 0;
	virtual void GetEvent(shared_ptr<Event>& _event) = 0; 
};

#endif //__IEVENTRETRIEVER_H__
