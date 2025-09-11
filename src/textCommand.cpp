#include "textCommand.h"
Add_TextCommand::Add_TextCommand(const std::vector<std::string>& args)
{
		m_pManage = Manage::GetInstance();
		try
		{
				m_id  = std::stoi(args[2]);
				m_pId = std::stoi(args[3]);
				m_row = std::stoi(args[4]);
				m_col = std::stoi(args[5]);
		}
		catch(const std::invalid_argument& e ) 
		{
				std::cout<<"Error : invalid argument"<<std::endl;
				return ;
		}
		m_text = args[6];
}
void Add_TextCommand::execute()
{
		std::unique_ptr<Checker> checker = std::make_unique<Checker>();
		if(!(checker -> M_CheckParametrs( m_id, m_pId, m_row, m_col)))
				return;
		std::shared_ptr<Base> b = std::make_shared<Text>(m_id, m_pId, m_row, m_col, m_text);
		m_pManage->AddElement(b);
		std::shared_ptr<Window> w = m_pManage->FindWindow(m_pId);
		if(w)
				w->AddChild(b);
}
