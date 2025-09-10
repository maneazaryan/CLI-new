#include "start.h"

void CommandsShow()
{
		std::cout<<"Available commands ։ \n"
				<<"	add window <id> <pId> <row> <col> <rowCount> <colCount>\n"
				<<"	add table  <id> <pId> <row> <col> <rowCount> <colCount>\n"
				<<"	add text   <id> <pId> <row> <col> <text>\n"
				<<"	add button <id> <pId> <row> <col> <text>\n"
				<<"Show + pId\n"
				<<"Exit"<<std::endl;
}
void GetFirstWindow( std::vector<std::string>& v )
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
void DoCommand(const std::vector<std::string>& v, bool& quit)
{
		int v_Size= v.size();
		std::string sCmdName = v.at(0);
		if((sCmdName == "Exit" || sCmdName == "exit") && v_Size == 1) 
				quit=false;	
		else 
		{
			Command* cmd = CommandFactory::CreateCommand(v);
			if(cmd) 
					cmd->execute();
		}
}

void GetCommands()
{
		std::unique_ptr<Parser> parser = std::make_unique<Parser>();
		bool quit = true;

		std::vector<std::string> args;
		GetFirstWindow( args );
		if(!quit)
			return;
		CommandsShow();
		while(quit)
		{
				args = parser->ParseLine();
				if(args.empty()) continue ;
				DoCommand(args, quit);
		}
}
