#include "manage.h"
bool Manage::CheckId(int id) 
{
        for(int i=0 ; i < m_v.size(); i++)
        {
                        if( m_v[i]->GetId()==id)
                        {
                                std::cout<<"Error : ID has already existed"<<std::endl;
                                return false;
                        }
        }
        return true;
}

bool Manage::CheckPId(int Pid) 
{
	for(int i = 0; i < m_v.size(); i++ )
	{
		if( m_v[i]->GetpId() != Pid)
			continue;
		else
			return true;
	}
	std::cout<<"Error: invalid parent window ID"<<std::endl;
	return false;
}
bool Manage::CheckPosition(int row, int col)
{
	for(int i = 0; i < m_v.size(); i++ )
	{
		if(m_v[i]->GetRow()==row && m_v[i]->GetCol()==col )
		{	
			std::cout<<"Error : rosition is not avalibe "<< std::endl;
			return false;
		}
	}
	return true;
}
int Manage::FindIndex(int pId)
{
        for(int i=0 ; i< m_v.size(); i++)
	{
		if( m_v[i]->GetpId()==pId)
			return i;
	}
	return -1;
}

Base* Manage::FindWindow(int pId)
{
	Window* w;	
        for(int i = 0 ; i<m_v.size(); i++)
	{
		w = dynamic_cast<Window*>(m_v[i]);
		if(w && m_v[i]->GetpId() == pId){
			return w;}
	}
	return nullptr;
}

bool Manage::CheckRange(int row, int col, int index )
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
		if( !(row <= w->GetRowCount() && col <= w->GetColCount()))
			{
				std::cout<<"Error : out of range"<<std::endl;
				return false;
			}
	}
	return true;
}

void Manage::AddElement(Base* base)
{
	m_v.push_back(base);
}

void Manage::Print(int showPid)
{
	Base* p = FindWindow(showPid);
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
