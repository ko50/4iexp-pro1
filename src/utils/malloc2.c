#include "h/malloc2.h"

#include <stdio.h>
#include <stdlib.h>

// Please free() returned value, end of program
void *malloc2(size_t size) {
    int *mem = malloc(size);
    if (mem == NULL) {
        fprintf(stderr, "Could not allocate memmory\n");
        exit(EXIT_FAILURE);
    }

    return mem;
}
