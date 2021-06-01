#ifndef LOADMANAGERCREATOR_H
#define LOADMANAGERCREATOR_H
#include <memory>

using namespace std;

class LoadManager;

class LoadManagerCreator
{
public:
    LoadManagerCreator() = default;
    ~LoadManagerCreator() = default;

    shared_ptr<LoadManager> getManager();

private:
    shared_ptr<LoadManager> createManager();

    shared_ptr<LoadManager> manager;
};

#endif // LOADMANAGERCREATOR_H
