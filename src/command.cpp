#include "command.h"
void commandsShow()
{
	std::cout<<"Available commands ։ "<<std::endl;
	std::cout<<"    add window <id> <rowCount> <colCount> [pId=-1] [row=-1] [col=-1]"<<std::endl;
	std::cout<<"    add text <id> <text> <pId> <row> <col>"<<std::endl;
	std::cout<<"    add table <id> <rowCount> <colCount> <pId> <row> <col>"<<std::endl;
	std::cout<<"    add button <id> <text> <pId> <row> <col>"<<std::endl;
	std::cout<<"Show"<<std::endl;
	std::cout<<"Exit"<<std::endl;
}
std::vector<std::string> getCommandsLine()
{
	std::string line;
	std::cout<< " < ";
	getline(std::cin, line);

	std::vector<std::string> commandsLine;

	std::string word;
	std::stringstream ss(line);
	while(ss>>word)
	{
		commandsLine.push_back(word);
	}
	return commandsLine;
}

void getFirstWindow(Manage& m)
{
	std::cout<<"Command Line Application (CLI)"<<std::endl;
	std::cout<<"Enter the first wondow's id, rowCount and colCount \n Type Exit to quit"<<std::endl;
	bool quitF = false;
	std::vector<std::string> v;
	while(!quitF)
	{
		v = getCommandsLine();
		if(v.size()==3)
		{
			int id=std::stoi(v[0]);
			int rowCount = std::stoi(v[1]);
			int colCount = std::stoi(v[2]);
			Base* base = new Window(id,rowCount,colCount);
			m.AddElement(base);
			quitF = true;
		}
		else if(v[0] == "Exit" || v[0] == "exit") 
			quitF = true;
		else 
		     std::cout << "Error: wrong command" << std::endl;
	}
}
void doCommand(const std::vector<std::string>& v, Manage& m, bool& quit)
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
			if(m.checkId(id) ) 
			{
				if(!(m.checkRange(row,col, 0) && m.ckeckPosition(row,col)))
				{
					std::cout<<"Error : out of range"<<std::endl;
					return;
				}
				Window* base = new Window(id, rowCount, colCount, pId, row, col);
				m.AddElement(base);
				if(m.checkPId(pId))
				{
					pId+=1;
					Window* base = new Window(id, rowCount, colCount, pId , row, col);
					base->AddChild(base);
					m.AddElement(base);
				}
			}
		}
		else if(v[1] == "text" && v.size() == 7)
		{
			int id = std::stoi(v[2]);
			if(m.checkId(id))
			{
				std::string text = v[3];
				int pId = std::stoi(v[4]);
				int row = std::stoi(v[5]);
				int col = std::stoi(v[6]);
				if(!m.checkRange(row,col, 0))
				{
					std::cout<<"Error : out of range"<<std::endl;
					return;
				}
				Base* base = new Text(id, text,pId, row, col);
				m.AddElement(base);
			}
		}
		else if(v[1] == "table" && v.size() == 8)
		{
			int id = std::stoi(v[2]);
			if(m.checkId(id)){
				int rowCount = std::stoi(v[3]);
				int colCount = std::stoi(v[4]);
				int pId = std::stoi(v[5]);
				int row = std::stoi(v[6]);
				int col = std::stoi(v[7]);
				if(!m.checkRange(row,col, 0))
				{
					std::cout<<"Error : out of range"<<std::endl;
					return;
				}
				Base* base = new Table(id,rowCount, colCount,pId, row, col);
				m.AddElement(base);
			}
		}
		else if(v[1] == "button" && v.size() == 7)
		{
			int id = std::stoi(v[2]);
			if(m.checkId(id)){
				std::string button = v[3];
				int pId = std::stoi(v[4]);
				int row = std::stoi(v[5]);
				int col = std::stoi(v[6]);
				if(!m.checkRange(row,col, 0))
				{
					std::cout<<"Error : out of range"<<std::endl;
					return;
				}
				Base* base = new Button(id, button, pId, row, col);
				m.AddElement(base);
			}
		}
		else std::cout<<"Wrong add command"<<std::endl;
	}
	else if(v[0] == "Show" || v[0] == "show") m.print();
	else if(v[0] == "Exit" || v[0] == "exit") quit=false;
	else {
		std::cout << "Error: wrong command" << std::endl;
	}
}
void getCommands(Manage& m)
{
	bool bstopRec;
	getFirstWindow(m);
	commandsShow();
	bool quit = true;
	std::vector<std::string> v;
	while(quit)
	{
		v = getCommandsLine();
		doCommand(v,m,quit);
	}
	//	getFirstWindow(m);
}
