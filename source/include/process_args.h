#ifndef PROCESSARGS_H
#define PROCESSARGS_H

#include <string.h>

#include "response.h"
#include "sort.h"

/// Max length for command
const size_t MAX_COMMAND_SIZE = 128;
/// Max length for name of file
const size_t MAX_FILENAME_SIZE = 128;

MsgType process_args(int argc, char* argv[], char infile_name[], char outfile_name[], Modifiers* mods);

#endif // PROCESSARGS_H

