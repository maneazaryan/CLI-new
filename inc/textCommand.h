#pragma once
#include "c.h"
#include <string>	
#include "manage.h"
class Add_TextCommand:public Command
{
		Manage* m;
        int m_id, m_pId, m_row, m_col;
        std::string m_text;
        public:
        Add_TextCommand(Manage* mm , int id, int pId, int row, int col, std::string text );
        void execute()override;
};
