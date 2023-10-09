#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "buffer_process.h"
//fstat //no stat.h
size_t get_file_length(FILE *fp)
{
    size_t LEN = 0;

    fseek(fp, 0L, SEEK_END);
    LEN = (size_t)ftell(fp);
    rewind(fp);

    return LEN;
}

size_t count_file_lines(struct Buffer_w_info buf_n_len)
{
	size_t NLINES = 0;
	for (size_t buf_ID = 0; buf_ID < buf_n_len.LEN; buf_ID++)
    {
        if(buf_n_len.buf[buf_ID] == '\n')
        {
            NLINES++;
        }
    }

	return NLINES;
}

void ptr_arranger(char * *str_ptrs, struct Buffer_w_info buf_n_len)
{
	str_ptrs[0] = buf_n_len.buf;
	size_t line_ID = 1;
    for (size_t buf_ID = 0; buf_ID < buf_n_len.LEN; buf_ID++)
    {
        if(buf_n_len.buf[buf_ID] == '\n')
        {
            buf_n_len.buf[buf_ID] = '\0';
			if(buf_ID + 1 < buf_n_len.LEN)
			{
            	str_ptrs[line_ID] = &(buf_n_len.buf[buf_ID + 1]);
            	line_ID++;
			}
        }
    }
}
