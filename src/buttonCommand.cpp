#include "buttonCommand.h"
Add_ButtonCommand:: Add_ButtonCommand(int id, int pId, int row, int col, std::string button)
                          :m_id(id), m_pId(pId), m_row(row), m_col(col), m_button(button)
                          {
   m_pManage = Manage::GetInstance();
}
void Add_ButtonCommand::execute()
{
		std::unique_ptr<Checker> checker = std::make_unique<Checker>();
		if(!(checker->M_CheckParametrs( m_id, m_pId, m_row, m_col)))
				return;
		Base* base = new Button(m_id, m_pId, m_row, m_col, m_button);
		m_pManage->AddElement(base);
		Window* w = m_pManage->FindWindow(m_pId);
		if(w)
		{
				w->AddChild(base);
		}
}
