#include "exit.h"
Exit::Exit()
{
	m_start = Start::GetInstance();
}
void Exit::execute()
{
	m_start -> SetQuit(); 
}
