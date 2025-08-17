#pragma once
#include "window.h"
#include "text.h"
#include "button.h"
#include "table.h"
#include "command.h"
class Manage{
	private:
		std::vector<Base*> m_v;
	public:
		Manage(){}
		virtual~Manage()
		{
			for(Base* a : m_v)
				delete a;
		}
		bool CheckId(int id);
		bool CheckPId(int Pid);
		bool CheckPosition(int row, int col, int index );
		int FindIndex(int pId);
		Base* FindWindow(int pId);
		bool CheckRange(int row, int col, int index );
		void AddElement(Base* base);
		void Print(int showPid);
};
