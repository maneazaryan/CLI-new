#include "window.h"
int Window::getRowCount()const{return m_rowCount;}
int Window::getColCount()const{return m_colCount;}
void Window::Print()const{
	std::cout<<"Window : id "<< getId()<<", size ( "<< getRowCount()<<", "<<getColCount()<<") in ("<<getRow()<<','<<getCol()<<") ";
}
