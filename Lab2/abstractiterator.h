#ifndef BASEITERATOR_H
#define BASEITERATOR_H

class AbstractIterator
{
public:
    AbstractIterator();
    virtual ~AbstractIterator() = 0;

    virtual int get_id() const = 0;
    virtual int get_els_num() const = 0;
protected:
    int id = 0;
    int elems_num = 0;
};

#endif // BASEITERATOR_H
