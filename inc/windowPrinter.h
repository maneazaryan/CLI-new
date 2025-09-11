#pragma once 
#include <iostream>	
#include <vector>
#include "window.h"
#include "base.h"
#include "manage.h"
#include <memory>
class WindowPrinter
{
	std::vector< std::shared_ptr<Base>> m_children;
	public:
	void Print(int showPid);	
};
