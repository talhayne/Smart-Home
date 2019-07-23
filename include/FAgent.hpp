#ifndef __FAGENT_HPP__
#define __FAGENT_HPP__

/****************************************************
						CTOR
****************************************************/

template<class T>
FAgent<T>::FAgent(IDynamicLoader<T>& _loader)
: m_loader(_loader)
{
}

/****************************************************
						newAgent
****************************************************/

template<class T>
Agent* FAgent<T>::newAgent(const AgentData& _data, ISubManager& _subManager, IEventPublish& _eventPublish)const
{
	std::string type = _data.m_type;
	type.insert(0, "./LIB/lib");
	
	Agent* (*createFunc)(ISubManager&, IEventPublish&);
	createFunc = (Agent* (*)(ISubManager&, IEventPublish&))m_loader.GetFunc(type, "Create");

	Agent* agent = createFunc(_subManager, _eventPublish);
	agent->Init(_data);
	
	return agent;
}

#endif //__FAGENT_HPP__
