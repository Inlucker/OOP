#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>

using namespace std;

class BaseError : public exception
{
public:
    BaseError(string info, string filename, int line, const char *time, string error = "Error")
    {
       /* err_info = "\nFile name: " + filename + "\nClass: " + classname +
                "\nLine#: " + to_string(line) +
                "\nTime: " + time + "Info: " + info;*/
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
    MemoryError(string info, string filename, int line, const char *time, string error = "Allocation error")
        : BaseError(info, filename, line, time, error) {};
    virtual const char* what() const noexcept
    {
        return err_info.c_str();
    }
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

#endif // ERRORS_H
