#include "button.h"
std::string Button::getButton() const { return m_button;}
void Button::Print()const 
{
	std::cout<<"Button : id " << getId()<<", button : "<< getButton()<<" ("<<getRow()<<','<<getCol()<<") "; 
}
