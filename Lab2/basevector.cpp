#include "basevector.h"

BaseVector::BaseVector()
{
    //constructor
    elems_num = 0;
}

/*BaseVector::BaseVector(BaseVector &copy_base)
{
    //constructor
    elems_num = copy_base.elems_num;
}*/

BaseVector::~BaseVector()
{
    //destructor
}

/*BaseVector::BaseVector(const BaseVector &base)
{
    elem_num = base.elem_num;
}

bool BaseVector::is_empty() const
{
    return !elem_num;
}

int BaseVector::size() const
{
    return elem_num;
}*/
