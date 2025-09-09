#include "commandFactory.h"

Command* CommandFactory::CreateCommand(const std::vector<std::string>& args)
{
		int args_Size= args.size();

		if(args.at(0) == "add" && (args_Size==8 || args_Size==7))
		{
				int id, pId, row, col, rowCount, colCount ;
				try
				{
						id = std::stoi(args[2]);
						pId = std::stoi(args[3]);
						row = std::stoi(args[4]);
						col = std::stoi(args[5]);
				}
				catch(const std::invalid_argument& e )
				{
						std::cout<<"Error : invalid argument"<<std::endl;
						return nullptr;
				}

				std::string sClassName = args.at(1);
				if(sClassName == "window" &&  args_Size == 8)
				{
						try
						{
							rowCount = std::stoi(args[6]);
							colCount = std::stoi(args[7]);
						}
						catch(const std::invalid_argument& e )
						{
							std::cout<<"Error : invalid argument"<<std::endl;
							return nullptr;
						}
						return new Add_WindowCommand(id, pId, row, col, rowCount, colCount);
				}
				else if(sClassName == "text" && args_Size == 7)
				{
						std::string text = args[6];
						return new Add_TextCommand( id, pId, row, col ,text);
				}
				else if(sClassName == "table" && args_Size == 8)
				{
						try
						{
							rowCount = std::stoi(args[6]);
							colCount = std::stoi(args[7]);
						}	
						catch(const std::invalid_argument& e )
						{
							std::cout<<"Error : invalid argument"<<std::endl;
							return nullptr;
						}
						return new Add_TableCommand( id, pId, row, col , rowCount, colCount);
				}
				else if(sClassName == "button" && args_Size == 7)
				{
						std::string button = args[6];
						return new Add_ButtonCommand( id, pId, row, col , button);
				}
		}
		std::cout<<"Error: wrong command" <<std::endl;
		return nullptr;
}
