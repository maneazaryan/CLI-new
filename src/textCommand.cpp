#include "textCommand.h"
Add_TextCommand::Add_TextCommand(int id, int pId, int row, int col, std::string text )
                       :m_id(id), m_pId(pId), m_row(row), m_col(col), m_text(text) 
{
   m_pManage = Manage::GetInstance();
}
void Add_TextCommand::execute()
{
		if(!(m_pManage->M_CheckParametrs( m_id, m_pId, m_row, m_col)))
				return;
		Base* b = new Text(m_id, m_pId, m_row, m_col, m_text);
		m_pManage->AddElement(b);
		Window* w = m_pManage->FindWindow(m_pId);
		if(w)
				w->AddChild(b);
}
