/** \file
    \brief      Output functions & messages
*/

#ifndef OUTPUT_H
#define OUTPUT_H

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include "../include/Index.h"
#include "../include/tests.h"



const char HELP[]              = "-h                    reference\n"
                                 "-src <filename>       input file\n"
                                 "-dst <filename>       output file\n"
                                 "-ralpha               compare lines from end\n"
                                 "-rsort                sort text in descending order\n"
                                 "-format               only format text\n";

const char NO_OPTIONS[]        = "Error: enter options (-h to open reference)\n";
const char NO_IFILE_NAME[]     = "Error: enter input file name";
const char NO_OFILE_NAME[]     = "Error: enter output file name";
const char COMMAND_OVERFLOW[]  = "Error: option is too long\n";
const char FILENAME_OVERFLOW[] = "Error: filename is too long\n";
const char OPTION_OVERWRITE[]  = "Error: option overwrite\n";
const char BAD_COMMAND[]       = "Error: bad command\n";
const char BUFFER_ERR[]        = "Error: ";
const char INDEX_ARRAY_ERR[]   = "Error: index array:";
const char BAD_INPUT_FILE[]    = "Error: cannot open input file\n";
const char BAD_OUTPUT_FILE[]   = "Error: cannot open output file\n";

/// Used to connect input and output
enum MsgType
{
    NOMSG,                  /// no message
    HLP,                    /// reference
    NO_OPT,                 /// no options error
    NO_IFL_NAME,
    NO_OFL_NAME,
    CMD_OVRFLW,             /// command overflow
    FLNAME_OVRFLW,          /// filename overflow
    OPT_OVRWRT,             /// options overwrite
    BAD_CMD,                /// bad input for command
    BUFF_ERR,               /// error with buffer creating
    INDX_ARR_ERR,           /// error with index array creating
    BAD_IFILE,              /// error with input file
    BAD_OFILE,              /// error with output file
};

/** \brief Prints message corresponding to param

    \param [out]    ostream     FILE* pointer to output file
    \param [in]     param       MsgType parameter, sets message
*/
void print(MsgType param, FILE* const ostream = stderr);

void print_line(char* begin, char* end, int file_descr);

void print_index_arr(Index* index_arr, size_t index_arr_size, int file_descr);

#endif // OUTPUT_H
