#ifndef FILE_STREAM_H
#define FILE_STREAM_H

#include <fstream>

using namespace std;

int print_stream(ofstream &file, const char* str);

int read_file(double &x, ifstream &file);
int read_file(int &x, ifstream &file);

#endif // FILE_STREAM_H
