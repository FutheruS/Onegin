#include "../include/UI.h"

void onegin_client()
{
    print(stdout, MsgType::INTRO);

    while(true)
    {
        print(stdout, MsgType::PRMPT);

        char command[MAX_COMMAND_SIZE] = "";
        get_command(stdin, command, MAX_COMMAND_SIZE);

        if(strcmp(command, "help") == 0 || strcmp(command, "h") == 0)
        {
            print(stdout, MsgType::HELP);
            continue;
        }
        else if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0)
        {
            break;
        }
        else if (strcmp(command, "process") == 0 || strcmp(command, "p") == 0)
        {

            char inputfile_name[MAX_FILENAME_SIZE] = "";
            char outputfile_name[MAX_FILENAME_SIZE] = "";

            print(stdout, MsgType::PRMPT_IFILE);
            get_command(stdin, inputfile_name, MAX_FILENAME_SIZE);

            print(stdout, MsgType::PRMPT_OFILE);
            get_command(stdin, outputfile_name, MAX_FILENAME_SIZE);

            FILE* const istream = fopen(inputfile_name,  "r");

            if(istream == NULL)
            {
                print(stderr, MsgType::BAD_IFILE);
                continue;
            }

            FILE* const ostream = fopen(outputfile_name, "w");

            if(ostream == NULL)
            {
                print(stderr, MsgType::BAD_OFILE);
                continue;
            }

            String_array str_arr {0};

            fill_str_arr(&str_arr, istream);

            //process_text();

            print_str_arr(&str_arr, ostream);

            if(fflush(ostream) == EOF)
                fprintf(stderr, "CRITICAL ERROR: ostream cannot be flushed");

            free_str_arr(&str_arr);

            print(stdout, MsgType::SCSS);
        }
        else
        {
            print(stdout, MsgType::BAD_CMD);
        }
    }
}
