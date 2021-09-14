/** \file
    \brief      String array structure
*/
#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

/** \brief      Structure containing array of strings
    \param      arr         Pointer to array of pointers to strings
    \param      size        Amount of strings in array
    \param      allocated   Amount of places for string in array
*/
struct String_array
{
    char** arr       {NULL};
    size_t size      {0};
    size_t allocated {0};
};

#endif // STRING_ARRAY_H
