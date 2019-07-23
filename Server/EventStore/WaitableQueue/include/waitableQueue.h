#ifndef __WAITABLEQUEUE_H__
#define __WAITABLEQUEUE_H__

#include <queue>
#include "condVar.h"

template <typename T>
class WaitableQueue
{
public:
	WaitableQueue();
	void Pop(T& _t);
	void Push(const T& _elem);
	bool IsEmpty(){return m_queue.empty();}
	
private:
	std::queue<T>	m_queue;
	Mutex			m_mutex;
	CondVar			m_condVar;
};

#include "waitableQueue.hpp"


#endif //__WAITABLEQUEUE_H__
