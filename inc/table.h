#pragma once
#include "base.h"
class Table: public Base{
		private:
				int m_tableRow;
				int m_tableCol;
		public:
				Table(int id, int pId, int row, int col , int tableRow, int tableCol);
				int GetTableRow()const;
				int GetTableCol()const;
				virtual void Draw()const override;
};
