#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "abstractfactory.h"

#include <QWidget>
#include <memory>

using namespace std;

class QtFactory : public AbstractFactory
{
public:
    QtFactory() = default;
    ~QtFactory() = default;
    virtual unique_ptr<BaseDrawer> createGraphics() override;
};

#endif // QTFACTORY_H
