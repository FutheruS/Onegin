#include "../include/output.h"

void print_str_arr(String_array* const str_arr, FILE* const ostream)
{
    for(size_t i = 0; i < str_arr->size; i++)
    {
        fprintf(ostream, "%s\n", str_arr->arr[i]);
    }
}

void print(FILE* const ostream, MsgType param)
{
    switch(param)
    {
    case MsgType::BAD_CMD:
    {
        fprintf(ostream, BAD_COMMAND);
        break;
    }
    case MsgType::BUFF_OVRFLW:
    {
        fprintf(ostream, BUFFER_OVERFLOW);
        break;
    }
    case MsgType::HELP:
    {
        fprintf(ostream, ONEGIN_HELP);
        break;
    }
    case MsgType::INTRO:
    {
        fprintf(ostream, ONEGIN_INTRO);
        break;
    }
    case MsgType::PRMPT:
    {
        fprintf(ostream, PROMPT);
        break;
    }
    case MsgType::PRMPT_IFILE:
    {
        fprintf(ostream, PROMPT_INPUTFILE);
        break;
    }
    case MsgType::PRMPT_OFILE:
    {
        fprintf(ostream, PROMPT_OUTPUTFILE);
        break;
    }
    case MsgType::SCSS:
    {
        fprintf(ostream, SUCCESS);
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
    fflush(ostream);
}
