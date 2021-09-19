#include "include/tests.h"
#include "include/input.h"
#include "include/output.h"
#include "include/Index.h"
#include "include/processing.h"
#include "include/process_args.h"

int main(int argc, char* argv[])
{
    char infile_name[MAX_FILENAME_SIZE]     = "";
    char outfile_name[MAX_FILENAME_SIZE]    = "";

    Modifiers mods = {};
    MsgType msg = MsgType::NOMSG;

    msg = process_args(argc, argv, infile_name, outfile_name, &mods);
    if(msg != MsgType::NOMSG)
    {
        print(msg);
        return 0;
    }

    int infile_descr = -1;
    int outfile_descr = -1;
    msg = open_files(infile_name, outfile_name, &infile_descr, &outfile_descr);
    if(msg != MsgType::NOMSG)
    {
        print(msg);
        close(infile_descr);
        close(outfile_descr);
        return 0;
    }

    size_t buffer_size = 0;

    char* buffer = create_buffer(infile_descr, &buffer_size);

    if(buffer == nullptr)
    {
        print(MsgType::BUFF_ERR);
        return 0;
    }

    size_t index_arr_size = 0;

    Index* index_arr = create_index_arr(buffer, &index_arr_size);

    if(index_arr == nullptr)
    {
        print(MsgType::INDX_ARR_ERR);
    }

    if(!mods.format)
        sort_index_arr(index_arr, index_arr_size, &mods);

    print_index_arr(index_arr, index_arr_size, outfile_descr);

    free(buffer);
    free(index_arr);

    return 0;
}
