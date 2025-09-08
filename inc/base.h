#pragma once
#include <iostream>
#include <vector>
class Manage;
class Base
{
	protected :
        int m_id;
        int m_row;
        int m_col;
        int m_pId;
    public:
        Base(int id, int pId , int row =-1, int col = -1 ) ;
		virtual ~Base(){};
		int GetpId();
		int GetId()const;
		int GetRow()const;
		int GetCol()const;
		virtual void Draw()const=0;
};
