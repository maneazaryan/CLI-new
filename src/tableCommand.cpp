#include "tableCommand.h"

Add_TableCommand::Add_TableCommand(int id, int pId, int row, int col, int rowCount, int colCount )
                       : m_id(id), m_pId(pId), m_row(row), m_col(col)
                       , m_rowCount(rowCount), m_colCount(colCount) 
{
   m_pManage = Manage::GetInstance();
}
void Add_TableCommand::execute()
{
		std::unique_ptr<Checker> checker = std::make_unique<Checker>();
		if(!(checker->M_CheckParametrs( m_id, m_pId, m_row, m_col) ))
				return;
		Base* base = new Table(m_id, m_pId, m_row, m_col, m_rowCount, m_colCount);
		m_pManage->AddElement(base);
		Window* w = m_pManage->FindWindow(m_pId);
		if(w)
				w->AddChild(base);
}
