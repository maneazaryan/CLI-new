#include "invorker.h"

void Invorker::executeComand(Command* com)
{
		if(!com) return;
//		m_history.push_back(c);
		com->execute();
}
Invorker::~Invorker ()
{
		for (auto c : m_history) 
			delete c;
}

/*
Command* Invorker::GetCmd()
{
	return m_cmd;
}

void Invorker::SetCmd( Command* cmd )
{
	m_cmd = cmd;
}

Command* Invorker::createCommand(std::string name, std::vector<std::string> v)
{
		int v_Size= v.size();

		if(name == "add" && (v_Size==8 || v_Size==7))
		{
				int id, pId, row, col;
				try
				{
						id = std::stoi(v[2]);
						pId = std::stoi(v[3]);
						row = std::stoi(v[4]);
						col = std::stoi(v[5]);
				}
				catch(const std::invalid_argument& e )
				{
					std::cout<<"Error : invalid argument"<<std::endl;
					return NULL;
				}

				std::string sClassName = v.at(1);
				if(sClassName == "window" &&  v_Size == 8)
				{
						int rowCount = std::stoi(v[6]);
						int colCount = std::stoi(v[7]);
						m_cmd = new Add_WindowCommand(id, pId, row, col, rowCount, colCount);
				}
				else if(sClassName == "text" && v_Size == 7)
				{
						std::string text = v[6];
						m_cmd = new Add_TextCommand( id, pId, row, col ,text);
						//inv.executeComand(com);
				}
				else if(sClassName == "table" && v_Size == 8)
				{
						int rowCount = std::stoi(v[6]);
						int colCount = std::stoi(v[7]);
						m_cmd = new Add_TableCommand( id, pId, row, col , rowCount, colCount);
						//inv.executeComand(com);	
				}
				else if(sClassName == "button" && v_Size == 7)
				{
						std::string button = v[6];
						m_cmd = new Add_ButtonCommand( id, pId, row, col , button);
						//inv.executeComand(com);	
				}
				else 
						std::cout<<"Wrong add command"<<std::endl;
		}
		else 
				std::cout << "Error: wrong command" << std::endl;

	return nullptr;
}
*/
