#include "window.h"

int Window::GetRowCount()const
{
	return m_rowCount;
}
int Window::GetColCount()const
{
	return m_colCount;
}
void Window::AddChild(Base* child) 
{
	m_children.push_back(child);
}
const std::vector<Base*>& Window::GetChildren()const
{
	return m_children;
}
void Window::Print()const{
	std::cout<<"Window : "<<GetId()<<std::endl;
}
void Window::Print2(Window* w)const{
	bool found ;
	for(int row = 0; row < w->GetRowCount(); row++)
	{
		for(int col = 0 ; col < w->GetColCount(); col++)
		{
			found = false ;
			for(const Base* ch : m_children )
			{
				if(ch->GetRow() == row && ch->GetCol() == col)
				{
					std::cout << ch->GetId() << ' ';
					found = true;
					break;
				}
			}	
			if(!found)
			{
				std::cout<<"[empty]"<< ' ';
			}
		}
		std::cout<<std::endl;
	}
}
