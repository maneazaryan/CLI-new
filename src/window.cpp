#include "window.h"

int Window::GetRowCount()const { return m_rowCount;}
int Window::GetColCount()const { return m_colCount;}

bool Window::IsPositionFree(int row, int col)const
{
	std::map<int, Base*>::const_iterator it;
	for(it=m_children.cbegin(); it != m_children.cend(); it++)
		{
			Base* child= it->second;
			if(child->GetRow()==row && child->GetCol()==col)
			{
				return false;
			}
		}
	return true;
}

void Window::AddChild(Base* child) 
{
	m_children.insert({child->GetId(),child});
}

const std::map<int, Base*>& Window::GetChildren()const
{
	return m_children;
}

void Window::Draw()const{
	std::cout<<"Window : "<<GetId()<<std::endl;
}

void Window::Print2(Window* w)const{
	bool found ;
	for(int row = 0; row < w->GetRowCount(); row++)
	{
		for(int col = 0 ; col < w->GetColCount(); col++)
		{
			found = false ;
			std::map<int, Base*>::const_iterator it;
			for(it=m_children.cbegin(); it!= m_children.cend(); it++ )
			{
				Base* ch = it->second;
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
