#ifndef MAIN__HPP
#define MAIN__HPP

#include "cmdline.hpp"
#include "errors.hpp"

using namespace std;

#define HELP_MSG  "Para ejecutar el programa usar: ./tp0 -d DATA.txt -i ENTRADA.txt -o SALIDA.txt\nTambien se puede usar: make test"

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_data(string const &);
static void opt_help(string const &);

#endif
