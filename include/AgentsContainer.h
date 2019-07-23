#ifndef __AGENTSCONTAINER_H__
#define __AGENTSCONTAINER_H__

#include <string>
#include <set>
#include <vector>

#include "thread.h"
#include "runable.h"
#include "common.h"
#include "Agent.h"

class AgentsContainer:private Ucopyable
{
public:
	~AgentsContainer();
	void addAgent(Agent* _agent);
	void removeAgent(Agent* _agent);
	void Connect();
	void puse();
	void stop();
	void print();

private:
	std::set<Agent*> m_agents;
	std::vector<Thread*> m_threads;
};

#endif //__AGENTSCONTAINER_H__
