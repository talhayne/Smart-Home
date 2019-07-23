#include <exception>
#include <iostream>
#include <cassert>

#include "condVar.h"

CondVar::CondVar(Mutex& _mutex)
:m_mutex(_mutex)
{
	int retVal = pthread_cond_init(&m_cond, NULL);
	if (retVal)
	{
		throw CondVarInitException();
	}
}

CondVar::~CondVar()
{
	int retVal = pthread_cond_destroy(&m_cond);
	if (retVal)
	{
		assert(0);
	}
}


void CondVar::NotifyOne()
{
	int retVal = pthread_cond_signal(&m_cond);
	if (retVal)
	{
		throw CondVarNotifyOneException();
	}
}

void CondVar::NotifyAll()
{
	int retVal = pthread_cond_broadcast(&m_cond);
	if (retVal)
	{
		throw CondVarNotifyAllException();
	}
}
