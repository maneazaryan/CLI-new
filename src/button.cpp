#include "button.h"
Button::Button (int id, int pId, int row , int col, std::string button):
          Base(id, pId, row, col ), m_button(button) {}

std::string Button::GetButton() const { return m_button;}
void Button::Draw()const 
{
	std::cout<<"Button " << GetId()<<" "; 
}
