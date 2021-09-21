#include "include/Text.h"

///constructor block
static void set_index_arr(char* buffer, Index* index_arr, size_t index_arr_size)
{
    assert(buffer && index_arr);

    size_t iter = 0;
    int ch = 0;
    char* first_symbol = nullptr;
    char* last_symbol  = nullptr;

    for(size_t line_num = 0; line_num < index_arr_size; line_num++)
    {
        while(isspace(buffer[iter])) //skips ws until first symbol
            iter++;

        first_symbol = &buffer[iter];

        while(true)
        {
            ch = buffer[iter];

            if(ch == '\n' || ch == '\0')
                break;

            if(!isspace(ch))
                last_symbol = &buffer[iter]; //save last !ws symbol
            iter++;
        }

        index_arr[line_num].begin = first_symbol;
        index_arr[line_num].end = last_symbol + 1;

        first_symbol = nullptr;
        last_symbol  = nullptr;
    }
}

static MsgType create_index_arr(Index** dst_index_arr, size_t* dst_index_arr_size, char* buffer)
{
    assert(buffer);
    assert(dst_index_arr_size);

    size_t iter     = 0;
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
        return MsgType::BAD_ALLOC;
    }
#ifdef TESTS
    fprintf(stderr, "line_num: %d\n", line_num);
#endif // TESTS

    set_index_arr(buffer, index_arr, line_num);

    *dst_index_arr_size = line_num;
    *dst_index_arr = index_arr;

    return MsgType::NOMSG;
}

static MsgType create_buffer(char** dst_buffer, size_t* dst_buffer_size, char* file_name)
{
    struct stat file_stat = {};
    if(stat(file_name, &file_stat) == -1)
        return MsgType::BAD_IFILE;

    size_t file_size = file_stat.st_size;

    char* buffer = nullptr;
    buffer = (char*) calloc(file_size + 1, sizeof(char)); // + 1 for '\0'
    if(buffer == nullptr)
        return MsgType::BAD_ALLOC;

    errno = 0;
    FILE* istream = fopen(file_name, "r");
    if(errno != 0)
    {
        free(buffer);
        return MsgType::BAD_IFILE;
    }

    errno = 0;
    size_t file_read = fread(buffer, sizeof(char), file_size, istream);
    if(errno != 0)
    {
        free(buffer);
        if(fclose(istream) == EOF)
			return MsgType::UNEXPCTD_ERR;

        return MsgType::BAD_IFILE;
    }

    if(fclose(istream) == EOF)
    {
        free(buffer);
        return MsgType::UNEXPCTD_ERR;
    }

    buffer = (char*) realloc(buffer, (file_read + 1) * sizeof(char)); //+ 1 for '\0'
    if(buffer == nullptr)
    {
        free(buffer);
        return MsgType::BAD_ALLOC;
    }

    buffer[file_read] = '\0';

    *dst_buffer = buffer;
    *dst_buffer_size = file_read;

    return MsgType::NOMSG;
}

MsgType create_Text(Text* text, char* file_name)
{
    assert(text && file_name);

    if(text == nullptr || file_name == nullptr)
        return MsgType::NULLPTR;

    char* buffer = nullptr;
    size_t buffer_size = 0;
    MsgType msg = create_buffer(&buffer, &buffer_size, file_name);
    if(msg != MsgType::NOMSG)
        return msg;

    Index* index_arr = nullptr;
    size_t index_arr_size = 0;
    msg = create_index_arr(&index_arr, &index_arr_size, buffer);
    if(msg != MsgType::NOMSG)
    {
        free(buffer);
        return msg;
    }

    text->buffer = buffer;
    text->index_arr = index_arr;
    text->index_arr_size = index_arr_size;
    text->buffer_size = buffer_size;

    return NOMSG;
}

///output block
static MsgType print_line(char* begin, char* end, FILE* ostream)
{
    assert(begin && end);

    size_t size = end - begin;
    if(fwrite(begin, sizeof(char), size, ostream) != size)
        return MsgType::BAD_OFILE;

    if(fwrite("\n", sizeof(char), 1, ostream) != 1)
        return MsgType::BAD_OFILE;

    return MsgType::NOMSG;
}

MsgType print_Text(Text* text, char* file_name)
{
	if(text == nullptr || file_name == nullptr)
		return MsgType::NULLPTR;

	FILE* ostream = fopen(file_name, "w");
	if(ostream == nullptr)
		return BAD_OFILE;

	for(size_t iter = 0; iter < text->index_arr_size; iter++)
    {
        MsgType msg = print_line(text->index_arr[iter].begin, text->index_arr[iter].end, ostream);
            if(msg != MsgType::NOMSG)
                return msg;
    }

	if(fclose(ostream) == EOF)
		return MsgType::UNEXPCTD_ERR;

	return MsgType::NOMSG;
}


///destructor
void destroy_Text(Text* text)
{
    free(text->index_arr);
    free(text->buffer);
}
