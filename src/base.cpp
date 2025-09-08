#include "base.h"
Base::Base(int id, int pId , int row, int col)
          : m_id(id) ,m_pId(pId) , m_row(row) , m_col(col){}
int Base::GetpId(){ return m_pId;}
int Base::GetId()const { return m_id;}
int Base::GetRow()const { return m_row;}
int Base::GetCol()const { return m_col;}
