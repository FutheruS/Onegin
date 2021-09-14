/** \file
    \brief      Input functions & global constants
*/

#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "../include/alloc.h"
#include "../include/String_array.h"

/// Max length for command
const size_t MAX_COMMAND_SIZE = 128;
/// Max length for name of file
const size_t MAX_FILENAME_SIZE = 128;
/// Default size of array of lines
const size_t DEFAULT_STRARR_SIZE = 16;
/// Default size of line
const size_t DEFAULT_LINE_SIZE = 16;

/** \brief      Reads line
    \details    Reads line, cleans all preliminary whitespaces, cleans multiple whitespaces
                reallocates for new input

    \param [in]     istream    FILE* pointer to input file
    \param [out]    line       Passed-by-pointer pointer to string

    \warning    Uses allocation (calloc, realloc)
    \return     Amount of read symbols
*/
size_t get_line(FILE* const istream, char** line);

/** \brief      Reads command
    \details    Reads command, ignores preliminary whitespaces, ends line with '\0' (c-style)

    \param [in]     istream    FILE* pointer to input file
    \param [out]    command    String for writing command
    \param [in]     maxcommand Max length for command

    \return     Amount of read symbols
*/
size_t get_command(FILE* const istream, char command[], const size_t maxcommand);

/** \brief      Fills string array from istream
    \details    Uses get_line. Reallocates in str_arr if needed

    \param [in]     istream     FILE* pointer to input file
    \param [out]    str_arr     String array containing array and it's parameters

*/
void fill_str_arr(String_array* str_arr, FILE* const istream);

#endif // INPUT_H
