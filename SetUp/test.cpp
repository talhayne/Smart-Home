#include "SetUp.h"
#include "EventStore.h"
#include "SubManager.h"

int main()
{
	SubManager subManager;
	EventStore eventPublish;
	
	SetUp("config.txt", subManager, eventPublish);
	return 0;
}
