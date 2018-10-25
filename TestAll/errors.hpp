#ifndef ERRORS__HPP
#define ERRORS__HPP
#include <iostream>
#include "types.hpp"

#define MAX_ERRORS 												4
#define MSG_OK														"Ok"
#define ERROR_MSG_OPENING_INPUT_FILE 			"Error abriendo archivo de entrada"
#define ERROR_MSG_OPENING_OUTPUT_FILE 		"Error abriendo archivo de entrada"
#define ERROR_MSG_EMPTY_FILE              "Archivo de entrada vacio"

void print_error(status_t st);

#endif
