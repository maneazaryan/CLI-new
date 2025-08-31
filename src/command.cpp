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

void GetFirstWindow(Manage* m, bool& quit )
{
		std::cout<<"Command Line Application (CLI)\n"<<
					"------------------------------\n"<<
					"First wondow : enter ID , rowCount and colCount\n"<<
					"Type Exit to quit"<<std::endl;
		std::vector<std::string> v;
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
						Base* base = new Window(id, rowCount, colCount);
						m->AddElement(base);
						quitF = false;
						std::cout <<"-------------------------" <<std::endl;
						std::cout <<"-1 is pId of the first window" <<std::endl;
						std::cout <<"-------------------------" <<std::endl;
				}
				else 
						std::cout << "Error: wrong command" << std::endl;
		}
}

void DoCommand(const std::vector<std::string>& v, Manage* m, bool& quit)
{
		if(v.empty()) return;
		int v_Size= v.size();
		// std::string sCmdName = v[0];
		if((v.at(0) == "Show" || v.at(0)== "show") && v_Size == 1)
		{
				std::cout<<"Enter Pid : ";
				int showPid;
				std::cin>>showPid ;
				m->Print(showPid);
		}
		else if((v.at(0) == "Exit" || v.at(0) == "exit") && v_Size == 1) 
				quit=false;
		else if(v[0] == "add" && (v_Size==8 || v_Size==7))
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

				// std::string sClassName = v.at(1);
				// std::string sClassId = sdt::stoi(v[2]);
				if(v[1] == "window" &&  v_Size == 8)
				{

						int rowCount = std::stoi(v[6]);
						int colCount = std::stoi(v[7]);
						if(!(m->CheckId(id)	 && 
												m->CheckPId(pId) &&
												m->CheckRange(row, col, pId) && 
												m->CheckPosition(row,col,pId)))
						{
								return;
						}
						Base* base = new Window(id, rowCount, colCount, pId, row, col);
						m->AddElement(base);

						int newpId=id;
						std::cout <<"-------------------------" <<std::endl;
						std::cout << newpId <<" is pId of new window" <<std::endl;
						std::cout <<"-------------------------" <<std::endl;

						Base* base2 = new Window(id, rowCount, colCount, newpId );
						m->AddElement(base2);

						Base* p = m->FindWindow(pId);
						Window* w = dynamic_cast<Window*>(p);
						if(w)
						{
								w->AddChild(base);
						}	
				}
				else if(v[1] == "text" && v_Size == 7)
				{
						std::string text = v[6];
						if(!(m->CheckId(id) && 
												m->CheckPId(pId)&&
												m->CheckRange(row, col, pId) && 
												m->CheckPosition(row,col,pId)))
						{
								return;
						}
						Base* b = new Text(id, text, pId, row, col);
						m->AddElement(b);
						Base* p = m->FindWindow(pId);
						Window* w = dynamic_cast<Window*>(p);
						if(w)
						{
								w->AddChild(b);
						}
				}
				else if(v[1] == "table" && v_Size == 8)
				{
						int rowCount = std::stoi(v[6]);
						int colCount = std::stoi(v[7]);
						if(!(m->CheckId(id) && 
												m->CheckPId(pId)&&
												m->CheckRange(row, col, pId) && 
												m->CheckPosition(row, col, pId)))
						{
								return;
						}
						Base* base = new Table(id, rowCount, colCount, pId, row, col);
						m->AddElement(base);

						Base* p = m->FindWindow(pId);
						Window* w = dynamic_cast<Window*>(p);
						if(w)
						{
								w->AddChild(base);
						}
				}
				else if(v[1] == "button" && v_Size == 7)
				{
						std::string button = v[6];
						if(!(m->CheckId(id) && 
												m->CheckPId(pId)&&
												m->CheckRange(row, col, pId) && 
												m->CheckPosition(row, col, pId)))
						{
								return;
						}
						Base* base = new Button(id, button, pId, row, col);
						m->AddElement(base);
						Base* p = m->FindWindow(pId);
						Window* w = dynamic_cast<Window*>(p);
						if(w)
						{
								w->AddChild(base);
						}
				}
				else 
						std::cout<<"Wrong add command"<<std::endl;
		}
		else 
				std::cout << "Error: wrong command" << std::endl;
}

void GetCommands(Manage* m)
{
		bool quit = true;
		GetFirstWindow(m, quit);
		if(!quit)
			return;
		CommandsShow();
		std::vector<std::string> v;
		while(quit)
		{
				v = GetCommandsLine();
				DoCommand(v,m,quit);
		}
}
