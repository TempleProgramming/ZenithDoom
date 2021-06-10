#include <stdio.h>
#include <stdlib.h>

#include "tos/tos_from_c.h"

U8* FileRead(U8* fname, I64* len)
{
    U8* source = NULL;
    FILE* fp = fopen(fname, "r");
    if (fp != NULL) {
        /* Go to the end of the file. */
        if (fseek(fp, 0L, SEEK_END) == 0) {
            /* Get the size of the file. */
            long bufsize = ftell(fp);
            if (bufsize == -1)
            {
                return NULL;
            }

            /* Allocate our buffer to that size. */
            source = malloc(sizeof(char) * (bufsize + 1));

            /* Go back to the start of the file. */
            if (fseek(fp, 0L, SEEK_SET) != 0)
            {
                return NULL;
            }

            /* Read the entire file into memory. */
            size_t newLen = fread(source, sizeof(char), bufsize, fp);
            if (ferror(fp) != 0) {
                fputs("Error reading file", stderr);
            }
            else {
                source[newLen++] = '\0'; /* Just to be safe. */
            }
        }
        fclose(fp);
    }
}