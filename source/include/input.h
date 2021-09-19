/** \file
    \brief      Input functions & global constants
*/

#ifndef INPUT_H
#define INPUT_H

#define _GNU_SOURCE

#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <ctype.h>
#include <sys/stat.h>

#include "../include/tests.h"
#include "../include/Index.h"
#include "../include/processing.h"


/** \brief Allocates buffer, fills from file
*/
char* create_buffer(int file_descr, size_t* buffer_size);

/** \brief Allocates array of Index structures with size depending on lines in buffer
*/
Index* create_index_arr(char* buffer, size_t* index_arr_size);

/** \brief Sets Index structures pointers to first and last symbol of lines
*/
void set_index_arr(char* buffer, Index* index_arr, size_t index_arr_size);

#endif // INPUT_H
