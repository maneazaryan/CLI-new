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
		std::vector<std::vector<Base*>> m_V;
	public:
		Manage(){}
		virtual~Manage(){
			for(int i=0; i<static_cast<int>(m_V.size());i++){
				for(int j=0; j<static_cast<int>(m_V[i].size());j++){
					delete m_V[i][j];
					m_V[i][j]=nullptr;
				}
			}
		}
		bool checkId(int id);
		int findPid(int pId);
		bool checkRange(int row, int col, int rowN );
		void AddElement(Base* base);
		void print();
};
