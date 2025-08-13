#include "text.h"
std::string Text::getText()const{return m_text;}
void Text::Print() const
{
	std::cout<<"Text"<<m_text;
	std::cout<<"Text : id " << getId()<<", text : "<< getText()<<" ("<<getRow()<<','<<getCol()<<") ";
}
