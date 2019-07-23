#include <iostream>
#include <cassert>

#include "Mutex.h"

Mutex::Mutex()
{
	int retVal = pthread_mutex_init(&m_mutex, NULL);
	if (retVal)
	{
		throw MutexInitException();
	}
}

Mutex::~Mutex()
{	
	int retVal = pthread_mutex_destroy(&m_mutex);
	if (retVal)
	{
		assert(0);
	}
}

void Mutex::lock()
{
	int retVal = pthread_mutex_lock(&m_mutex);
	if (retVal)
	{
		throw MutexLockException();
	}
}

void Mutex::unlock()
{
	int retVal = pthread_mutex_unlock(&m_mutex);
	if (retVal)
	{
		throw MutexUnlockException();		
	}
}

