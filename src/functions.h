#ifndef H_FUNCTIONS
#define H_FUNCTIONS
#include <stdio.h>
#include <stdlib.h>

size_t check_file(FILE* input, size_t* is_uint);

int32_t check_string(char* str, size_t* is_uint);

void sort_uint(FILE* input, FILE* output, size_t size);

void sort_double(FILE* input, FILE* output, size_t size);
#endif
