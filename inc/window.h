#pragma once
#include <iostream>	
#include <vector>
#include "base.h"
#include "manage.h"
class Window: public Base
{
	private:
		int m_rowCount;
		int m_colCount;
		std::vector<Base*> m_children;


	public:
		Window(
				int id
				, int rowCount
				, int colCount
				, int pId 
				, int row 
				, int col)
			: Base( id, row, col, pId)
			  , m_rowCount(rowCount)
			  , m_colCount(colCount) 
	{}

		Window(
				int id
				, int rowCount
				, int colCount)
			: Base( id, -1, -1, -1)
			  , m_rowCount(rowCount)
			  , m_colCount(colCount) 
	{}
		Window(
				int id
				, int rowCount
				, int colCount
				, int pId)
			:Base( id, -1, -1, pId)
			 , m_rowCount(rowCount)
			 , m_colCount(colCount)
	{}

		int getRowCount()const;
		int getColCount()const;
		void AddChild(Base* child);
		const std::vector<Base*>& getChildren()const;
		void Print()const override;
		void Print2(Window* w)const ;
};
