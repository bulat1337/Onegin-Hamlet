#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "buffer_process.h"
#include "helpers.h"
#include "sorters.h"

void text_print(FILE *dest_file_ptr, char * *str_ptrs, size_t NLINES);
//printers

int main()
{
    const char file_name[] = "hamlet.txt";

    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL)
    {
        perror("ERROR:");
        exit(EXIT_FAILURE);
    }

    const size_t LEN = get_file_length(fp);

    char *buf = (char*)calloc(LEN, sizeof(char));
    allocated_ptrs_manager((char *)buf);

    fread_tjms(buf, fp, LEN);

    size_t NLINES = count_file_lines(buf, LEN);

    char * *str_ptrs = (char **)calloc(NLINES, sizeof(char *));
    allocated_ptrs_manager((char *)str_ptrs);

	ptr_arranger(str_ptrs, buf, LEN);

    FILE *fp_dest = fopen("dest.txt", "w");
    if (fp_dest == NULL)
    {
        perror("ERROR:");
        return -1;
    }

    text_print(fp_dest, str_ptrs, NLINES);

    fprintf(fp_dest, "\n-----------\n");

    str_sort(str_ptrs, NLINES);

    text_print(fp_dest, str_ptrs, NLINES);

    allocated_ptrs_manager();

    return 0;
}

