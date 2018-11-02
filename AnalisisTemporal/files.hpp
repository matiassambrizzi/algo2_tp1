#ifndef FILES__HPP
#define FILES__HPP
#include <iostream>
#include <fstream>
#include "types.hpp"
using namespace std;

#define CLA_POSITION_INPUT_FILE         1
#define CLA_POSITION_OUTPUT_FILE        2

status_t open_file(ofstream &fo, ifstream &fi, char *argv[]);
void close_file(ifstream &fi,ofstream &fo);

#endif
