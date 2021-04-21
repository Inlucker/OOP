#ifndef BASEITERATOR_H
#define BASEITERATOR_H

class BaseIterator
{
public:
    BaseIterator();
    ~BaseIterator();

    //virtual bool operator !=(const BaseIterator& it) const = 0;
    //virtual BaseIterator& operator ++() const = 0;
    //virtual BaseIterator operator ++(int) const = 0;
protected:
    int id = 0;
    int elems_num = 0;
};

#endif // BASEITERATOR_H
