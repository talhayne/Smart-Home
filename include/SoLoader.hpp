#ifndef __SOLOADER_HPP__
#define __SOLOADER_HPP__

#include <dlfcn.h>

template<class T>
SoLoader<T>::~SoLoader()
{
}

template<class T>
T SoLoader<T>::GetFunc(const std::string& _path, const std::string& _func)
{
	void* handle = dlopen(_path.c_str(), RTLD_LAZY);
	if(!handle)
	{
		std::cout << dlerror() << std::endl;
	}
	return dlsym(handle, _func.c_str());
}

#endif //__SOLOADER_HPP__
