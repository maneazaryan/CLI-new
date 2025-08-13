#include "table.h"      
int Table::getTableRow()const{return m_tableRow;}
int Table::getTableCol()const{return m_tableCol;}          
void Table::Print() const
{
	std::cout<<"Table : id "<< getId()<<", size ( "<< getTableRow()<<", "<<getTableCol()<<") in ("<<getRow()<<','<<getCol()<<") ";
}
