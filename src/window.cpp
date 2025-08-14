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
	for(int i = 0; i < m_rowCount; i++)
	{
			if(m_children[i]) 
			{
				std::cout<< " Window : id "<< getId()
					<< ", size ( " << getRowCount()<<", " << getColCount()
					<< ") in (" << getRow()<<',' << getCol() << ") ";
			}
			else std::cout << " [empty] "; 
	}
}
