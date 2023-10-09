#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "helpers.h"

void str_swap(char * *str_1, char * *str_2)
{
    char *temp = *str_1;
    *str_1 = *str_2;
    *str_2 = temp;
}

void allocated_ptrs_manager(char *allocated_ptr)
{ //  atexit();
    static char *allocated_ptrs[10] = {}; //reealloc(after stack task)
    static size_t ptr_ct = 0;
    if (allocated_ptr == (char *)1) //if очищалось
    {
        for(size_t ptr_ID = 0; ptr_ID < ptr_ct; ptr_ID++)
        {
			//assert
            free(allocated_ptrs[ptr_ID]);
            printf("ALLOCATED_PTR_MANAGER: all allocated pointers has been erased");
        }
    }
    else
    {
        if (allocated_ptr == NULL)
        {
            printf("Not enough memory for calloc"); //Q errno?
            exit(EXIT_FAILURE);
        }

        printf("ALLOCATED_PTR_MANAGER: allocated_ptrs[%lu] has beed registered\n", ptr_ct);
        allocated_ptrs[ptr_ct] = (char *)allocated_ptr;
        ptr_ct++;
    }
}

void fread_tjms(struct Buffer_w_info buf_n_len, FILE *file_ptr) //rename tjms //fopen
{
    size_t LEN_check = fread(buf_n_len.buf, sizeof(char), buf_n_len.LEN, file_ptr);
    if (LEN_check != buf_n_len.LEN)
    {
        printf("fread error");
        exit(EXIT_FAILURE);
    }
    fclose(file_ptr);
}

char *str_reverse(char * str) // cmprator
{
    size_t str_len = strlen(str);
    char *rev_str = (char *)calloc(str_len + 1, sizeof(char));
    for(size_t letter_ID = 0; letter_ID < str_len; letter_ID++)
    {
        rev_str[letter_ID] = str[str_len - letter_ID - 1];
    }
    rev_str[str_len] = '\0';

    return rev_str;
}

int str_comparator(const void *str_1, const void *str_2)
{
	int cmp_result = strcmp( *(const char * const*)str_1, *(const char * const*)str_2);
	if(cmp_result > 0)
	{
		return 1;
	}
	else if(cmp_result == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
