#include "parser.h"

const std::vector<std::string> Parser::ParseLine()const
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
