#include "window.h"
Window::Window(int id, int pId, int row, int col,  int rowCount, int colCount)
        : Base( id, pId, row, col )
          , m_rowCount(rowCount) 
          , m_colCount(colCount) {}

Window::Window(int id, int pId, int rowCount, int colCount)
       	 :Base( id, pId, -1, -1) , m_rowCount(rowCount), m_colCount(colCount){}  

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

void Window::Draw()const{
	std::cout<<"Window "<<GetId()<< " ";
}
