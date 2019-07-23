#ifndef __THREAD_H__
#define __THREAD_H__

#include <memory>
#include <stdexcept>
#include <tr1/memory>

#include "common.h"
#include "runable.h"

using std::tr1::shared_ptr;

class PthreadCreateExeption: public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Pthread Create Exeption";
	}
private:
	int m_errorVal;
}; 

class PthreadJoinExeption: public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Pthread Join Exeption";
	}
};

class PthreadDetachExeption: public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Pthread Detach Exeption";
	}
};

class Thread:private Ucopyable
{
public:
	Thread(shared_ptr<Runable> _runable, bool _joinable = true);
	~Thread();
	
	void Join();
	void Detach();
	bool Joinable()const;
	pthread_t GetTid()const;
private:
	static void* Work(void* _this);
private:
	pthread_t			m_tid;
	shared_ptr<Runable>	m_run;
	bool		m_wasJoinable;
	bool		m_needToJoin;
};

#endif //__THREAD_H__
