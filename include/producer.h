#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include "runable.h"
#include "waitableQueue.h"
#include "dog.h"

class Producer:public Runable
{
public:
	Producer(WaitableQueue<Dog>& _q, long _n);
	void Run();
private:
	WaitableQueue<Dog>&	m_queue;
	long				m_nLoops;	
};

#endif //__PRODUCER_H__
