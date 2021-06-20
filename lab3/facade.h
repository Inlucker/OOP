#ifndef FACADE_H
#define FACADE_H

#include <memory>

using namespace std;

class BaseCommand;

class Facade
{
public:
    Facade();
    virtual ~Facade() = default;
    void execute(BaseCommand &cmd);
};

#endif // FACADE_H
