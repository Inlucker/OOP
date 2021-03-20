#include "file_stream.h"

#include "error_codes.h"

int open_file(Read_file &file, const char* filename)
{
    if (file.stream)
        file.stream.close();

    file.stream.open(filename);
    if (!file.stream)
        return FILE_NOT_FOUND;

    return 0;
}

int open_file(Write_file &file, const char* filename)
{
    if (file.stream)
        file.stream.close();

    file.stream.open(filename);
    if (!file.stream)
        return FILE_NOT_FOUND;

    return 0;
}

int close_file(Read_file &file)
{
    if (file.stream)
        file.stream.close();

    return 0;
}

int close_file(Write_file &file)
{
    if (file.stream)
        file.stream.close();

    return 0;
}

int print_stream(Write_file &file, const char* str)
{
    if (!file.stream)
        return FILE_NOT_FOUND;
    file.stream << str;

    return OK;
}

int read_file(double &x, Read_file &file)
{
    if (!file.stream)
        return FILE_NOT_FOUND;

    double y = 0;
    if (!(file.stream >> y))
        return FILE_ERROR;
    x = y;

    return OK;
}

int read_file(int &x, Read_file &file)
{
    if (!file.stream)
        return FILE_NOT_FOUND;

    int y = 0;
    if (!(file.stream >> y))
        return FILE_ERROR;
    x = y;

    return OK;
}

