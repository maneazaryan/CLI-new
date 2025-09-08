#include "windowCommand.h"
Add_WindowCommand::Add_WindowCommand(Manage* mm, int id, int pId, int row, int col,  int rowCount, int colCount)
         :
		  m (mm)
         , m_id(id), m_pId(pId)
         , m_row(row), m_col(col)
         , m_rowCount(rowCount), m_colCount(colCount){}

void Add_WindowCommand::execute()
{
		if(!(m->M_CheckParametrs( m_id, m_pId, m_row, m_col)))
		{
				return;
		}
		if(m_id==-1)
		{
				std::cout<<"-1 is Root window Pid, you can't use is as an id"<<std::endl;
				return;
		}
		Base* base = new Window(m_id, m_pId, m_row , m_col, m_rowCount, m_colCount);
		m->AddElement(base);

		int newPid=m_id;
		Base* base2 = new Window(m_id, newPid, m_row, m_col, m_rowCount, m_colCount );
		m->AddElement(base2);

		Window* p = m->FindWindow(m_pId);
		if(p)
		{
				p->AddChild(base2);
		}
		std::cout <<"-------------------------" <<std::endl;
		std::cout << newPid<<" is pId of new window" <<std::endl;
		std::cout <<"-------------------------" <<std::endl;
}
