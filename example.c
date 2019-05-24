#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "debugmalloc.h"

int main(void) {
    char *data;

    /* everything is fine here */
    data = (char*) malloc(128 * sizeof(char));
    strcpy(data, "Hello world");
    printf("\n\nOne block is allocated:\n");
    debugmalloc_dump();
    free(data);
    printf("\n\nNo blocks allocated:\n");
    debugmalloc_dump();
    
    /* buffer overflow */
    data = (char*) malloc(128 * sizeof(char));
    strcpy(data - 16, "Buffer overflow");
    printf("\n\nError message for buffer overflow:\n");
    free(data);

    /* memory leak... */
    malloc(100);
    /* ... error message at program end */
    return 0;
}
