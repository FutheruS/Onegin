/** \file
    \brief      Output functions & messages
*/

#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <assert.h>
#include "../include/String_array.h"

const char ONEGIN_INTRO[]      = "Onegin\n"
                                 "Enter 'h' to open reference \n";

const char PROMPT[]            = ">";
const char PROMPT_INPUTFILE[]  = "Enter name of the input  file: ";
const char PROMPT_OUTPUTFILE[] = "Enter name of the output file: ";
const char SUCCESS[]           = "Done\n";
const char ONEGIN_HELP[]       = "'h'/'help'        - open reference\n"
                                 "'q'/'quit'        - quit program\n"
                                 "'p'/'process'     - process text\n";
const char BAD_COMMAND[]       = "Unknown command\n"
                                 "(enter 'q' to close the program, 'h' to open reference)\n";

const char BUFFER_OVERFLOW[]   = "Buffer overflow: number contains too many symbols\n"
                                 "(try using exponential form)\n";

const char BAD_INPUT_FILE[]    = "Error: cannot open input file\n";
const char BAD_OUTPUT_FILE[]   = "Error: cannot open output file\n";

/// Used to connect input and output
enum MsgType
{
    NOMSG = 1,              /// no output
    INTRO,                  /// intro
    PRMPT,                  /// prompt
    PRMPT_OFILE,            /// prompt for entering name of the input file
    PRMPT_IFILE,            /// prompt for entering name of the output file
    SCSS,                   /// message for successful program executing
    HELP,                   /// reference
    BAD_CMD,                /// message for bad input for command
    BUFF_OVRFLW,            /// message for buffer-overflowing input
    BAD_IFILE,              /// message for error in opening input file
    BAD_OFILE,              /// message for error in opening output file
};

/** \brief Prints message corresponding to param

    \param [out]    ostream     FILE* pointer to output file
    \param [in]     param       MsgType parameter, sets message
*/
void print(FILE* const ostream, MsgType param);

/** \brief Prints text from string array to file

    \param [in]     str_arr     Pointer to string array
    \param [out]    ostream     FILE* pointer to output file

*/
void print_str_arr(String_array* const str_arr, FILE* const ostream);

#endif // OUTPUT_H
