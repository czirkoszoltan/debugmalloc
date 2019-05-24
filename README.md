# Debugmalloc

Simple heap allocation checker for C.

- Lists allocated memory blocks.
- Tracks allocations, remembers allocating functions and code lines for each block.
- Provides some protection against buffer overruns.

To use the library, add `debugmalloc.c` and `debugmalloc.h` to your project,
and *include `debugmalloc.h` in all your source files*.

Example:

```c
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
```
