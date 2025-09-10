#include "start.h"

Start* Start::m_Start = nullptr;
bool Start::GetQuit()
{
	return m_bQuit;
}
void Start::SetQuit()
{
	m_bQuit = false;
}
Start* Start::GetInstance()
{
	if(m_Start == nullptr)
	{
		m_Start = new Start();
	}
	return m_Start;
}
void Start::DeleteInstance()
{
	delete m_Start;
	m_Start = nullptr;
}
void Start::CommandsShow()
{
		std::cout<<"Available commands ։ \n"
				<<"	add window <id> <pId> <row> <col> <rowCount> <colCount>\n"
				<<"	add table  <id> <pId> <row> <col> <rowCount> <colCount>\n"
				<<"	add text   <id> <pId> <row> <col> <text>\n"
				<<"	add button <id> <pId> <row> <col> <text>\n"
				<<"Show + pId\n"
				<<"Exit"<<std::endl;
}
void Start::GetFirstWindow( std::vector<std::string>& v )
{
		std::cout<<"Command Line Application (CLI)\n"<<
					"------------------------------\n"<<
					"First wondow : enter ID , rowCount and colCount\n"<<std::endl;
		std::unique_ptr<Parser> parser = std::make_unique<Parser>();
		while(true)
		{
			v = parser -> ParseLine();
			v.push_back("first");
			Command* cmd = CommandFactory::CreateCommand(v);
			if(cmd) 
			{
					cmd->execute();
					break;
			}
		}
}
void Start::GetCommands()
{
		std::unique_ptr<Parser> parser = std::make_unique<Parser>();
		bool quit = true;

		std::vector<std::string> args;
		GetFirstWindow( args );
		if(! m_bQuit)
			return;
		CommandsShow();
		while(m_bQuit)
		{
				args = parser->ParseLine();
				if(args.empty()) continue ;
				Command* cmd = CommandFactory::CreateCommand(args);
				if(cmd) 
					cmd->execute();
		}
}
