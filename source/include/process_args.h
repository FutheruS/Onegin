#ifndef PROCESSARGS_H
#define PROCESSARGS_H

#include <string.h>
#include "../include/processing.h"
#include "../include/output.h"
#include "../include/input.h"

/// Max length for command
const size_t MAX_COMMAND_SIZE = 128;
/// Max length for name of file
const size_t MAX_FILENAME_SIZE = 128;

MsgType process_args(int argc, char* argv[], char infile_name[], char outfile_name[], Modifiers* mods);

MsgType open_files(char infile_name[], char outfile_name[], int* infile_descr, int* outfile_descr);

#endif // PROCESSARGS_H

