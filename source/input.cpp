#include "include/input.h"

char* create_buffer(int file_descr, size_t* buffer_size)
{
    assert(buffer_size);

    struct stat file_stat = {};
    if(fstat(file_descr, &file_stat) == -1)
        return nullptr;

    size_t file_size = file_stat.st_size;

    char* buffer = (char*) calloc(file_size + 1, sizeof(char));
    if(buffer == nullptr)
        return nullptr;

    size_t read_size = read(file_descr, buffer, file_size);

#ifdef TESTS
    fprintf(stderr, "read_size: %d\n", read_size);
#endif // TESTS

    buffer = (char*) realloc(buffer, read_size + 1);

    buffer[read_size] = '\0';

    *buffer_size = read_size;

    close(file_descr);

    return buffer;
}

Index* create_index_arr(char* buffer, size_t* index_arr_size)
{
    assert(buffer);
    assert(index_arr_size);

    size_t iter = 0;
    size_t line_num = 0;
    bool nline_flag = 0;

    while(true)
    {
        int ch = buffer[iter];

        if((ch == '\n' || ch == '\0') && nline_flag == 0)
        {
            nline_flag = 1;
            line_num++;
        }

        if(!isspace(ch))
            nline_flag = 0;

    #ifdef TESTS
        fprintf(stderr, "iter:%.3d ch:%c line_num:%.3d\n", iter, ch, line_num);
    #endif // TESTS

        if(ch == '\0')
            break;

        iter++;
    }

    Index* index_arr = (Index*) calloc(line_num, sizeof(Index));

    if(index_arr == nullptr)
    {
        return nullptr;
    }
#ifdef TESTS
    fprintf(stderr, "line_num: %d\n", line_num);
#endif // TESTS

    *index_arr_size = line_num;

    set_index_arr(buffer, index_arr, line_num);

    return index_arr;
}

void set_index_arr(char* buffer, Index* index_arr, size_t index_arr_size)
{
    assert(buffer);
    assert(index_arr);

    size_t iter = 0;
    bool first_alpha_flag = 1;

    char* first_symbol  = nullptr;
    char* first_alpha   = nullptr;
    char* last_alpha    = nullptr;
    char* last_symbol   = nullptr;

    for(size_t line_num = 0; line_num < index_arr_size; line_num++)
    {
        while(isspace(buffer[iter]))
            iter++;

        first_symbol = &buffer[iter];

        while(true)
        {
            int ch = buffer[iter];

            if(ch == '\n' || ch == '\0')
                break;

            if(!isspace(ch))
                last_symbol = &buffer[iter];

            if(first_alpha_flag && isalpha(ch))
            {
                first_alpha = &buffer[iter];
                first_alpha_flag = 0;
            }
            if(!first_alpha_flag && isalpha(ch))
            {
                last_alpha = &buffer[iter];
            }

            iter++;
        }

        if(first_alpha == nullptr)
            first_alpha = first_symbol;
        if(last_alpha == nullptr)
            last_alpha = last_symbol;

        index_arr[line_num].begin       = first_symbol;
        index_arr[line_num].begin_alpha = first_alpha;
        index_arr[line_num].end_alpha  = last_alpha + 1;
        index_arr[line_num].end         = last_symbol + 1;

        first_symbol  = nullptr;
        first_alpha   = nullptr;
        last_alpha    = nullptr;
        last_symbol   = nullptr;

        first_alpha_flag = 1;
    }
}
