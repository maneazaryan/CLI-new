#include "command.h"
#include "manage.h"

Manage* Manage::m_pManage=nullptr;
int main()
{
	GetCommands(Manage::GetInstance());
	return 0;
}	
