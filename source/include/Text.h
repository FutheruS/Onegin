#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>

#include "response.h"

struct Index
{
    char* begin         {nullptr};
    char* end           {nullptr};
};

struct Text
{
    size_t buffer_size  = 0;
    char* buffer        = nullptr;

    size_t index_arr_size = 0;
    Index* index_arr      = nullptr;
};

MsgType create_Text(Text*, char* infile_name);

MsgType print_Text(Text* text, char* file_name);

void destroy_Text(Text*);

#endif // TEXT_H
