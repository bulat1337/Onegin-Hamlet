#ifndef HELPERS_H
#define HELPERS_H

void str_swap(char * *str_1, char * *str_2);
void allocated_ptrs_manager(char *allocated_ptr = (char *)-1);
void fread_tjms(char *buffer, FILE *file_ptr, size_t length);
char *str_reverse(char * str);//helpers

#endif
