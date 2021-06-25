#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>
#include <time.h>

using namespace std;

class BaseError : public exception
{
public:
    BaseError(string info, string filename, int line, const char *time, string error = "Error")
    {
        err_info = "\nError: " + error;
        err_info = err_info + "\nTime: " + time;
        err_info += "File name: " + filename +"\nLine#: " + to_string(line);
        err_info += "\nWhat caused error: " + info;
    }
    virtual const char* what() const noexcept override
    {
        return err_info.c_str();
    }
protected:
    string err_info;
};

class IndexError : public BaseError
{
public:
    IndexError(string info, string filename, int line, const char *time, string error = "Index out of range")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class GraphicsSolutionKeyError : public BaseError
{
public:
    GraphicsSolutionKeyError(string info, string filename, int line, const char *time, string error = "No such key in map")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class NoCanvasError : public BaseError
{
public:
    NoCanvasError(string info, string filename, int line, const char *time, string error = "No canvas")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class NoDrawerError : public BaseError
{
public:
    NoDrawerError(string info, string filename, int line, const char *time, string error = "No drawer")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class NoCameraError : public BaseError
{
public:
    NoCameraError(string info, string filename, int line, const char *time, string error = "No camera")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class NoObjectError : public BaseError
{
public:
    NoObjectError(string info, string filename, int line, const char *time, string error = "No object with such name")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class ExistingObjectError : public BaseError
{
public:
    ExistingObjectError(string info, string filename, int line, const char *time, string error = "Object with such name already exists")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class EmptyNameError : public BaseError
{
public:
    EmptyNameError(string info, string filename, int line, const char *time, string error = "Can't create object with empty name")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class SetCanvasError : public BaseError
{
public:
    SetCanvasError(string info, string filename, int line, const char *time, string error = "Set canvas error")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class UseCameraError : public BaseError
{
public:
    UseCameraError(string info, string filename, int line, const char *time, string error = "Use Camera Error")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class FileOpenError : public BaseError
{
public:
    FileOpenError(string info, string filename, int line, const char *time, string error = "File open error")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class NoMementosError : public BaseError
{
public:
    NoMementosError(string info, string filename, int line, const char *time, string error = "No mementos error")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

//Iterator and composite errors
class EmptyError : public BaseError
{
public:
    EmptyError(string info, string filename, int line, const char *time, string error = "Trying to use empty vector")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class NegativeSizeError : public BaseError
{
public:
    NegativeSizeError(string info, string filename, int line, const char *time, string error = "Trying to create vector with negative size")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class MemoryError : public BaseError
{
public:
    MemoryError(string info, string filename, int line, const char *time, string error = "Memory error")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class IteratorWeakPtrError : public BaseError
{
public:
    IteratorWeakPtrError(string info, string filename, int line, const char *time, string error = "Iterator weak_ptr error")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class IteratorIdError : public BaseError
{
public:
    IteratorIdError(string info, string filename, int line, const char *time, string error = "Iterator id out of range")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

class DifSizeError : public BaseError
{
public:
    DifSizeError(string info, string filename, int line, const char *time, string error = "Opearation with different sized vectors")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
};

#endif // ERRORS_H
