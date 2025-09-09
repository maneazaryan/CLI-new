#pragma once
#include <iostream>
#include "base.h"
#include "manage.h"
#include <vector>
class Window: public Base
{
		private:
				int m_rowCount;
				int m_colCount;
				std::vector< Base*> m_children;
		public:
				Window(int id,int pId,  int row , int col,int rowCount, int colCount );
				Window(int id, int pId, int rowCount, int colCount);
				int GetRowCount()const;
				int GetColCount()const;
				bool IsPositionFree(int row, int col)const;
				void AddChild(Base* child);
				const std::vector< Base*>& GetChildren()const;
				void Draw()const override;
//test for me 
				void Show(Window* w)const ;
};
