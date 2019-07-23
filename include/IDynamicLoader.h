#ifndef __IDYNAMICLOADER_H__
#define __IDYNAMICLOADER_H__
#include <string>

template<class T>
class IDynamicLoader
{
public:
    virtual ~IDynamicLoader();
    virtual T GetFunc(const std::string& _path, const std::string& _func) = 0;
};

#include "IDynamicLoader.hpp"

#endif //__IDYNAMICLOADER_H__
