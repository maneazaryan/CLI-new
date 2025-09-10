#pragma once
#include <iostream>	
#include <vector>
#include <string>
#include "command.h"
#include "checker.h"
#include "base.h"
#include "manage.h"
class Add_F_WindowCommand: public Command
{
        int m_id, m_rowCount, m_colCount, m_pId;
        public:
        Add_F_WindowCommand(const std::vector<std::string>& args);
        void execute() override;
};
