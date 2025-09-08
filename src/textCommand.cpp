#include "textCommand.h"
Add_TextCommand::Add_TextCommand(Manage* mm ,int id, int pId, int row, int col, std::string text )
                       :m(mm), m_id(id), m_pId(pId), m_row(row), m_col(col), m_text(text) {}
void Add_TextCommand::execute()
{
		if(!(m->M_CheckParametrs( m_id, m_pId, m_row, m_col)))
				return;
		Base* b = new Text(m_id, m_pId, m_row, m_col, m_text);
		m->AddElement(b);
		Window* w = m->FindWindow(m_pId);
		if(w)
				w->AddChild(b);
}
