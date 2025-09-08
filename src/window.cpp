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

bool Window::IsPositionFree(int row, int col)const
{
	for(int it = 0 ; it < m_children.size(); it++)
		{
			if(m_children.at(it)->GetRow()==row && m_children.at(it)->GetCol()==col)
				return false;
		}
	return true;
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

void Window::Show(Window* w)const{
	bool found ;
	for(int row = 0; row < w->GetRowCount(); row++)
	{
		for(int col = 0 ; col < w->GetColCount(); col++)
		{
			found = false ;
			for(int i = 0 ; i< m_children.size(); i++ )
			{
				if(m_children.at(i)->GetRow() == row && m_children.at(i)->GetCol() == col)
				{
					m_children.at(i)->Draw();
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
