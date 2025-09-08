#include "table.h"      
Table::Table(int id, int pId, int row, int col , int rowCount, int colCount):
	Base(id, pId, row, col ), m_tableRow(rowCount), m_tableCol(colCount) {}

int Table::GetTableRow()const{return m_tableRow;}
int Table::GetTableCol()const{return m_tableCol;}          
void Table::Draw() const
{
	std::cout<<"Table "<< GetId()<< ' ';
}
