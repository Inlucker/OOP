#ifndef FILELOADER_H
#define FILELOADER_H

#include <memory>

using namespace std;

#include "basefileloader.h"

class FileLoader : public BaseFileLoader
{
public:
    FileLoader();
    virtual ~FileLoader() override = default;
    virtual void open(string filename) override;
    virtual void close() override;
    virtual shared_ptr<ifstream> loadFile() override;
protected:
    shared_ptr<ifstream> file; //shared_ptr<ifstream> or just ifstream?
};

#endif // FILELOADER_H
