#pragma once
#include "command.h"
#include <vector>
class Command;
class Invorker
{
    std::vector<Command*> m_vPCmd;
    Command* m_cmd;
    public:
    void executeComand(Command* com);
    ~Invorker();
};
