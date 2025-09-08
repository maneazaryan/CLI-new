#include "tableCommand.h"

Add_TableCommand::Add_TableCommand(Manage* mm, int id, int pId, int row, int col, int rowCount, int colCount )
                       : m(mm), m_id(id), m_pId(pId), m_row(row), m_col(col)
                       , m_rowCount(rowCount), m_colCount(colCount) {}
void Add_TableCommand::execute()
{
		if(!(m->M_CheckParametrs( m_id, m_pId, m_row, m_col) ))
				return;
		Base* base = new Table(m_id, m_pId, m_row, m_col, m_rowCount, m_colCount);
		m->AddElement(base);
		Window* w = m->FindWindow(m_pId);
		if(w)
				w->AddChild(base);
}
