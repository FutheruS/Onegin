#ifndef TESTS_H
#define TESTS_H

//#define TESTS

#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include "output.h"
#include "Index.h"

void test_print_buffer(char* begin, char* end);

void test_print_line(Index* index, int file_descr);

#endif // TESTS_H
