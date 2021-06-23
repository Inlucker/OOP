#ifndef MEMENTO_H
#define MEMENTO_H

#include "scene.h"

class Memento
{
    friend class Scene;

public:
    Memento(Scene &o);

private:
    void setOriginator(Scene o);
    Scene getOriginator();

private:
    Scene originator;
};

#endif // MEMENTO_H
