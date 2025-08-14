#include "manage.h"
bool Manage::checkId(int id) 
{
        for(int i=0 ; i < m_v.size(); i++)
        {
                        if( m_v[i]->getId()==id)
                        {
                                std::cout<<"Error : id has already existed"<<std::endl;
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
int Manage::findPid(int pId)
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
		if(w && m_v[i]->getpId() == pId)
			return w;
	}
	return  w;
}

bool Manage::checkRange(int row, int col, int index )
{
	std::cout <<"row\t " <<row << "\n" << "col\t "<<col <<"\nindex\t" << index ;
	if(row<0 || col<0 ) return false;	
	Window* w =dynamic_cast<Window*>(m_v.at(index));
	if(w==nullptr) return false;
	return ( row <= w->getRowCount() && col <= w->getColCount());
}

void Manage::AddElement(Base* base)
{
	int pId = base->getpId();
	int id  = base->getId();
	int row = base->getRow();
	int col = base->getCol();
		
	int index=findPid(pId);
	m_v.push_back(base);

	//Base* bparent = findWindow(pId);
//	Window* parent = dynamic_cast<Window*>(bparent);
//	
//	if(!parent) 
//	{
//		std::cout << "Error : parent not found " << std::endl ;
//		return;
//	}
//	parent->AddChild(base);
	



/*
		if(rowN==-1)
		{
			std::cout<<pId;
			Window* w =dynamic_cast<Window*>(base);
			if(w==nullptr){
				std::cout<<"Erorr : wrong pId"<<std::endl;
				return;
			}else{
				m_v.push_back(base);
				
			}
		}
		else
		{
			if(checkRange(row,col,rowN)) 
			{
				m_v.push_back(base);
			}
			else
			{
				std::cout<<"Error : out of range"<<std::endl;
			}
		}
*/
}

void Manage::print()
{
	std::cout<<"------Elements------"<<std::endl;
	for (Base* el : m_v)
		std::cout<<el->getId()<< ' ';
//        win		dynamic_cast<window >
//  	 vecWPB	win->getchild;
//      for (
//	
}
