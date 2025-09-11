#include "commandFactory.h"

std::shared_ptr<Command> CommandFactory::CreateCommand(const std::vector<std::string>& args)
{
		int args_Size= args.size();
		const std::string sName = args.at(0);

		if(args_Size == 4 && args.at(3)=="first")
				return std::make_shared<Add_F_WindowCommand>(args);
		else if(sName == "add" && (args_Size==8 || args_Size==7))
		{
			std::string sClassName = args.at(1);
			if(sClassName == "window" &&  args_Size == 8) 
					return std::make_shared<Add_WindowCommand>(args);
			else if(sClassName == "text" && args_Size == 7)
					return std::make_shared<Add_TextCommand>(args);
			else if(sClassName == "table" && args_Size == 8)
					return std::make_shared<Add_TableCommand>(args);
			else if(sClassName == "button" && args_Size == 7)
					return std::make_shared<Add_ButtonCommand>(args);
		}
		else if((sName == "show" || sName == "Show") && args_Size == 2)
			return std::make_shared<Show>(args);
		else if((sName == "Exit" || sName == "exit") && args_Size == 1)
			return std::make_shared<Exit>();
		std::cout<<"Error: wrong command" <<std::endl;
		return nullptr;
}
