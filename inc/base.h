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
		Base(int id 
				,int row=-1
				,int col=-1
				,int pId=-1)
			: m_id(id)
			  , m_row(row)
			  , m_col(col)
			  , m_pId(pId) {}

		virtual ~Base(){};
		int GetpId();
		int GetId()const;
		int GetRow()const;
		int GetCol()const;
		Base() {};
		virtual void Print()const=0;
};
