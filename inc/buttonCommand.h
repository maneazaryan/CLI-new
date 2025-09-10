#pragma once
#include <memory>
#include <vector>
#include <string>
#include "command.h"
#include "base.h"
#include "manage.h"
#include "checker.h"
class Add_ButtonCommand : public Command
{
		Manage* m_pManage;
        int m_id, m_pId, m_row, m_col;
        std::string m_button;
        public:
        Add_ButtonCommand(const std::vector<std::string>& args);
        void execute()override;
};
