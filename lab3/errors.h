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

#endif // ERRORS_H
