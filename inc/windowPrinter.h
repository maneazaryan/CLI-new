#pragma once 
#include <iostream>	
#include <vector>
#include "window.h"
#include "base.h"
#include "manage.h"
class WindowPrinter
{
	std::vector< Base*> m_children;
	public:
	void Print(int showPid);	
};
