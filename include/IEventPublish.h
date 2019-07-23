#ifndef __IEVENTPUBLISH_H__
#define __IEVENTPUBLISH_H__

#include "Event.h"
#include "common.h"
#include "SharedPtr.h"

class IEventPublish:private Ucopyable
{
public:
	virtual ~IEventPublish() = 0;
	virtual void PublishEvent(shared_ptr<Event> _event) = 0;
};

#endif //__IEVENTPUBLISH_H__
