#include "start.h"

void CommandsShow()
{
		std::cout<<"Available commands ։ \n"
				<<"	add window <id> <pId> <row> <col> <rowCount> <colCount>\n"
				<<"	add table  <id> <pId> <row> <col> <rowCount> <colCount>\n"
				<<"	add text   <id> <pId> <row> <col> <text>\n"
				<<"	add button <id> <pId> <row> <col> <text>\n"
				<<"Show\n"
				<<"Exit"<<std::endl;
}
std::vector<std::string> GetCommandsLine()
{
		std::string line;
		std::cout<< " < ";
		getline(std::cin, line);
		std::vector<std::string> CommandsLine;

		std::string word;
		std::stringstream ss(line);
		while(ss>>word)
		{
				CommandsLine.push_back(word);
		}
		return CommandsLine;
}

void GetFirstWindow( std::vector<std::string>& v )
{
		std::cout<<"Command Line Application (CLI)\n"<<
					"------------------------------\n"<<
					"First wondow : enter ID , rowCount and colCount\n"<<std::endl;
		while(true)
		{
				v = GetCommandsLine();
				if(v.size() == 3 )
				{
						int id=std::stoi(v.at(0));
						int rowCount = std::stoi(v.at(1));
						int colCount = std::stoi(v.at(2));
						if(rowCount > 0 && colCount > 0 )
						{
							Command* cmd = new Add_F_WindowCommand(id, rowCount, colCount);	
							//inv.executeComand(cmd);
							cmd->execute();
							break;
						}
				}
				else 
						std::cout << "Error: wrong command" << std::endl;
		}
}
void DoCommand(const std::vector<std::string>& v, bool& quit)
{
		int v_Size= v.size();
		std::string sCmdName = v.at(0);
		if((sCmdName == "Show" || sCmdName == "show") && v_Size == 1)
		{
				std::cout<<"Enter Pid : ";
				std::string input;
				std::cin >> input ;
				std::regex digits("^-?[0-9]+$");
				if(std::regex_match(input, digits))
				{
					int showPid = std::stoi(input);
					Manage::GetInstance()->Print(showPid);
				}
				else 
					std::cout << "Error:: Invalid input\n";

		}
		else if((sCmdName == "Exit" || sCmdName == "exit") && v_Size == 1) 
				quit=false;	
		else if(sCmdName=="add")
		{
			Command* cmd = CommandFactory::CreateCommand(v);
			if(cmd) 
					cmd->execute();

		}
		else
				std::cout << "Error: wrong command" << std::endl;
}

void GetCommands()
{
		bool quit = true;
		std::vector<std::string> args;
		GetFirstWindow( args );
		if(!quit)
			return;
		CommandsShow();
		while(quit)
		{
				args = GetCommandsLine();
				if(args.empty()) continue ;
				DoCommand(args, quit);
		}
}
