#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "buffer_process.h"

size_t get_file_length(FILE *fp)
{
    size_t LEN = 0;

    fseek(fp, 0L, SEEK_END);
    LEN = ftell(fp);
    rewind(fp);

    return LEN;
}

size_t count_file_lines(char *buf, size_t LEN)
{
	size_t NLINES = 0;
	for (size_t i = 0; i < LEN; i++)
    {
        if(buf[i] == '\n')
        {
            NLINES++;
        }
    }

	return NLINES;
}

void ptr_arranger(char * *str_ptrs, char *buf, size_t LEN)
{
	str_ptrs[0] = buf;
	size_t line_ID = 0;
    for (size_t buf_ID = 0; buf_ID < LEN; buf_ID++)
    {
        if(buf[buf_ID] == '\n')
        {
            buf[buf_ID] = '\0';
            str_ptrs[line_ID + 1] = &buf[buf_ID+1];
            line_ID++;
        }
    }
}
