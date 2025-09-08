#include "invorker.h"

void Invorker::executeComand(Command* com)
{
		m_cmd=com ;
//		v.push_back(c);
		m_cmd->execute();
}
Invorker::~Invorker ()
{
		m_vPCmd.clear();
}

