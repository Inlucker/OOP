#include "fileloader.h"

#include <iostream>

void FileLoader::open(string filename)
{
    if (file)
        file->close();

    file->open(filename);
    if (!file)
        cout << "file not found" << endl;
        // throw file not found
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
