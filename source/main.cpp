#include "include/Text.h"
#include "include/process_args.h"
#include "include/sort.h"
#include "include/response.h"

int main(int argc, char* argv[])
{
    char infile_name[MAX_FILENAME_SIZE]     = "";
    char outfile_name[MAX_FILENAME_SIZE]    = "";

    Modifiers mods = {};

    MsgType msg = process_args(argc, argv, infile_name, outfile_name, &mods);
    if(msg != MsgType::NOMSG)
    {
        print(msg);
        return 1;
    }

    Text text{};

    msg = create_Text(&text, infile_name);
    if(msg != NOMSG)
    {
        print(msg);
        return 2;
    }

    sort_Text(&text, &mods);

    msg = print_Text(&text, outfile_name);
    if(msg != NOMSG)
    {
        print(msg);
        return 3;
    }

    destroy_Text(&text);

    return 0;
}
