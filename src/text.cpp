#include "text.h"
std::string Text::GetText()const{return m_text;}
void Text::Draw() const
{
	std::cout<<"Text"<<m_text;
	std::cout<<"Text : id " << GetId()<<", text : "<< GetText()<<" ("<<GetRow()<<','<<GetCol()<<") ";
}
