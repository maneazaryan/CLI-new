#pragma once
#include <iostream>	
#include <vector>
#include <memory>

#include "parser.h"
#include "base.h"
#include "window.h"
#include "commandFactory.h"

#include "command.h"

void CommandsShow();
void GetFirstWindow(std::vector<std::string>& v);
void DoCommand(const std::vector<std::string>& v, bool& quit);
void GetCommands();
