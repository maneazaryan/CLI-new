#include "show.h"
Show::Show(const std::vector<std::string>& args)
{
		try
		{
				std::string input = args.at(1);
				std::regex digits("^-?[0-9]+$");
				if(std::regex_match(input, digits))
				{
					m_showPid = std::stoi(input);
				}
		}
		catch(const std::invalid_argument& e )
		{
				std::cout<<"Error : invalid input"<<std::endl;
				return;
		}
}
void Show::execute() 
{
		std::unique_ptr<WindowPrinter> print = std::make_unique<WindowPrinter>();
		print->Print(m_showPid);
}
