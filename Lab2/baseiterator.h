#ifndef BASEITERATOR_H
#define BASEITERATOR_H

class BaseIterator
{
public:
    BaseIterator();
    virtual ~BaseIterator() = 0;

protected:
    int id = 0;
    int elems_num = 0;
};

#endif // BASEITERATOR_H
