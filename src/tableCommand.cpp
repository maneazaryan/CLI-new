#include "tableCommand.h"
Add_TableCommand::Add_TableCommand(const std::vector<std::string>& args)
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
				return ;
        }

}
void Add_TableCommand::execute()
{
		std::unique_ptr<Checker> checker = std::make_unique<Checker>();
		if(!(checker->M_CheckParametrs( m_id, m_pId, m_row, m_col) ))
				return;
		std::shared_ptr<Base> base = std::make_shared<Table>(m_id, m_pId, m_row, m_col, m_rowCount, m_colCount);
		m_pManage->AddElement(base);
		std::shared_ptr<Window> w = m_pManage->FindWindow(m_pId);
		if(w)
				w->AddChild(base);
}
