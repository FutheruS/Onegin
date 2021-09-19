#include "include/tests.h"

void test_print_buffer(char* begin, char* end)
{
    assert(begin && end);

    printf("-------------BUFFER------------- \n");
    while(begin < end)
    {
        printf("%d\n", *begin);
        begin++;
    }
    printf("------------ENDBUFFER------------\n");
}
void test_print_line(Index* index, int file_descr)
{
    assert(index);

    write(file_descr, "//////////\n", 11);

    print_line(index->begin, index->end, file_descr);
    print_line(index->begin_alpha, index->end_alpha, file_descr);

    write(file_descr, "//////////\n", 11);
}
