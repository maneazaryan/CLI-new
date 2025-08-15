#include "window.h"

int Window::getRowCount()const
{
	return m_rowCount;
}
int Window::getColCount()const
{
	return m_colCount;
}
void Window::AddChild(Base* child) 
{
	m_children.push_back(child);
}
const std::vector<Base*>& Window::getChildren()const
{
	return m_children;
}
void Window::Print()const{
	std::cout<<' ';
}
void Window::Print2(Window* w)const{
	bool found ;
	for(int row = 0; row < w->getRowCount(); row++)
	{
		for(int col = 0 ; col < w->getColCount(); col++)
		{
			found = false ;
			for(const Base* ch : m_children )
			{
				if(ch->getRow() == row && ch->getCol() == col)
				{
					std::cout << ch->getId() << ' ';
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
