#ifndef __RUNABLE_H__
#define __RUNABLE_H__

class Runable
{
public:
	virtual ~Runable();
	virtual void Run() = 0;
};

#endif //__RUNABLE_H__
