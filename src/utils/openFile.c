#include "h/openFile.h"

#include <stdio.h>
#include <stdlib.h>

FILE* openFile(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Please provide data filename.\n");
        exit(EXIT_FAILURE);
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open data file\n");
        exit(EXIT_FAILURE);
    }

    return fp;
}
