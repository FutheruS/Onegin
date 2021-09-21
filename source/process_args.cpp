#include "include/process_args.h"

MsgType process_args(int argc, char* argv[], char infile_name[], char outfile_name[], Modifiers* mods)
{
    if(argc < 2)
        return MsgType::NO_OPT;

    struct Options
    {
        int src     = 0;
        int dst     = 0;
        int format  = 0;
        int rsort   = 0;
        int ralpha  = 0;
    } opts;

    for(int iter = 1; iter < argc; iter++)
    {
        char command[MAX_COMMAND_SIZE] = "";
        if(memccpy(command, argv[iter], '\0', MAX_COMMAND_SIZE) == nullptr)
        {
            return MsgType::CMD_OVRFLW; //LONG_COMMAND
        }

        if(strcmp(command, "-h") == 0)
        {
            if(argc > 2)
                return MsgType::HLP_NOTE;
            else
                return MsgType::HLP;
        }
        else if(strcmp(command, "--src") == 0)
        {
            if(opts.src == 1)
                return MsgType::OPT_OVRWRT;

            iter++;
            if(iter >= argc)
                return MsgType::NO_IFL_NAME;

            if(memccpy(infile_name, argv[iter], '\0', MAX_FILENAME_SIZE) == nullptr)
            {
                return MsgType::FLNAME_OVRFLW; //LONG_FILENAME
            }

            opts.src = 1;
        }
        else if(strcmp(command, "--dst") == 0)
        {
            if(opts.dst == 1)
                return MsgType::OPT_OVRWRT;

            iter++;
            if(iter >= argc)
                return MsgType::NO_OFL_NAME;

            if(memccpy(outfile_name, argv[iter], '\0', MAX_FILENAME_SIZE) == nullptr)
            {
                return MsgType::FLNAME_OVRFLW; //LONG_FILENAME
            }

            opts.dst = 1;
        }
        else if(strcmp(command, "--ralpha") == 0)
        {
            if(opts.ralpha == 0 && opts.format == 0)
                opts.ralpha = 1;
            else
                return MsgType::OPT_OVRWRT;
        }
        else if(strcmp(command, "--rsort") == 0)
        {
            if(opts.rsort == 0 && opts.format == 0)
                opts.rsort = 1;
            else
                return MsgType::OPT_OVRWRT;
        }
        else if(strcmp(command, "--format") == 0)
        {
            if(opts.format == 0 && opts.ralpha == 0 && opts.rsort == 0)
                opts.format = 1;
            else
                return MsgType::OPT_OVRWRT;
        }
        else
        {
            return MsgType::BAD_CMD; //BAD_CMD
        }
    }

    if(opts.src == 0)
        return MsgType::NO_IFL_NAME;
    if(opts.dst == 0)
        return MsgType::NO_OFL_NAME;

    mods->format            = opts.format;
    mods->reverse_compare   = opts.ralpha;
    mods->reverse_sort      = opts.rsort;

    return MsgType::NOMSG;
}
