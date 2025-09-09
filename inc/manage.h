#pragma once
#include "window.h"
#include "text.h"
#include "button.h"
#include "table.h"
#include "start.h"
#include <map>
class Window;
class Manage{
		private:
				static Manage* m_pManage; 
				std::multimap<int, Base*> m_v;
		private:
				Manage(){}
		public:
				virtual~Manage();
				static Manage* GetInstance();
				bool CheckId(int id);
				bool CheckPId(int Pid);
				bool CheckPosition(int row, int col, int pId);
				bool CheckRange(int row, int col, int pId);
 				bool M_CheckParametrs( int m_id, int m_pId, int m_col, int m_row);
				Window* FindWindow(int pId);
				void AddElement(Base* base);
//test for me
				void Print(int showPid);
};
