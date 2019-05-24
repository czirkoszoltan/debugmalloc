#ifndef DEBUGMALLOC_NOMACRO_H
#define DEBUGMALLOC_NOMACRO_H

#include <stdbool.h>
#include <stddef.h>

/* Use these macro-like functions to allocate and deallocate memory.
 * Semantics: the same as the standard functions. */
#define debugmalloc_malloc(X) debugmalloc_malloc_full((X), "malloc", #X, __FILE__, __LINE__, false)
#define debugmalloc_calloc(X,Y) debugmalloc_malloc_full((X)*(Y), "calloc", #X ", " #Y, __FILE__, __LINE__, true)
#define debugmalloc_realloc(P,X) debugmalloc_realloc_full((P), (X), "realloc", #X, __FILE__, __LINE__)
#define debugmalloc_free(P) debugmalloc_free_full((P), "free", __FILE__, __LINE__)

/* Use this function to set the name of the log file.
 * If empty, all log messages are written to stderr. */
void debugmalloc_log_file(char const *logfilename);

/* Dump data of all memory blocks allocated. */
void debugmalloc_dump(void);

/* count number of blocks allocated */
int debugmalloc_allocated_count(void);


/* Internal functions, you don't have to deal with these directly. */
void *debugmalloc_malloc_full(size_t size, char const *func, char const *expr, char const *file, unsigned line, bool zero);
void *debugmalloc_realloc_full(void *oldmem, size_t newsize, char const *func, char const *expr, char const *file, unsigned line);
void debugmalloc_free_full(void *mem, char const *func, char const *file, unsigned line);


#endif  /* DEBUGMALLOC_NOMACRO_H */
