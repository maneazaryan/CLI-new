#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "command.h"
#include "windowPrinter.h"
class Show: public Command
{
		int m_showPid;
        public:
        Show(const std::vector<std::string>& args);
        void execute() override;
};
