#include "manage.h"
bool Manage::checkId(int id) 
{
        for(int i=0 ; i<static_cast<int>((m_V).size()); i++)
        {
                for(int j=0; j<static_cast<int>(m_V[i].size()); j++)
                {
                        if(m_V[i][j]!=nullptr && m_V[i][j]->getId()==id)
                        {
                                std::cout<<"Error : id has already existed"<<std::endl;
                                return false;
                        }
                }
        }
        return true;
}
int Manage::findPid(int pId)
{
        for(int i=0 ; i<static_cast<int>((m_V).size()); i++)
	{
		Window* w =dynamic_cast<Window*>(m_V[i][0]);
		if(w!=nullptr &&  w->getpId()==pId)
			return i;
	}
	return -1;
}
bool Manage::checkRange(int row, int col, int rowN )
{
	if(row<0 || col<0 ) return false;	
	Window* w =dynamic_cast<Window*>(m_V[rowN][0]);
	if(w==nullptr) return false;
	return ( row < w->getRowCount() && col < w->getColCount());

}
//texy azat linelu pahi hamar funcion grel
//karchacnelu pahery pahel
void Manage::AddElement(Base* base){
	int pId=base->getpId();
	int id=base->getId();
	int row=base->getRow();
	int col=base->getCol();

	if(!m_V.empty()) {
		int rowN=findPid(pId);
		if(rowN==-1){
			Window* w =dynamic_cast<Window*>(base);
			if(w==nullptr){
				std::cout<<"Erorr::wrong pId"<<std::endl;
				return;
			}else{
				m_V.push_back(std::vector<Base*>{base});
			}
		}else{
			if(checkRange(row,col,rowN)) m_V[rowN].push_back(base);
			else{
				std::cout<<"Error : out of range"<<std::endl;
				return;
			}
		}
	}
}
void Manage::print(){
	std::cout<<"------Elements------"<<std::endl;
	for (int i = 0; i < static_cast<int>((m_V).size()); i++) {
		for (int j = 0; j <static_cast<int>(m_V[i].size()); j++) {
			if (m_V[i][j])
				m_V[i][j]->Print();
			else
				std::cout << "[" << i << "," << j << "] empty" <<" ";
		}
		std::cout<<std::endl;
	}

}
