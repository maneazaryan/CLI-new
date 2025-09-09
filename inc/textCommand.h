#pragma once
#include "command.h"
#include <string>	
#include <memory>
#include "manage.h"
#include "checker.h"
class Add_TextCommand:public Command
{
		Manage* m_pManage;
        int m_id, m_pId, m_row, m_col;
        std::string m_text;
        public:
        Add_TextCommand(int id, int pId, int row, int col, std::string text );
        void execute()override;
};
