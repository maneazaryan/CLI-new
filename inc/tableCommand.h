#pragma once
#include "c.h"
#include "manage.h"
class Add_TableCommand:public Command
{
		Manage* m ;
        int m_id, m_pId, m_row, m_col, m_rowCount, m_colCount;
        public:
        Add_TableCommand(Manage* m, int id, int pId, int row, int col, int rowCount, int colCount );
        void execute()override;
};
