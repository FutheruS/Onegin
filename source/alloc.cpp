#include "../include/alloc.h"

void* recalloc(void* ptr, size_t* nobj, size_t new_nobj, size_t size)
{
    void* new_ptr = realloc(ptr, new_nobj*size);

    memset(new_ptr + (*nobj) * size, 0, (new_nobj-(*nobj))*size);

    *nobj = new_nobj;

    return new_ptr;
}

void free_str_arr(String_array* str_arr)
{
    for(size_t i = 0; i < str_arr->size; i++)
        free(str_arr->arr[i]);

    free(str_arr->arr);
}
