#pragma once
#include "c.h"
#include "base.h"
#include "manage.h"
class Add_ButtonCommand : public Command
{
		Manage* m;
        int m_id, m_pId, m_row, m_col;
        std::string m_button;
        public:
        Add_ButtonCommand(Manage* mm , int id, int pId, int row, int col, std::string button);
        void execute()override;
};
