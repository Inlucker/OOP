#include "basemodelbuilder.h"

#include "modeldirector.h"

shared_ptr<Model> ModelDirector::create(shared_ptr<BaseModelBuilder> builder, shared_ptr<ifstream> file)
{
    builder->build();

    size_t points_count;
    *file >> points_count;

    for (size_t i = 0; i < points_count; i++)
    {
        double x, y, z;
        *file >> x >> y >> z;
        builder->addPoint(x, y, z);
    }

    size_t links_count;
    *file >> links_count;

    for (size_t i = 0; i < links_count; i++)
    {
        size_t pt1, pt2;
        *file >> pt1 >> pt2;
        builder->addEdge(pt1, pt2);
    }

    return builder->getModel();
}
