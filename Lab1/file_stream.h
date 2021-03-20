#ifndef FILE_STREAM_H
#define FILE_STREAM_H

#include <fstream>

//using namespace std;

struct Read_file
{
    std::ifstream stream;
};

struct Write_file
{
    std::ofstream stream;
};

int open_file(Read_file &file, const char* filename);
int open_file(Write_file &file, const char* filename);

int close_file(Read_file &file);
int close_file(Write_file &file);

int print_stream(Write_file &file, const char* str);

int read_file(double &x, Read_file &file);
int read_file(int &x, Read_file &file);

#endif // FILE_STREAM_H
