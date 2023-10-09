#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "helpers.h"
#include "printers.h"

void text_print(FILE *dest_file_ptr, char * *str_ptrs, size_t NLINES)
{
    for(size_t line_ID = 0; line_ID < NLINES; line_ID++)
    {
        fprintf(dest_file_ptr, "%d - %s\n", str_ptrs[line_ID][0], str_ptrs[line_ID]);
    }
}
