#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "buffer_process.h"
#include "helpers.h"
#include "sorters.h"

void text_print(FILE *dest_file_ptr, char * *str_ptrs, size_t NLINES);
//printers
//with open file
// printf wrapper: LOG("Hello meow!"); -> "[log] Hello meow";
// LOG("buffer ptr is %p", buffer_ptr); -> "[log] buffer ptr is 0x898989"
// макрос переменным к эл

int main()
{
	struct Buffer_w_info buf_n_len =
	{
		.buf = NULL,
		.LEN = 0
	};
    const char file_name[] = "hamlet.txt"; //argv

    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL)
    {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }

    buf_n_len.LEN = get_file_length(fp);

    buf_n_len.buf = (char*)calloc(buf_n_len.LEN, sizeof(char));
    allocated_ptrs_manager((char *)buf_n_len.buf);

    fread_tjms(buf_n_len, fp); //parsing

    size_t NLINES = count_file_lines(buf_n_len);

    char * *str_ptrs = (char **)calloc(NLINES, sizeof(char *));
    allocated_ptrs_manager((char *)str_ptrs);

	ptr_arranger(str_ptrs, buf_n_len);

    FILE *fp_dest = fopen("dest.txt", "wb");
    if (fp_dest == NULL)
    {
        perror("ERROR:");
        return -1;
    }

    text_print(fp_dest, str_ptrs, NLINES);

	int (*comparator_ptr) (const void *, const void *) = str_comparator;

    qsort(str_ptrs, NLINES, sizeof(char *), comparator_ptr); //struct for ptrs n nlines
	fprintf(fp_dest, "\n------------------\n");
    text_print(stdout, str_ptrs, NLINES);

    allocated_ptrs_manager();

    return 0;
}

