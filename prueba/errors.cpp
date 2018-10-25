#include <iostream>
#include "errors.hpp"
#include "types.hpp"
using namespace std;

const char *errors[MAX_ERRORS] = {
	MSG_OK,
	ERROR_MSG_OPENING_INPUT_FILE,
	ERROR_MSG_OPENING_OUTPUT_FILE,
	ERROR_MSG_EMPTY_FILE
};

status_t print_error(status_t st)
{
	cerr << errors[st] << endl;
	return OK;
}
