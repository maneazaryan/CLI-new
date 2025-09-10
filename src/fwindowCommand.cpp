#include "fwindowCommand.h"
Add_F_WindowCommand::Add_F_WindowCommand(const std::vector<std::string>& args)
{
		m_pId      = -1;
		try
		{
				m_id       = std::stoi(args.at(0));		
				m_rowCount = std::stoi(args.at(1));
				m_colCount = std::stoi(args.at(2));					
		}
		catch(const std::invalid_argument& e )
		{
				std::cout<<"Error : invalid argument"<<std::endl;
				return;
		}
}
void Add_F_WindowCommand::execute()
{
		Base* base = new Window(m_id, m_pId, m_rowCount, m_colCount );
		Manage::GetInstance()->AddElement(base);

		std::cout <<"-1 is pId of the first window" <<std::endl;
}
