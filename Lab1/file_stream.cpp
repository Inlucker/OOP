#include <file_stream.h>
#include "error_codes.h"

/*int open_file(ifstream &file, const char* filename)
{
    if (file)
        file.close();

    file.open(filename);
    if (!file)
        return FILE_NOT_FOUND;

    return OK;
}

int open_file(ofstream &file, const char* filename)
{
    if (file)
        file.close();

    file.open(filename);
    if (!file)
        return FILE_NOT_FOUND;

    return OK;
}

int close_file(ifstream &file)
{
    if (file)
        file.close();

    return OK;
}

int close_file(ofstream &file)
{
    if (file)
        file.close();

    return OK;
}*/


int print_stream(ofstream &file, const char* str)
{
    if (!file)
        return FILE_NOT_FOUND;
    file << str;

    return OK;
}

int read_file(double &x, ifstream &file)
{
    if (!file)
        return FILE_NOT_FOUND;

    double y = 0;
    if (!(file >> y))
        return FILE_ERROR;
    x = y;

    return OK;
}

int read_file(int &x, ifstream &file)
{
    if (!file)
        return FILE_NOT_FOUND;

    int y = 0;
    if (!(file >> y))
        return FILE_ERROR;
    x = y;

    return OK;
}

