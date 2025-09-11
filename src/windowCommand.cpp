#include "windowCommand.h"
Add_WindowCommand::Add_WindowCommand(const std::vector<std::string>& args)
{
		m_pManage = Manage::GetInstance();
		try
		{
				m_id       = std::stoi(args[2]);
				m_pId      = std::stoi(args[3]);
				m_row      = std::stoi(args[4]);
				m_col      = std::stoi(args[5]);
				m_rowCount = std::stoi(args[6]);
				m_colCount = std::stoi(args[7]);
		}
		catch(const std::invalid_argument& e )
		{
			std::cout<<"Error : invalid argument"<<std::endl;
			return;
		}
}

void Add_WindowCommand::execute()
{
		std::unique_ptr<Checker> checker = std::make_unique<Checker>();
		if(!(checker -> M_CheckParametrs( m_id, m_pId, m_row, m_col) 
			&& checker -> M_Check_Count(m_rowCount, m_colCount)))
		{
				return;
		}
		if(m_id==-1)
		{
				std::cout<<"-1 is Root window Pid, you can't use is as an id"<<std::endl;
				return;
		}
		std::shared_ptr<Base> base = std::make_shared<Window>(m_id, m_pId, m_row , m_col, m_rowCount, m_colCount);
		m_pManage->AddElement(base);

		int newPid=m_id;
		std::shared_ptr<Base> base2 = std::make_shared<Window>(m_id, newPid, m_row, m_col, m_rowCount, m_colCount );
		m_pManage->AddElement(base2);

		std::shared_ptr<Window> parent = m_pManage->FindWindow(m_pId);
		if(parent)
		{
				parent->AddChild(base2);
		}
		std::cout << newPid<<" is pId of new window" <<std::endl;
}
