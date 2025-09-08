#include "buttonCommand.h"
Add_ButtonCommand:: Add_ButtonCommand(Manage* mm, int id, int pId, int row, int col, std::string button)
                          :m(mm), m_id(id), m_pId(pId), m_row(row), m_col(col), m_button(button)
                          {}
void Add_ButtonCommand::execute()
{
		if(!(m->M_CheckParametrs( m_id, m_pId, m_row, m_col)))
				return;
		Base* base = new Button(m_id, m_pId, m_row, m_col, m_button);
		m->AddElement(base);
		Window* w = m->FindWindow(m_pId);
		if(w)
		{
				w->AddChild(base);
		}
}
