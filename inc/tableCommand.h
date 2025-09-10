#pragma once
#include <vector>
#include <string>
#include <memory>
#include "command.h"
#include "manage.h"
#include "checker.h"
class Add_TableCommand:public Command
{
		Manage* m_pManage ;
        int m_id, m_pId, m_row, m_col, m_rowCount, m_colCount;
        public:
        Add_TableCommand(const std::vector<std::string>& args);
        void execute()override;
};
