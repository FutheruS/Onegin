#include "include/output.h"

void print_line(char* begin, char* end, int file_descr)
{
    assert(begin && end);

    write(file_descr, begin, end - begin);
    write(file_descr, "\n", 1);
}

void print_index_arr(Index* index_arr, size_t index_arr_size, int file_descr)
{
    assert(index_arr);

    for(size_t iter = 0; iter < index_arr_size; iter++)
    {
    #ifndef TESTS
        print_line(index_arr[iter].begin, index_arr[iter].end, file_descr);
    #else
        test_print_line(&index_arr[iter], file_descr);
    #endif
    }

    close(file_descr);
}

void print(MsgType param, FILE* const ostream)
{
    switch(param)
    {
    case MsgType::NOMSG:
    {
        break;
    }
    case MsgType::HLP:
    {
        fprintf(ostream, HELP);
        break;
    }
    case MsgType::NO_OPT:
    {
        fprintf(ostream, NO_OPTIONS);
        break;
    }
    case MsgType::NO_IFL_NAME:
    {
        fprintf(ostream, NO_IFILE_NAME);
        break;
    }
    case MsgType::NO_OFL_NAME:
    {
        fprintf(ostream, NO_OFILE_NAME);
        break;
    }
    case MsgType::CMD_OVRFLW:
    {
        fprintf(ostream, COMMAND_OVERFLOW);
        break;
    }
    case MsgType::OPT_OVRWRT:
    {
        fprintf(ostream, OPTION_OVERWRITE);
        break;
    }
    case MsgType::FLNAME_OVRFLW:
    {
        fprintf(ostream, FILENAME_OVERFLOW);
        break;
    }
    case MsgType::BAD_CMD:
    {
        fprintf(ostream, BAD_COMMAND);
        break;
    }
    case MsgType::BUFF_ERR:
    {
        fprintf(ostream, "%s %s\n", BUFFER_ERR, strerror(errno));
        break;
    }
    case MsgType::INDX_ARR_ERR:
    {
        fprintf(ostream,"%s %s\n", INDEX_ARRAY_ERR, strerror(errno));
        break;
    }
    case MsgType::BAD_IFILE:
    {
        fprintf(ostream, BAD_INPUT_FILE);
        break;
    }
    case MsgType::BAD_OFILE:
    {
        fprintf(ostream, BAD_OUTPUT_FILE);
        break;
    }
    default:
    {
        assert(0);
    }
    }
}
