#ifndef __COMMON_H__
#define __COMMON_H__

class Ucopyable
{
	public:
		Ucopyable(){}
	private:
		Ucopyable(const Ucopyable&); //no impl
		Ucopyable operator=(const Ucopyable&); //no impl
};

#endif //__COOMON_H__
