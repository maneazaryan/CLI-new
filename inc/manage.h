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
				std::multimap<int, Base*> m_mElements;
		private:
				Manage(){}
		public:
				virtual~Manage();
				Manage(const Manage&) = delete;
				Manage& operator=(const Manage&) = delete;
				static Manage* GetInstance();
				static void DeleteInstance();
				std::multimap<int, Base*>GetElements() const ;
				Window* FindWindow(int pId);
				void AddElement(Base* base);
};
