#include <iostream> //debug
#include <csignal>
#include <stdlib.h> 

#include "SmartHome.h"

bool SmartHome::m_runFlag = 1;

void signalHandler(int signum)
{
   std::cout << "\n\nInterrupt signal (" << signum << ") received.\n" << std::endl;
   
   exit(signum);  
}

SmartHome::SmartHome(const std::string& _fileName)
: m_server(m_dis, m_subManager, m_eventStore)
, m_setUp(_fileName, m_subManager, m_eventStore)
{
}

void SmartHome::Connect()
{
	signal(SIGUSR1, signalHandler);
	signal(SIGINT, signalHandler);
	
	try
	{
		m_setUp.Connect();
		m_server.Work();
	}
	catch(std::exception& j)
	{
		std::cout << j.what() << std::endl;
	}
}
