#pragma once
#include "window.h"
#include "text.h"
#include "button.h"
#include "table.h"
#include "start.h"
#include <map>
#include <memory>
class Window;
class Manage{
		private:
				static Manage* m_pManage; 
				std::multimap<int, std::shared_ptr<Base>> m_mElements;
		private:
				Manage(){}
		public:
				virtual~Manage(){};
				Manage(const Manage&) = delete;
				Manage& operator=(const Manage&) = delete;
				static Manage* GetInstance();
				static void DeleteInstance();
				const std::multimap<int, std::shared_ptr<Base>>& GetElements() const ;
				std::shared_ptr<Window> FindWindow(int pId);
				void AddElement(std::shared_ptr<Base> base);
};
