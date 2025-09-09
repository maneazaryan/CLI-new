#include "start.h"
#include "manage.h"

int main()
{
	GetCommands();
	Manage::DeleteInstance();
	return 0;
}	
