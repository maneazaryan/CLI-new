#pragma once
#include <iostream>
#include <string>
#include <map>
#include "manage.h"
#include "base.h"
#include "window.h"

class Checker
{
	private:
		std::multimap<int, Base*> m_mElements ;
	private:
		bool CheckId(int id);
		bool CheckPId(int Pid);
		bool CheckPosition(int row, int col, int pId);
		bool CheckRange(int row, int col, int pId);
	public:
		Checker ();
		bool M_CheckParametrs( int m_id, int m_pId, int m_col, int m_row);

};
