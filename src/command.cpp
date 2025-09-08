#include "command.h"

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

void GetFirstWindow(Manage* m, bool& quit,std::vector<std::string>& v, Invorker& inv )
{
		std::cout<<"Command Line Application (CLI)\n"<<
					"------------------------------\n"<<
					"First wondow : enter ID , rowCount and colCount\n"<<
					"Type Exit to quit"<<std::endl;
		bool quitF = true;
		while(quitF)
		{
				v = GetCommandsLine();
				if(v.at(0) == "Exit" || v.at(0) == "exit") 
				{	
						quit = false;
						quitF = false;
				}
				else if(v.size() == 3 )
				{
						int id=std::stoi(v.at(0));
						int rowCount = std::stoi(v.at(1));
						int colCount = std::stoi(v.at(2));
						quitF = false;
						Command* cmd = new Add_F_WindowCommand(m,id, rowCount, colCount);	
						inv.executeComand(cmd);
				}
				else 
						std::cout << "Error: wrong command" << std::endl;
		}
}
void DoCommand(const std::vector<std::string>& v, Manage* m, bool& quit, Invorker& inv)
{
		if(v.empty()) return;
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
					m->Print(showPid);
				}
				else 
					std::cout << "Error:: Invalid input\n";

		}
		else if((sCmdName == "Exit" || sCmdName == "exit") && v_Size == 1) 
				quit=false;
		else if(sCmdName == "add" && (v_Size==8 || v_Size==7))
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
					return;
				}

				std::string sClassName = v.at(1);
				if(sClassName == "window" &&  v_Size == 8)
				{
						int rowCount = std::stoi(v[6]);
						int colCount = std::stoi(v[7]);
						Command* com = new Add_WindowCommand(m, id, pId, row, col, rowCount, colCount) ;
						inv.executeComand(com);	
				}
				else if(sClassName == "text" && v_Size == 7)
				{
						std::string text = v[6];
						Command* com = new Add_TextCommand(m,id, pId, row, col ,text);
						inv.executeComand(com);
				}
				else if(sClassName == "table" && v_Size == 8)
				{
						int rowCount = std::stoi(v[6]);
						int colCount = std::stoi(v[7]);
						Command* com = new Add_TableCommand(m,id, pId, row, col , rowCount, colCount);
						inv.executeComand(com);	
				}
				else if(sClassName == "button" && v_Size == 7)
				{
						std::string button = v[6];
						Command* com = new Add_ButtonCommand(m,id, pId, row, col , button);
						inv.executeComand(com);	
				}
				else 
						std::cout<<"Wrong add command"<<std::endl;
		}
		else 
				std::cout << "Error: wrong command" << std::endl;
}

void GetCommands(Manage* m)
{
		Invorker inv;
		bool quit = true;
		std::vector<std::string> v;
		GetFirstWindow(m, quit, v, inv );
		if(!quit)
			return;
		CommandsShow();
		while(quit)
		{
				v = GetCommandsLine();
				DoCommand(v, m, quit, inv);
		}
}
