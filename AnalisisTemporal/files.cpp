#include <iostream>
#include <fstream>
#include "files.hpp"
#include "types.hpp"
using namespace std;

status_t open_file(ofstream &fo, ifstream &fi, char *argv[])
{

	fi.open((argv[CLA_POSITION_INPUT_FILE]),ios::in);
	if(fi.fail())
		return ERROR_OPENING_INPUT_FILE;

	fo.open((argv[CLA_POSITION_OUTPUT_FILE]),ios::out);
	if(fo.fail())
		return ERROR_OPENING_OUTPUT_FILE;

	//Check_empty_file
	fi.seekg(0,fi.end); //Voy hasta el final del archivo
	if(!fi.tellg())			//Me fijo si el tamaño es cero
	{
		close_file(fi,fo);
		return ERROR_EMPTY_FILE;
	}

	fi.seekg(0,fi.beg);	//Vuelvo al principio del archivo
	return OK;
}

void close_file(ifstream &fi,ofstream &fo)
{
	fi.close();
	fo.close();
}
