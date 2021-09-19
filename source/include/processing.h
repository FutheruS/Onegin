#ifndef PROCESSING_H
#define PROCESSING_H

#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include "Index.h"
#include "tests.h"

struct Modifiers
{
    bool format              = {0};     /// only formats text if set
    bool reverse_sort        = {0};     /// sorts text in descending order if set
    bool reverse_compare     = {0};     /// compares lines from end if set
};

int str_cmp(const void* first_ptr, const void* second_ptr);

int str_cmp_rev(const void* first_ptr, const void* second_ptr);

int neg_str_cmp(const void* first_ptr, const void* second_ptr);

int neg_str_cmp_rev(const void* first_ptr, const void* second_ptr);

void sort_index_arr(Index* index_arr, size_t index_arr_size, Modifiers* mods);

#endif // PROCESSING_H
