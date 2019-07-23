#ifndef __MUTEX_H__
#define __MUTEX_H__

#include <pthread.h>
#include <exception>

#include "common.h"

class MutexInitException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "Mutex Init Exception";
	}
};

class MutexLockException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "Mutex Lock Exception";
	}
};

class MutexUnlockException: public std::exception {
public:
	virtual const char* what() const throw() {
		return "Mutex unlock Exception";
	}
};

class Mutex:private Ucopyable
{
	friend class CondVar;
public:
	Mutex();
	~Mutex();

	void lock();
	void unlock();
	pthread_mutex_t*	getMutex(){return &m_mutex;}		
private:
	pthread_mutex_t		m_mutex;
};

#endif //__MUTEX_H__
