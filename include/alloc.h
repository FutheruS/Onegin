/** \file
    \brief      Functions for allocating memory

*/

#ifndef ALLOC_H
#define ALLOC_H

#include <string.h>
#include <stdlib.h>
#include "../include/String_array.h"

/**
    \brief      Reallocate and initialize
    \details    Uses realloc(), initializes added space like calloc()

    \param [in]         ptr         Pointer to memory to be reallocated
    \param [in, out]    nobj        Passed-by-reference amount of objects pointed to
    \param [in]         new_nobj    New amount of objects pointed to
    \param [in]         size        Size of objects pointed to

    \return Pointer to new, reallocated memory
*/
void* recalloc(void* ptr, size_t* nobj, size_t new_nobj, size_t size);

/**
    \brief      Frees allocated for string array memory
    \details    Uses free() to free strings and array itself

    \param [in]         str_arr     Pointer to String array to be freed
*/
void free_str_arr(String_array* str_arr);

#endif // ALLOC_H
