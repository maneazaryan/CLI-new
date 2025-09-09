#pragma once
#include <iostream>	
#include <memory>
#include "command.h"
#include "manage.h"
#include "checker.h"
class Add_WindowCommand : public Command
{
		Manage* m_pManage;
        int m_id, m_pId, m_row, m_col, m_rowCount, m_colCount;
        public:
        Add_WindowCommand(int id, int pId, int row, int col,  int rowCount, int colCount);
        void execute()override;
};
