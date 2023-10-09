#ifndef HELPERS_H
#define HELPERS_H

struct Buffer_w_info
{
	char *buf;
	size_t LEN;
};

void str_swap(char * *str_1, char * *str_2);
void allocated_ptrs_manager(char *allocated_ptr = (char *)1); //const for 1
void fread_tjms(struct Buffer_w_info buf_n_len, FILE *file_ptr);
char *str_reverse(char * str);//helpers
int str_comparator(const void *str1, const void *str2);

#endif
