#pragma once
#include <iostream>
#include <vector>
#include "base.h"
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
		virtual~Manage(){}
		bool checkId(int id);
		bool checkPId(int Pid);
		bool ckeckPosition(int row, int col);
		int findPid(int pId);
		Base* findWindow(int pId);
		bool checkRange(int row, int col, int rowN );
		void AddElement(Base* base);
		void print();
};
