#pragma once
#include <memory>
#include "command.h"
#include "manage.h"
#include "checker.h"
class Add_TableCommand:public Command
{
		Manage* m_pManage ;
        int m_id, m_pId, m_row, m_col, m_rowCount, m_colCount;
        public:
        Add_TableCommand(int id, int pId, int row, int col, int rowCount, int colCount );
        void execute()override;
};
