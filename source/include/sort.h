#ifndef SORT_H
#define SORT_H

#include <stdint.h>
#include "Text.h"
#include "response.h"

struct Modifiers
{
    bool format              = {0};     /// only formats text if set
    bool reverse_sort        = {0};     /// sorts text in descending order if set
    bool reverse_compare     = {0};     /// compares lines from end if set
};

void sort_Text(Text*, Modifiers*);

int line_cmp(const void* first, const void* second, const char* mods);

void shakesort(void* begin, size_t count, size_t size, int (*comp)(const void*, const void*));

#endif // SORT_H

