#pragma once
#include "command.h"
#include <vector>

/*#include <string>
#include "buttonCommand.h"
#include "fwindowCommand.h"
#include "windowCommand.h"
#include "tableCommand.h"
#include "textCommand.h"
*/
class Invorker
{
    std::vector<Command*> m_history;
    public:
    void executeComand(Command* com);
	//void SetCmd( Command* cmd );
	//Command* GetCmd();
//	Command* createCommand(std::string name, std::vector<std::string> args);
    ~Invorker();
};
