#include "manage.h"
bool Manage::checkId(int id) 
{
        for(int i=0 ; i < m_v.size(); i++)
        {
                        if( m_v[i]->getId()==id)
                        {
                                std::cout<<"Error : ID has already existed"<<std::endl;
                                return false;
                        }
        }
        return true;
}

bool Manage::checkPId(int Pid) 
{
	for(int i = 0; i < m_v.size(); i++ )
	{
		if( m_v[i]->getpId() != Pid)
			continue;
		else
			return true;
	}
	std::cout<<"Error: invalid parent window ID"<<std::endl;
	return false;
}
bool Manage::ckeckPosition(int row, int col)
{
	for(int i = 0; i < m_v.size(); i++ )
	{
		if(m_v[i]->getRow()==row && m_v[i]->getCol()==col )
		{	
			std::cout<<"Error : rosition is not avalibe "<< std::endl;
			return false;
		}
	}
	return true;
}
int Manage::findIndex(int pId)
{
        for(int i=0 ; i< m_v.size(); i++)
	{
		if( m_v[i]->getpId()==pId)
			return i;
	}
	return -1;
}

Base* Manage::findWindow(int pId)
{
	Window* w;	
        for(int i = 0 ; i<m_v.size(); i++)
	{
		w = dynamic_cast<Window*>(m_v[i]);
		if(w && m_v[i]->getpId() == pId){
			return w;}
	}
	return nullptr;
}

bool Manage::checkRange(int row, int col, int index )
{
	if(row<0 || col<0 ) 
	{
		std::cout<<"Error : out of range"<<std::endl;
		return false;	
	}
	Window* w =dynamic_cast<Window*>(m_v.at(index));
	if(w==nullptr)
	{
		return false;
	}
	else
	{
		if( !(row <= w->getRowCount() && col <= w->getColCount()))
			{
				std::cout<<"Error : out of range"<<std::endl;
				return false;
			}
	}
	return true;
}

void Manage::AddElement(Base* base)
{
	int pId = base->getpId();
	int id  = base->getId();
	int row = base->getRow();
	int col = base->getCol();
		
	m_v.push_back(base);
}

void Manage::Print(int showPid)
{
	Base* p = findWindow(showPid);
	Window* w = dynamic_cast<Window*>(p);
	if(w!=nullptr)
	{
		std::cout<<"------Elements------"<<std::endl;
		w->Print2(w);
	}
	else
	{
		std::cout<<"Error : no window found with Pid"<< showPid << std::endl;
	}
}
