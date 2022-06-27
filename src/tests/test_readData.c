#include <stdio.h>
#include <stdlib.h>

#include "../utils/h/readData.h"

int main(int ac, char *av[]) {
    FILE *fp;
    Data *dp;
    int i;

    if ((fp = fopen(av[1], "r")) == NULL) {
        fputs("readData: error 1\n", stderr);
        exit(EXIT_FAILURE);
    }

    dp = readData(fp);

    printf("%d\n", dp->num);
    for (i = 0; i < dp->num; i++)
        printf("%lf %lf\n", dp->data[i].x, dp->data[i].y);

    free(dp);
}
