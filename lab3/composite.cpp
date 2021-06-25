#include "composite.h"
#include "point.h"

Composite::Composite(initializer_list<shared_ptr<Object>> args)
{
    //if (!(*elems_num = args.size())) return;
    elems_num = int(args.size());
    alloc_data();

    size_t i = 0;
    for (auto &elem : args)
        data_ptr[i++] = elem;
}

Composite::Composite() : Object()
{
    cout << "created composite: " << name;
    elems_num = 0;
}

Composite::Composite(string new_name) : Object(new_name)
{
    elems_num = 0;
}

Composite::Composite(int elements_number)
{
    time_t t_time = time(NULL);
    if (elements_number < 0)
        throw NegativeSizeError("elements_number < 0", __FILE__, __LINE__, ctime(&t_time));

    if (elements_number == 0)
    {
        elems_num = 0;
        data_ptr.reset();
    }
    else
    {
        elems_num = elements_number;
        alloc_data();

        //for each
        for (auto &elem:*this)
            elem = 0;
        /*for (Iterator<Type> It = this->begin(); It != this->end(); ++It)
            *It = 0;*/
    }
}

void Composite::transform(const Point move, const Point scale, const Point rotate)
{
    //Composite rez(*this);
    for (auto &elem:*this)
        elem->transform(move, scale, rotate);
}

bool Composite::isVisible() const //what do I do here?
{
    cout << "Composite isVisible method:" << endl;
    bool rez = false;
    //Composite rez(*this);
    for (ConstIterator<Type> It = this->cbegin(); It != this->cend(); It++)
    {
        if ((*It)->isVisible()) //??
        {
            rez = true;
        }
    }
    return rez; //return true????
}

void Composite::accept(shared_ptr<BaseVisitor> visitor)
{
    for (auto &obj:*this)
        obj->accept(visitor);
}

shared_ptr<Object> Composite::clone()
{
    //shared_ptr<Object> newComposite = shared_ptr<Object>(new Composite());
    shared_ptr<Object> newComposite = shared_ptr<Object>(new Composite(name));
    for (auto &obj:*this)
    {
        newComposite->add(obj->clone());
    }
    return newComposite;
}

bool Composite::add(shared_ptr<Object> comp)
{
    //objectsVec.push_back(comp);
    if (elems_num == 0)
    {
        *this = Composite{comp};
        return true;
    }
    else
    {
        bool existsFlag = false;
        for (auto &obj:*this)
        {
            if (obj->getName() == comp->getName())
                existsFlag = true;
        }
        if (existsFlag)
        {
            time_t t_time = time(NULL);
            throw ExistingObjectError("Object with name " + comp->getName() + " alreadyExists", __FILE__, __LINE__, ctime(&t_time));
        }

        elems_num += 1;
        if (elems_num > 0)
        {
            shared_ptr<Type[]> new_ptr(new Type[elems_num]);

            if (!new_ptr)
            {
                time_t t_time = time(NULL);
                throw MemoryError("allocationg data_ptr error", __FILE__, __LINE__, ctime(&t_time));
            }

            Iterator<Type> It1 = this->begin();
            for (int i = 0; i < elems_num - 1; i++, It1++)
            {
                new_ptr[i] = *It1;
            }
            new_ptr[elems_num-1] = comp;
            //data_ptr.reset();
            data_ptr = new_ptr;
            return true;
        }
        else
        {
            data_ptr.reset();
            return false;
        }
    }
}

bool Composite::remove(IteratorObject &it)
{
    //objectsVec.erase(it);
    bool deleteFlag = false;
    for (Iterator<Type> It1 = this->begin(); It1 != this->end(); It1++)
    {
        if (It1 == it)
        {
            (*It1).reset();
            deleteFlag = true;
        }
    }
    if (deleteFlag)
    {
        //elems_num -= 1;
        if (elems_num - 1 > 0)
        {
            shared_ptr<Type[]> new_ptr(new Type[elems_num - 1]);

            if (!new_ptr)
            {
                time_t t_time = time(NULL);
                throw MemoryError("allocationg data_ptr error", __FILE__, __LINE__, ctime(&t_time));
            }

            Iterator<Type> It1 = this->begin();
            for (int i = 0; It1 != this->end(); It1++)
            {
                if (It1 != it)
                {
                    new_ptr[i++] = *It1;
                }
            }
            //data_ptr.reset();
            elems_num -= 1;
            data_ptr = new_ptr;
        }
        else
        {
            elems_num = 0;
            data_ptr.reset();
        }
        return true;
    }
    else
        return false;
}

bool Composite::isComposite() const
{
    return true;
}

bool Composite::clear()
{
    //objectsVec.clear();
    elems_num = 0;
    data_ptr.reset();
    return true;
}

int Composite::size() const
{
    return elems_num;
    //return objectsVec.size();
}

/*IteratorObject Composite::begin() const
{
    return objectsVec.begin();
}

IteratorObject Composite::end() const
{
    return objectsVec.end();
}*/

Iterator<Type> Composite::begin() noexcept
{
    return Iterator<Type>(data_ptr, elems_num, 0);
}

Iterator<Type> Composite::end() noexcept
{
    return Iterator<Type>(data_ptr, elems_num, elems_num);
}

ConstIterator<Type> Composite::cbegin() const noexcept
{
    return ConstIterator<Type>(data_ptr, elems_num, 0);
}

ConstIterator<Type> Composite::cend() const noexcept
{
    return ConstIterator<Type>(data_ptr, elems_num, elems_num);
}


void Composite::alloc_data()
{
    data_ptr.reset();
    if (elems_num != 0)
    {
        shared_ptr<Type[]> new_ptr(new Type[elems_num]);

        time_t t_time = time(NULL);
        if (!new_ptr)
            throw MemoryError("allocationg data_ptr error", __FILE__, __LINE__, ctime(&t_time));

        data_ptr = new_ptr;
    }
}
