#pragma once
#include "command.h"
#include <vector>
class Command;
class Invorker
{
    std::vector<Command*> v;
    Command* c;
    public:
    void executeComand(Command* com);
    ~Invorker();
};
