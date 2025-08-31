#pragma once
#include <iostream>	
#include <vector>
#include <sstream>
#include "base.h"
#include "window.h"
#include "manage.h"

void CommandsShow();
std::vector<std::string> GetCommandsLine();
void GetFirstWindow(Manage* m, bool& quit);
void DoCommand(const std::vector<std::string>& v,Manage* m, bool& quit);
void GetCommands(Manage* m);
