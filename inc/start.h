#pragma once
#include <iostream>	
#include <vector>
#include <memory>
#include <sstream>
#include <regex>
#include "base.h"
#include "windowPrinter.h"
#include "window.h"
#include "commandFactory.h"

#include "command.h"
#include "fwindowCommand.h"

class Add_F_WindowCommand;
void CommandsShow();
std::vector<std::string> GetCommandsLine();
void GetFirstWindow(std::vector<std::string>& v);
void DoCommand(const std::vector<std::string>& v, bool& quit);
void GetCommands();
