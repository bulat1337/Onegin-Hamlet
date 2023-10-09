#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "sorters.h"
#include "helpers.h"

void str_sort(char * *str_ptrs,  size_t NLINES) //const
{
    for (size_t n1 = 0; n1 < NLINES - 1; n1++)
    {
        for (size_t n2 = n1 + 1; n2 < NLINES; n2++)
        {
            if (strcmp(str_ptrs[n1], str_ptrs[n2]) > 0)
            {
                str_swap(&(str_ptrs[n1]), &(str_ptrs[n2]));
            }
        } //assert null ptr
    }
}
void str_rev_sort(char * *str_ptrs, size_t NLINES)
{
    for (size_t n1 = 0; n1 < NLINES - 1; n1++)
    {
        for (size_t n2 = n1 + 1; n2 < NLINES; n2++)
        {
            if (strcmp(str_reverse(str_ptrs[n1]), str_reverse(str_ptrs[n2])) > 0)
            {
                str_swap(&str_ptrs[n1], &str_ptrs[n2]);
            }
        }
    }
}
