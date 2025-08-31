#include "table.h"      
int Table::GetTableRow()const{return m_tableRow;}
int Table::GetTableCol()const{return m_tableCol;}          
void Table::Draw() const
{
	std::cout<<"Table : id "<< GetId()<<", size ( "<< GetTableRow()<<", "<<GetTableCol()<<") in ("<<GetRow()<<','<<GetCol()<<") ";
}
