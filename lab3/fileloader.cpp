#include "fileloader.h"
#include "errors.h"

#include <iostream>

FileLoader::FileLoader()
{
    file = shared_ptr<ifstream>(new ifstream());
}

void FileLoader::open(string filename)
{
    if (file->is_open())
        file->close();

    file->open(filename);
    if (!file->is_open())
    {
        cout << "Couldn't open file" << endl;
        time_t t_time = time(NULL);
        throw FileOpenError("Couldn't open file", __FILE__, __LINE__, ctime(&t_time));
    }
}

void FileLoader::close()
{
    if (file)
        file->close();
}

shared_ptr<ifstream> FileLoader::loadFile()
{
    return file;
}
