#include "include/processing.h"

int str_cmp(const void* first_ptr, const void* second_ptr)
{
    assert(first_ptr && second_ptr);

    const Index* first_line   = (const Index*) first_ptr;
    const Index* second_line  = (const Index*) second_ptr;

    char* fl_begin      = first_line->begin_alpha;
    char* fl_end        = first_line->end_alpha;
    char* sl_begin      = second_line->begin_alpha;
    char* sl_end        = second_line->end_alpha;

    while(true)
    {
        if(fl_begin == fl_end)
        {
            if(sl_begin == sl_end)
                return 0;
            else
                return -1;
        }
        if(sl_begin == sl_end)
            return 1;

        if(*fl_begin > *sl_begin)
            return 1;
        if(*fl_begin < *sl_begin)
            return -1;

        fl_begin++;
        sl_begin++;
    }
}

int str_cmp_rev(const void* first_ptr, const void* second_ptr)
{
    assert(first_ptr && second_ptr);

    const Index* first_line   = (const Index*) first_ptr;
    const Index* second_line  = (const Index*) second_ptr;

    char* fl_end        = first_line->begin_alpha - 1;
    char* fl_begin      = first_line->end_alpha - 1;
    char* sl_end        = second_line->begin_alpha - 1;
    char* sl_begin      = second_line->end_alpha - 1;

    while(true)
    {
        if(fl_begin == fl_end)
        {
            if(sl_begin == sl_end)
                return 0;
            else
                return -1;
        }
        if(sl_begin == sl_end)
            return 1;

        if(*fl_begin > *sl_begin)
            return 1;
        if(*fl_begin < *sl_begin)
            return -1;

        fl_begin--;
        sl_begin--;
    }
}

int neg_str_cmp(const void* first_ptr, const void* second_ptr)
{
    return -str_cmp(first_ptr, second_ptr);
}

int neg_str_cmp_rev(const void* first_ptr, const void* second_ptr)
{
    return -str_cmp_rev(first_ptr, second_ptr);
}

void sort_index_arr(Index* index_arr, size_t index_arr_size, Modifiers* mods)
{
    assert(index_arr);

    if(mods->reverse_sort)
    {
        if(mods->reverse_compare)
            qsort(index_arr, index_arr_size, sizeof(Index), neg_str_cmp_rev);
        else
            qsort(index_arr, index_arr_size, sizeof(Index), neg_str_cmp);

    }
    else
    {
        if(mods->reverse_compare)
            qsort(index_arr, index_arr_size, sizeof(Index), str_cmp_rev);
        else
            qsort(index_arr, index_arr_size, sizeof(Index), str_cmp);

    }
}
