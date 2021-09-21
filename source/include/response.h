#ifndef RESPONSE_H
#define RESPONSE_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

const char HELP[]              = "-h                     reference\n"
                                 "--src <filename>       input file\n"
                                 "--dst <filename>       output file\n"
                                 "--ralpha               compare lines from end\n"
                                 "--rsort                sort text in descending order\n"
                                 "--format               only format text\n";

const char NOTE[]              = "(program ignores other options if -h entered)\n";
const char NO_OPTIONS[]        = "Error: enter options (-h to open reference)\n";
const char OPTION_OVERWRITE[]  = "Error: option overwrite\n";
const char NO_IFILE_NAME[]     = "Error: enter input file name";
const char NO_OFILE_NAME[]     = "Error: enter output file name";
const char COMMAND_OVERFLOW[]  = "Error: option is too long\n";
const char FILENAME_OVERFLOW[] = "Error: filename is too long\n";
const char BAD_COMMAND[]       = "Error: bad command\n";
const char BAD_INPUT_FILE[]    = "Error: cannot open input file\n";
const char BAD_OUTPUT_FILE[]   = "Error: cannot open output file\n";
const char BAD_ALLOCATION[]    = "Error: allocation has failed\n";
const char NULLPOINTER[]       = "UNDEFINED ERROR: nullptr was passed\n";
const char UNEXPECTED_ERROR[]  = "UNEXPECTED ERROR";

enum MsgType
{
    NOMSG           = 0,  /// no message
    HLP             = 1,  /// reference
    HLP_NOTE        = 2,
    NO_OPT          = 3,  /// error: no options
    OPT_OVRWRT      = 4,  /// options overwrite
    NO_IFL_NAME     = 5,  /// no input file name
    NO_OFL_NAME     = 6,  /// no output file name
    CMD_OVRFLW      = 7,  /// command overflow
    FLNAME_OVRFLW   = 8,  /// filename overflow
    BAD_CMD         = 9,  /// bad input for command
    BAD_IFILE       = 10,  /// error with input file
    BAD_OFILE       = 11, /// error with output file
    BAD_ALLOC       = 12, /// error with allocating
    NULLPTR         = 13, /// ERROR: nullptr was passed
    UNEXPCTD_ERR    = 14, /// ERROR
};

/** \brief Prints message corresponding to param

    \param [out]    ostream     FILE* pointer to output file
    \param [in]     param       MsgType parameter, sets message
*/
void print(MsgType param, FILE* const ostream = stderr);

#endif // RESPONSE_H
