#ifndef BUFFER_PROCESS
#define BUFFER_PROCESS
#include "helpers.h"

size_t get_file_length(FILE *fp);
size_t count_file_lines(struct Buffer_w_info buf_n_len);
void ptr_arranger(char * *str_ptrs, struct Buffer_w_info buf_n_len);

#endif
