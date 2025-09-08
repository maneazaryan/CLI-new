#include "invorker.h"

void Invorker::executeComand(Command* com)
{
		c=com ;
//		v.push_back(c);
		c->execute();
}
Invorker::~Invorker ()
{
		for(Command* a: v)
				delete a;
}

