#include "button.h"
std::string Button::GetButton() const { return m_button;}
void Button::Draw()const 
{
	std::cout<<"Button : id " << GetId()<<", button : "<< GetButton()<<" ("<<GetRow()<<','<<GetCol()<<") "; 
}
