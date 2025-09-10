#include "windowPrinter.h"
void WindowPrinter::Print(int showPid)
{
		Window* w = Manage::GetInstance() -> FindWindow(showPid);
		if(!w)
		{
				std::cout<<"Error : no window found with Pid "<< showPid << std::endl;
				return;
		}
		else
		{
				m_children = w -> GetChildren(); 
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
}
