#pragma once
#include <iostream>	
#include "c.h"
#include "base.h"
#include "manage.h"
class Add_F_WindowCommand: public Command
{
		Manage* m;
        int m_id, m_rowCount, m_colCount, m_pId;
        public:
        Add_F_WindowCommand(Manage* mm, int id,  int rowCount, int colCount);
        void execute() override;
};
