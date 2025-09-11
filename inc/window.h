#pragma once
#include <iostream>
#include "base.h"
#include "manage.h"
#include <vector>
#include <memory>
class Window: public Base
{
		private:
				int m_rowCount;
				int m_colCount;
				std::vector< std::shared_ptr<Base>> m_children;
		public:
				Window(int id,int pId,  int row , int col,int rowCount, int colCount );
				Window(int id, int pId, int rowCount, int colCount);
				int GetRowCount()const;
				int GetColCount()const;
				void AddChild(std::shared_ptr<Base> child);
				const std::vector< std::shared_ptr<Base>>& GetChildren()const;
				void Draw()const override;
};
