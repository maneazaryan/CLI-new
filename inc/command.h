#pragma once
#include <iostream>	
#include <vector>
#include <sstream>
#include <regex>
#include "base.h"
#include "window.h"
#include "manage.h"

#include "c.h"
#include "buttonCommand.h"
#include "fwindowCommand.h"
#include "windowCommand.h"
#include "tableCommand.h"
#include "textCommand.h"
#include "invorker.h"

class Ivorker;
class Show;
class Add_F_WindowCommand;
class Add_WindowCommand;
class Add_TextCommand;
class Add_TableCommand;
class Add_ButtonCommand;
void CommandsShow();
std::vector<std::string> GetCommandsLine();
void GetFirstWindow(Manage* m, bool& quit,std::vector<std::string>& v, Ivorker& inv);
void DoCommand(const std::vector<std::string>& v,Manage* m, bool& quit, Ivorker& inv);
void GetCommands(Manage* m);
