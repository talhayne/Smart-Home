#include <cassert>
#include <iostream>

#include "thread.h"

void* Thread::Work(void* _run)
{
	Runable* run = reinterpret_cast<Runable*>(_run);
	try
	{
		run->Run();
	}
	catch (...)
	{
		throw;
	}
	
	return 0;
}

/**************************************************************
							CTOR
**************************************************************/

Thread::Thread(shared_ptr<Runable> _runable, bool _joinable)
:m_run(_runable)
,m_wasJoinable(false)
,m_needToJoin(_joinable)
{
	int rtval = pthread_create(&m_tid, NULL, &Work, &(*m_run));
	if(rtval)
	{
		throw PthreadCreateExeption();
	}
	
	if(!m_needToJoin)
	{
		try
		{
			Detach();
		}
		catch(PthreadDetachExeption& d)
		{
			throw;
		}
	}
}

/**************************************************************
							DTOR
**************************************************************/

Thread::~Thread()
{
	if (m_needToJoin && !m_wasJoinable)
	{
		try
		{
			Join();
		}catch(PthreadJoinExeption& j)
		{	
			std::cerr << j.what() << std::endl;
		}
	}
}

/**************************************************************
							join
**************************************************************/

void Thread::Join()
{
	if (m_needToJoin && !m_wasJoinable)
	{
		int retVal = pthread_join(m_tid, NULL);
		if (retVal)
		{
			throw PthreadJoinExeption();
		}
		m_wasJoinable = true;
	}
	else
	{
		assert(0);
	}
}

/**************************************************************
							detach
**************************************************************/

void Thread::Detach()
{	
	int retVal = pthread_detach(m_tid);
	if (retVal)
	{
		throw PthreadDetachExeption();
	}
	m_needToJoin = false;
}

/**************************************************************
							Joinable
**************************************************************/

bool Thread::Joinable()const
{
	return m_needToJoin;
}

/**************************************************************
							GetTid
**************************************************************/

pthread_t Thread::GetTid()const
{
	return m_tid;
}

