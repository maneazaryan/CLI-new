#include "fwindowCommand.h"
Add_F_WindowCommand::Add_F_WindowCommand(int id,  int rowCount, int colCount)
                : m_id(id), m_rowCount(rowCount), m_colCount(colCount)
                {
                    m_pId=-1;
                }

void Add_F_WindowCommand::execute()
{
		Base* base = new Window(m_id, m_pId, m_rowCount, m_colCount );
		Manage::GetInstance()->AddElement(base);

		std::cout <<"-------------------------" <<std::endl;
		std::cout <<"-1 is pId of the first window" <<std::endl;
		std::cout <<"-------------------------" <<std::endl;
}
