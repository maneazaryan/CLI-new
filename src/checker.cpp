#include "checker.h"
Checker::Checker()
{
	m_mElements = Manage::GetInstance()->GetElements();
}

bool Checker::CheckId(int id) 
{
		for(const auto& pair : m_mElements)
		{
				Base* b = pair.second;
				if(b && b->GetId()==id)
				{
						std::cout<<"Error : ID has already existed"<<std::endl;
						return false;
				}
		}
		return true;
}

bool Checker::CheckPId(int Pid) 
{
		if(m_mElements.find(Pid) == m_mElements.end())
		{
				std::cout<<"Error: invalid parent window ID"<<std::endl;
				return false;
		}
		else return true;
}
bool Checker::CheckPosition(int row, int col, int pId)
{
		if(row < 0 || col < 0)
		{
				std::cout<<"Error : position is not avalibe "<< std::endl;
				return false;
		}
		std::map<int, Base*> ::iterator it = m_mElements.find(pId);
		if(it==m_mElements.end())
		{
				return false;
		}
		Window* w = dynamic_cast<Window*>(it->second);
		if(!w)
		{
				return false;
		}
		if(w->IsPositionFree(row, col)==false)
		{
				std::cout<<"Error : position is not available "<< std::endl;
				return false;
		}
		return true;
}

bool Checker::CheckRange(int row, int col, int pId )
{
		if(row<0 || col<0 ) 
		{
				std::cout<<"Error : out of range"<<std::endl;
				return false;	
		}
		std::map<int, Base*> ::iterator it = m_mElements.find(pId);
		if(it==m_mElements.end())
		{
				return false;
		}
		Window* w = dynamic_cast<Window*>(it->second);
		if(!w)	
		{
				return false;
		}
		if(!(row< w->GetRowCount() && col < w->GetColCount()))
		{

				std::cout<<"Error : out of range"<<std::endl;
				return false;
		}
		return true;
}
bool Checker::M_CheckParametrs( int m_id, int m_pId, int m_row, int m_col)
{
		if(CheckId(m_id) &&  
						CheckPId(m_pId) &&
						CheckRange(m_row, m_col, m_pId) &&  
						CheckPosition(m_row,m_col,m_pId))
		{
				return true;
		}
		else return false;    
}
