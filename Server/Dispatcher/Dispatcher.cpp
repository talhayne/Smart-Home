#include "Dispatcher.h"

void Dispatcher::Work(const std::set<Agent*>& _agents, shared_ptr<Event> _event)const
{
	std::cout << std::endl << "Dispatcher::Work -> event:  " << std::endl;
	_event->Print();
	std::cout << std::endl;
	
	for(std::set<Agent*>::iterator it = _agents.begin(); it != _agents.end(); ++it)
	{
		std::cout << (*it)->getType() << std::endl;
		(*it)->GetEvent(_event);
	}
}
