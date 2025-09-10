#pragma once
#include <iostream>	
#include <vector>
#include <memory>
#include "parser.h"
#include "base.h"
#include "window.h"
#include "commandFactory.h"
#include "command.h"

class Start
{
	private :
		static Start* m_Start;
		bool m_bQuit = true;
	private:
		Start(){};
		Start(const Start&) = delete;
    	Start& operator=(const Start&) = delete;
		void CommandsShow();
		void GetFirstWindow(std::vector<std::string>& v);
	public :
		bool GetQuit();
		void SetQuit();
		static Start* GetInstance();
		static void DeleteInstance();
		void GetCommands();
};
