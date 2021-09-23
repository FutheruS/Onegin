#include "include/sort.h"

static int line_cmp(const void* first, const void* second)
{
    const char* fl_begin  = ((const Index*) first)->begin;
    const char* fl_end    = ((const Index*) first)->end;
    const char* sl_begin  = ((const Index*) second)->begin;
    const char* sl_end    = ((const Index*) second)->end;

    while(!isalpha(*fl_begin))
    {
        fl_begin++;
        if(fl_begin == fl_end)
            break;
    }

    while(!isalpha(*sl_begin))
    {
        sl_begin++;
        if(sl_begin == sl_end)
            break;
    }

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

static int line_cmp_neg(const void* first, const void* second)
{
    return -line_cmp(first, second);
}

static int line_cmp_rev(const void* first, const void* second)
{
    const char* fl_end  = ((const Index*) first)->begin;
    const char* fl_begin    = ((const Index*) first)->end - 1;
    const char* sl_end = ((const Index*) second)->begin;
    const char* sl_begin    = ((const Index*) second)->end - 1;

    while(!isalpha(*fl_begin))
    {
        fl_begin--;
        if(fl_begin == fl_end)
            break;
    }

    while(!isalpha(*sl_begin))
    {
        sl_begin--;
        if(sl_begin == sl_end)
            break;
    }

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

static int line_cmp_rev_neg(const void* first, const void* second)
{
    return -line_cmp_rev(first, second);
}

void sort_Text(Text* text, Modifiers* mods)
{
    if(mods->format == 1)
        return;

    int (*comp) (const void* first, const void* second) = nullptr;

    if(mods->reverse_compare)
    {
        if(mods->reverse_sort)
            comp = &line_cmp_rev_neg;
        else
            comp = &line_cmp_rev;
    }
    else
    {
        if(mods->reverse_sort)
            comp = &line_cmp_neg;
        else
            comp = &line_cmp;
    }

    shakesort(text->index_arr, text->index_arr_size, sizeof(Index), comp);
}

/** \brief  Swaps any type

    \param [in] [out]   first   Pointer to first object
    \param [in] [out]   second  Pointer to second object
    \param [in]         size    Size of passed objects in bytes
*/
static void swap(void* first, void* second, size_t size)
{
    while(size >= 8)
    {
        int64_t temp = *((int64_t*) first);
        *((int64_t*) first) = *((int64_t*) second);
        *((int64_t*) second) = temp;

        first   +=8;
        second  +=8;
        size -= sizeof(int64_t);
    }
    while(size >= 4)
    {
        int32_t temp = *((int32_t*) first);
        *((int32_t*) first) = *((int32_t*) second);
        *((int32_t*) second) = temp;

        first   +=4;
        second  +=4;
        size -= sizeof(int32_t);
    }
    while(size >= 2)
    {
        int16_t temp = *((int16_t*) first);
        *((int16_t*) first) = *((int16_t*) second);
        *((int16_t*) second) = temp;

        first   +=2;
        second  +=2;
        size -= sizeof(int16_t);
    }
    while(size >= 1)
    {
        int8_t temp = *((int8_t*) first);
        *((int8_t*) first) = *((int8_t*) second);
        *((int8_t*) second) = temp;

        first   +=1;
        second  +=1;
        size -= sizeof(int8_t);
    }
}

/** \brief Sort function (shakesort algorithm)

    \param [in] [out]   begin       Pointer to first element of array
    \param [in] [out]   end         Pointer to element after last element of array
    \param [in]         size        Size of element in bytes
    \param [in]         comp        Compare function
    \param [in]         comp_args   Argument string for compare function
*/
void shakesort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*))
{
    char* left = (char*) ptr;
    char* right = ((char*) ptr) + count * size - size;
    bool sorted = false;

    while(!sorted)
    {
        sorted = true;

        if(right == left) return;

        for(char* iter = left; iter != right; iter += size)
        {
            if(comp(iter, iter + size) > 0)
            {
                swap(iter, iter + size, size);
                sorted = false;
            }
        }
        right -= size;

        if(right == left) return;

        for(char* iter = right; iter != left; iter -= size)
        {
            if(comp(iter, iter - size) < 0)
            {
                swap(iter, iter - size, size);
                sorted = false;
            }
        }
        left += size;
    }
}
