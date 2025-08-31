#pragma once
#include "base.h"
class Table: public Base{
		private:
				int m_tableRow;
				int m_tableCol;
		public:
				Table(int id, int tableRow, int tableCol, int pId, int row, int col ):
						Base(id, row, col, pId), m_tableRow(tableRow), m_tableCol(tableCol) {}
				int GetTableRow()const;
				int GetTableCol()const;
				virtual void Draw()const override;
};
