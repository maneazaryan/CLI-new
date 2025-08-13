#include "window.h"
int Window::getRowCount()const{return m_rowCount;}
int Window::getColCount()const{return m_colCount;}
void Window::Print(Base* base)const{
	std::cout<<"Window: Pid "<<base->getpId()<<std::endl;
}
