#include "../include/input.h"

size_t get_line(FILE* const istream, char** line)
{
    assert(istream);

    char* temp_line = (char*) calloc(DEFAULT_LINE_SIZE, sizeof(char));
    size_t temp_line_allocated = DEFAULT_LINE_SIZE;

    int ch = 0;

    while((ch = getc(istream)) != EOF && isspace(ch)) //skips whitespaces between lines
        ;
    ungetc(ch, istream);

    size_t temp_line_sz = 0;
    bool ws_flag = 0;

    while(true)
    {
        if(temp_line_sz == temp_line_allocated) //check for overflow
        {
            temp_line = (char*) recalloc(temp_line, &temp_line_allocated, temp_line_allocated * 2, sizeof(char));
        }

        ch = getc(istream);

        if(ch == '\n' || ch == EOF) //check for end of line or EOF
            break;

        if(isspace(ch))
        {
            if(ch != ' ')
                ch = ' ';

            if(ws_flag)
                continue;
            else
                ws_flag = 1;
        }
        else
        {
            ws_flag = 0;
        }

        temp_line[temp_line_sz] = (char) ch;
        temp_line_sz++;
    }
    temp_line[temp_line_sz] = '\0'; //c-style string

    *line = temp_line;

    return temp_line_sz;
}

size_t get_command(FILE* const istream, char line[], const size_t maxline)
{
    assert(istream);
    assert(line);

    int ch = 0;

    while((ch = getc(istream)) != EOF && isspace(ch)) //skips whitespaces between lines
        ;
    ungetc(ch, istream);

    size_t curr_len = 0;
    bool ws_flag = 0;

    while(true)
    {
        if(curr_len == maxline - 1) //check for overflow
        {
            fprintf(stderr, "WARNING: string overflow");
            break;
        }

        ch = getc(istream);

        if(ch == '\n' || ch == EOF) //check for end of line or EOF
            break;

        ch = tolower(ch);

        line[curr_len] = (char) ch;
        curr_len++;
    }
    line[curr_len] = '\0'; //c-style string

    return curr_len;
}

void fill_str_arr(String_array* str_arr, FILE* const istream)
{
    size_t arr_sz = 0;
    char** arr = (char**) calloc(DEFAULT_STRARR_SIZE, sizeof(char*));
    size_t arr_allocated = DEFAULT_STRARR_SIZE;

    while(true)
    {
        if(arr_allocated == arr_sz)
            arr = (char**) recalloc(arr, &arr_allocated, arr_allocated * 2, sizeof(char*));

        char* buffer = NULL;

        if(get_line(istream, &buffer) == 0)
        {
            free(buffer);
            break;
        }

        arr[arr_sz] = buffer;
        arr_sz++;
    }
    str_arr->allocated = arr_allocated;
    str_arr->size      = arr_sz;
    str_arr->arr       = arr;
}
