#ifndef BASEFILELOADER_H
#define BASEFILELOADER_H

#include <fstream>
#include <memory>

using namespace std;

class Object;
class BaseModelBuilder;

class BaseFileLoader
{
public:
    BaseFileLoader() = default;
    virtual ~BaseFileLoader() = 0;
    virtual void open(string filename) = 0;
    virtual void close() = 0;
    virtual shared_ptr<ifstream> loadFile() = 0;
protected:
    shared_ptr<ifstream> file; //Должен быть здесь
};

#endif // BASEFILELOADER_H
