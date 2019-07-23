#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "runable.h"
#include "waitableQueue.h"
#include "dog.h"

class Consumer:public Runable
{
public:
	Consumer(WaitableQueue<Dog>& _q, long _n);
	void Run();
	bool DidFail(){return m_failed;}
	long HowManyDogs(){return m_nDogs;}
	
private:
	WaitableQueue<Dog>&	m_queue;
	long				m_nLoops;
	long				m_nDogs;
	long 				m_prevID;
    bool 				m_failed;
};

#endif //__CONSUMER_H__

