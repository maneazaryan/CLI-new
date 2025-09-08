#include "manage.h"
Manage* Manage::GetInstance()
{
	if(m_pManage==nullptr)
	{
		return new Manage();
	}
	return m_pManage;
}
bool Manage::CheckId(int id) 
{
		for(const auto& pair : m_v)
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

bool Manage::CheckPId(int Pid) 
{

		if(m_v.find(Pid) == m_v.end())
		{
				std::cout<<"Error: invalid parent window ID"<<std::endl;
				return false;
		}
		else return true;
}
bool Manage::CheckPosition(int row, int col, int pId)
{
		if(row < 0 || col < 0)
		{
				std::cout<<"Error : position is not avalibe "<< std::endl;
				return false;
		}
		std::map<int, Base*> ::iterator it = m_v.find(pId);
		if(it==m_v.end())
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

bool Manage::CheckRange(int row, int col, int pId )
{
		if(row<0 || col<0 ) 
		{
				std::cout<<"Error : out of range"<<std::endl;
				return false;	
		}
		std::map<int, Base*> ::iterator it = m_v.find(pId);
		if(it==m_v.end())
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
bool Manage::M_CheckParametrs( int m_id, int m_pId, int m_row, int m_col)
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

Window* Manage::FindWindow(int pId)
{
		std::multimap<int, Base*>::iterator it = m_v.find(pId);
		if(it!= m_v.end())
		{
				Window* w= dynamic_cast<Window*>(it-> second);
				if(w)
				{
						return w;
				}
		}
		return nullptr;
}

void Manage::AddElement(Base* base)
{
		m_v.insert({base->GetpId(), base});
}
//test
void Manage::Print(int showPid)
{
		Window* w = FindWindow(showPid);
		if(w)
		{
				w->Show(w);
		}
		else
		{
				std::cout<<"Error : no window found with Pid "<< showPid << std::endl;
		}
}
Manage::~Manage()
{
		for (std::map<int, Base*>::iterator it = m_v.begin(); it != m_v.end(); ++it)
				delete it->second;
}
