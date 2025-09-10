#include "start.h"
#include "manage.h"

int main()
{
	Start::GetInstance()->GetCommands();
	Manage::DeleteInstance();
	Start::DeleteInstance();
	return 0;
}	
