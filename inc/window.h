#pragma once
#include "base.h"
#include "manage.h"
#include <map>
class Window: public Base
{
	private:
		int m_rowCount;
		int m_colCount;
		std::map<int, Base*> m_children;
	public:
		Window(int id, int rowCount, int colCount, int pId , int row , int col)
			: Base( id, row, col, pId)
			  , m_rowCount(rowCount)
			  , m_colCount(colCount) 
	{}

		Window(int id, int rowCount, int colCount)
			:Window(id, rowCount, colCount, -1 , -1, -1)
	{}
		Window(int id, int rowCount, int colCount, int pId)
			:Window(id, rowCount , colCount , pId, -1 , -1)
	{}
		int GetRowCount()const;
		int GetColCount()const;
		bool IsPositionFree(int row, int col)const;
		void AddChild(Base* child);
		const std::map<int, Base*>& GetChildren()const;
		void Draw()const override;
		void Print2(Window* w)const ;
};
