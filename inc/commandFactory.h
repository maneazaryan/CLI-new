#pragma once
#include <iostream>	
#include <string>
#include <vector>
#include "command.h"
#include "buttonCommand.h"
#include "fwindowCommand.h"
#include "windowCommand.h"
#include "tableCommand.h"
#include "textCommand.h"

class CommandFactory
{
    public:
        static Command* CreateCommand(const std::vector<std::string>& args);
};
