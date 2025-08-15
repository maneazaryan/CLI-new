#include "command.h"
void CommandsShow()
{
	std::cout<<"Available commands ։ "<<std::endl;
	std::cout<<"    add window <id> <rowCount> <colCount> <pId> <row> <col>"<<std::endl;
	std::cout<<"    add text <id> <text> <pId> <row> <col>"<<std::endl;
	std::cout<<"    add table <id> <rowCount> <colCount> <pId> <row> <col>"<<std::endl;
	std::cout<<"    add button <id> <text> <pId> <row> <col>"<<std::endl;
	std::cout<<"Show"<<std::endl;
	std::cout<<"Exit"<<std::endl;
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

void GetFirstWindow(Manage& m)
{
	std::cout<<"Command Line Application (CLI)"<<std::endl;
	std::cout<<"------------------------------"<<std::endl;
	std::cout<<"First wondow : enter ID , rowCount and colCount"<<std::endl;
	std::cout<<"Type Exit to quit"<<std::endl;
	bool quitF = false;
	std::vector<std::string> v;
	while(!quitF)
	{
		v = GetCommandsLine();
		if(v.size() == 3 )
		{
			int id=std::stoi(v[0]);
			int rowCount = std::stoi(v[1]);
			int colCount = std::stoi(v[2]);
			Base* base = new Window(id, rowCount, colCount);
			m.AddElement(base);
			quitF = true;
			std::cout <<"-------------------------" <<std::endl;
			std::cout <<"-1 is pId of the first window" <<std::endl;
			std::cout <<"-------------------------" <<std::endl;
		}
		else if(v[0] == "Exit" || v[0] == "exit") 
			quitF = true;
		else 
		     std::cout << "Error: wrong command" << std::endl;
	}
}
void DoCommand(const std::vector<std::string>& v, Manage& m, bool& quit)
{
	if(v.empty()) return;
	if(v[0] == "add")
	{
		if(v[1] == "window" &&  v.size() == 8)
		{
			int id = std::stoi(v[2]);
			int rowCount = std::stoi(v[3]);
			int colCount = std::stoi(v[4]);
			int pId = std::stoi(v[5]);
			int row = std::stoi(v[6]);
			int col = std::stoi(v[7]);
			if(m.CheckId(id) && m.CheckPId(pId))
			{
				int index  = m.FindIndex(pId);
				if(!(m.CheckRange(row, col, index) && m.CheckPosition(row,col)))
				{
					return;
				}
				Window* base = new Window(id, rowCount, colCount, pId, row, col);
				m.AddElement(base);

				int newpId=id;
				std::cout <<"-------------------------" <<std::endl;
				std::cout << newpId <<" is pId of new window" <<std::endl;
				std::cout <<"-------------------------" <<std::endl;

				Window* base2 = new Window(id, rowCount, colCount, newpId );
				m.AddElement(base2);

				Base* p = m.FindWindow(pId);
			 	Window* w = dynamic_cast<Window*>(p);
				if(w)
				{
				std::cout <<"-------------------------" <<std::endl;
					w->AddChild(base);
				}
			}
		}
		else if(v[1] == "text" && v.size() == 7)
		{
			int id = std::stoi(v[2]);
			std::string text = v[3];
			int pId = std::stoi(v[4]);
			int row = std::stoi(v[5]);
			int col = std::stoi(v[6]);
			if(m.CheckId(id) && m.CheckPId(pId))
			{
				int index  = m.FindIndex(pId);
				if(!(m.CheckRange(row, col, index) && m.CheckPosition(row,col)))
				{
					return;
				}
				Base* b = new Text(id, text, pId, row, col);
				m.AddElement(b);
				Base* p = m.FindWindow(pId);
				Window* w = dynamic_cast<Window*>(p);
				if(w)
				{
					w->AddChild(b);
				}
			}
		}
		else if(v[1] == "table" && v.size() == 8)
		{
			int id = std::stoi(v[2]);
			int rowCount = std::stoi(v[3]);
			int colCount = std::stoi(v[4]);
			int pId = std::stoi(v[5]);
			int row = std::stoi(v[6]);
			int col = std::stoi(v[7]);
			if(m.CheckId(id) && m.CheckPId(pId)){
				int index = m.FindIndex(pId);
				if(!(m.CheckRange(row, col, index) && m.CheckPosition(row,col)))
				{
					return;
				}
				Base* base = new Table(id,rowCount, colCount,pId, row, col);
				m.AddElement(base);

				Base* p = m.FindWindow(pId);
				Window* w = dynamic_cast<Window*>(p);
				if(w)
				{
					w->AddChild(base);
				}
			}
		}
		else if(v[1] == "button" && v.size() == 7)
		{
			int id = std::stoi(v[2]);
				std::string button = v[3];
				int pId = std::stoi(v[4]);
				int row = std::stoi(v[5]);
				int col = std::stoi(v[6]);
			if(m.CheckId(id) && m.CheckPId(pId)){
				int index = m.FindIndex(pId);
				if(!(m.CheckRange(row, col, index) && m.CheckPosition(row,col)))
				{
					return;
				}
				Base* base = new Button(id, button, pId, row, col);
				m.AddElement(base);
				Base* p = m.FindWindow(pId);
				Window* w = dynamic_cast<Window*>(p);
				if(w)
				{
					w->AddChild(base);
				}
			}
		}
		else std::cout<<"Wrong add command"<<std::endl;
	}
	else if((v[0] == "Show" || v[0] == "show") && v.size() == 1)
	{
		std::cout<<"Enter Pid : ";
		int showPid;
		std::cin>>showPid ;
		m.Print(showPid);
	}
	else if((v[0] == "Exit" || v[0] == "exit") && v.size() == 1) quit=false;
	else {
		std::cout << "Error: wrong command" << std::endl;
	}
}
void GetCommands(Manage& m)
{
	GetFirstWindow(m);
	CommandsShow();
	bool quit = true;
	std::vector<std::string> v;
	while(quit)
	{
		v = GetCommandsLine();
		DoCommand(v,m,quit);
	}
}
