#pragma once
#include "window.h"
#include "text.h"
#include "button.h"
#include "table.h"
#include "command.h"
#include <map>
class Manage{
		private:
				static Manage* m_pManage; 
				std::map<int, Base*> m_v;
				Manage(){}
		public:
				virtual~Manage()
				{
						for (std::map<int, Base*>::iterator it = m_v.begin(); it != m_v.end(); ++it)
								delete it->second;
				}
				static Manage* GetInstance();
				bool CheckId(int id);
				bool CheckPId(int Pid);
				bool CheckPosition(int row, int col, int pId);
				Base* FindWindow(int pId);
				bool CheckRange(int row, int col, int pId);
				void AddElement(Base* base);
				void Print(int showPid);
};
