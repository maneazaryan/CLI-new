#pragma once
#include "command.h"
#include "base.h"
#include "manage.h"
class Add_ButtonCommand : public Command
{
		Manage* m_pManage;
        int m_id, m_pId, m_row, m_col;
        std::string m_button;
        public:
        Add_ButtonCommand(int id, int pId, int row, int col, std::string button);
        void execute()override;
};
