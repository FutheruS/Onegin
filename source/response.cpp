#include "include/response.h"

void print(MsgType param, FILE* const ostream)
{
    switch(param)
    {
        case MsgType::HLP:
        {
            fprintf(ostream, HELP);
            break;
        }
        case MsgType::HLP_NOTE:
        {
            fprintf(ostream, "%s\n%s", HELP, NOTE);
            break;
        }
        case MsgType::NO_OPT:
        {
            fprintf(ostream, NO_OPTIONS);
            break;
        }
        case MsgType::OPT_OVRWRT:
        {
            fprintf(ostream, OPTION_OVERWRITE);
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
        case MsgType::FLNAME_OVRFLW:
        {
            fprintf(ostream, FILENAME_OVERFLOW);
            break;
        }
        case MsgType::NOMSG:
        {
            break;
        }
        case MsgType::BAD_CMD:
        {
            fprintf(ostream, BAD_COMMAND);
            break;
        }
        case MsgType::BAD_IFILE:
        {
            fprintf(ostream, "%s %s", BAD_INPUT_FILE, strerror(errno));
            break;
        }
        case MsgType::BAD_OFILE:
        {
            fprintf(ostream, "%s %s", BAD_OUTPUT_FILE, strerror(errno));
            break;
        }
        case MsgType::BAD_ALLOC:
        {
            fprintf(ostream, BAD_ALLOCATION);
            break;
        }
        case MsgType::NULLPTR:
        {
            fprintf(ostream, NULLPOINTER);

            assert(0);
            break;
        }
        case MsgType::UNEXPCTD_ERR:
        {
            fprintf(ostream, UNEXPECTED_ERROR);

            assert(0);
            break;
        }
        default:
        {
            assert(0);
        }
    }
}
