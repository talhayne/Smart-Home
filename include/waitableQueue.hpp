#include <exception>
#include <iostream>

template <typename T>
class IsEmptyQueue
{
public:
	IsEmptyQueue(std::queue<T>& _queue):m_queue(_queue){}	
	bool operator()() const
	{
		return m_queue.empty();
	}
private:
	std::queue<T>&	m_queue;
};

template <typename T>
WaitableQueue<T>::WaitableQueue()
: m_condVar(m_mutex)
{
}

template <typename T>
void WaitableQueue<T>::Pop(T& _t)
{
	m_mutex.lock();
	try
	{
		m_condVar.Wait(IsEmptyQueue<T>(m_queue));
		_t = m_queue.front();
		m_queue.pop();
		m_mutex.unlock(); 	
	}
	catch(std::exception& e)
	{
		m_mutex.unlock(); 
		throw;
	}
}

template <typename T>
void WaitableQueue<T>::Push(const T& _elem)
{
    m_mutex.lock();
    try
	{
		m_queue.push(_elem);
		m_mutex.unlock();
		m_condVar.NotifyAll();
	}
	catch(std::exception& e)
	{
		m_mutex.unlock(); 
		throw;
	}
	catch(...)
	{
		m_mutex.unlock(); 
		throw;
	}	
}

