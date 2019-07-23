#ifndef __CONDVAR_H__
#define __CONDVAR_H__

#include <pthread.h>
#include "common.h"
#include "Mutex.h"
#include <iostream>

class CondVarInitException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "CondVar Init Exception";
	}
};

class CondVarWaitException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "CondVar Wait Exception";
	}
};


class CondVarNotifyOneException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "CondVar Notif One Exception";
	}
};

class CondVarNotifyAllException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "CondVar Notify All Exception";
	}
};

class CondVar:private Ucopyable
{
public:
	CondVar(Mutex& _mutex);
	~CondVar();
	
	template <typename Predicate>
	void Wait(const Predicate& p);
	void NotifyOne();
	void NotifyAll();
private:
	Mutex&			m_mutex;
	pthread_cond_t 	m_cond;
};

	
template <typename Predicate>
void CondVar::Wait(const Predicate& p)
{
	while (p())
	{
		int retVal = pthread_cond_wait(&m_cond, m_mutex.getMutex());
		if (retVal)
		{
			throw CondVarWaitException();
		}
	}
}


#endif //__CONDVAR_H__
