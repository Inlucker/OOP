#ifndef GRAPHICSOLUTION_H
#define GRAPHICSOLUTION_H

#include <map>

using namespace std;

#include "abstractfactory.h"

class GraphicSolution
{
public:
    //GraphicSolution();
    typedef unique_ptr<AbstractFactory> (*CreateFactory)();

    bool registration(size_t id, CreateFactory createfun);
    bool check(size_t id);

    unique_ptr<AbstractFactory> create(size_t id);
private:
    using CallBackMap = map<size_t, CreateFactory>;

    CallBackMap callbacks;
};

unique_ptr<AbstractFactory> createQtFactory();

#endif // GRAPHICSOLUTION_H
