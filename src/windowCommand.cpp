#include "windowCommand.h"
Add_WindowCommand::Add_WindowCommand(int id, int pId, int row, int col,  int rowCount, int colCount)
         : m_id(id), m_pId(pId)
         , m_row(row), m_col(col)
         , m_rowCount(rowCount), m_colCount(colCount)

{
   m_pManage = Manage::GetInstance();
}

void Add_WindowCommand::execute()
{
		std::unique_ptr<Checker> checker = std::make_unique<Checker>();
		if(!(checker -> M_CheckParametrs( m_id, m_pId, m_row, m_col)))
		{
				return;
		}
		if(m_id==-1)
		{
				std::cout<<"-1 is Root window Pid, you can't use is as an id"<<std::endl;
				return;
		}
		Base* base = new Window(m_id, m_pId, m_row , m_col, m_rowCount, m_colCount);
		m_pManage->AddElement(base);

		int newPid=m_id;
		Base* base2 = new Window(m_id, newPid, m_row, m_col, m_rowCount, m_colCount );
		m_pManage->AddElement(base2);

		Window* parent = m_pManage->FindWindow(m_pId);
		if(parent)
		{
				parent->AddChild(base2);
		}
		std::cout << newPid<<" is pId of new window" <<std::endl;
}
