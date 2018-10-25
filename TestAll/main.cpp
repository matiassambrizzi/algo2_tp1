#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "main.hpp"
#include "cmdline.hpp"
#include "types.hpp"
#include "errors.hpp"
#include "array.hpp"
#include "sensor.hpp"
#include "sensor_network.hpp"
#include "dato.hpp"
#include "node.hpp"
#include "segmentTree.hpp"

using namespace std;

//Opciones globales
static option_t options[] = {
	{1, "d", "data", NULL, opt_data, OPT_MANDATORY},
	{1, "i", "input", "-", opt_input, OPT_MANDATORY},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static istream *iss = 0;
static istream *iss_data = 0;
static ostream *oss = 0;
static fstream ifs;
static fstream ifs_data;
static fstream ofs;

int main(int argc, char *argv[]){

	//Vavidaciones CLA
	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	//Fin Validacioon

	sensorNetwork test;

	//Carga de datos a la red de sensores
	test.process_input_file(*iss_data);
	test.buildSegmentTrees();
	test.process_query_tree(*iss,*oss);

	return OK;
}


static void opt_input(string const &arg)
{

	if (arg == "-") {
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	}
	else {
		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		print_error(ERROR_OPENING_INPUT_FILE);
		exit(1);
	}

}

static void opt_output(string const &arg)
{

	if (arg == "-") {
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		print_error(ERROR_OPENING_OUTPUT_FILE);
		exit(1);
	}
}


static void opt_data(string const &arg)
{

	ifs_data.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
		iss_data = &ifs_data;

	if (!iss_data->good()) {
		print_error(ERROR_OPENING_INPUT_FILE);
		exit(1);
	}


}

static void opt_help(string const &arg)
{
	//Imprimo por pantalla como invocar el programa
	cout << HELP_MSG << endl;
	exit(0);
}
