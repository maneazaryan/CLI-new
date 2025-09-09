#pragma once
#include <iostream>	
#include <vector>
#include <sstream>
#include <regex>
#include "base.h"
#include "window.h"
#include "commandFactory.h"

#include "command.h"
#include "fwindowCommand.h"
#include "invorker.h"

class Invorker;
class Add_F_WindowCommand;
void CommandsShow();
std::vector<std::string> GetCommandsLine();
void GetFirstWindow(std::vector<std::string>& v, Invorker& inv);
void DoCommand(const std::vector<std::string>& v, bool& quit, Invorker& inv);
void GetCommands();
