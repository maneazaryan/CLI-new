#include "text.h"
Text::Text(int id, int pId, int row, int col, std::string text):
		Base(id, pId, row, col  ), m_text(text) {}

std::string Text::GetText()const{return m_text;}
void Text::Draw() const
{
		std::cout<<"Text  " << GetId() << " ";
}
