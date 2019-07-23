#ifndef __SOLOADER_H__
#define __SOLOADER_H__
#include <string>
#include "IDynamicLoader.h"

template<class T>
class SoLoader:public IDynamicLoader<T>
{
public:
    virtual ~SoLoader();
    virtual T GetFunc(const std::string& _path, const std::string& _func);
};

#include "SoLoader.hpp"

#endif //__SOLOADER_H__
