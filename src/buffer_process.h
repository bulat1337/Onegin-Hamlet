#ifndef BUFFER_PROCESS
#define BUFFER_PROCESS

size_t get_file_length(FILE *fp);
size_t count_file_lines(char *buf, size_t LEN); //buffer processing
void ptr_arranger(char * *str_ptrs, char *buf, size_t LEN);

#endif
