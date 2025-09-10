#pragma once
#include <memory>
#include "command.h"
#include "start.h"
class Start;
class Exit: public Command
{
	Start* m_start;
	public:
	Exit();	
	void execute()override;
};
