#ifndef FILE_STREAM_H
#define FILE_STREAM_H

#include <fstream>

using namespace std;

//int open_file(ifstream &file, const char* filename);
//int open_file(ofstream &file, const char* filename);

//int close_file(ifstream &file);
//int close_file(ofstream &file);

int print_stream(ofstream &file, const char* str);

int read_file(double &x, ifstream &file);
int read_file(int &x, ifstream &file);

#endif // FILE_STREAM_H
