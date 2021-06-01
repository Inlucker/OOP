#ifndef TRANSFORMMANAGERCREATOR_H
#define TRANSFORMMANAGERCREATOR_H

#include <memory>

using namespace std;

class TransformManager;

class TransformManagerCreator
{
public:
    TransformManagerCreator() = default;
    ~TransformManagerCreator() = default;

    shared_ptr<TransformManager> getManager();

private:
    shared_ptr<TransformManager> createManager();

    shared_ptr<TransformManager> manager;
};

#endif // TRANSFORMMANAGERCREATOR_H
