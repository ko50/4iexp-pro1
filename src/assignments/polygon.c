#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/h/correlationUtil.h"
#include "../utils/h/leastSquareUtil.h"
#include "../utils/h/malloc2.h"
#include "../utils/h/openFile.h"
#include "../utils/h/polygonUtil.h"
#include "../utils/h/readData.h"

int main(int argc, char **argv) {
    FILE *fp = openFile(argc, argv);
    Data *dp = readData(fp);
    int num = dp->num;

    double *dx = (double *)malloc2(sizeof(double) * num);
    double *dy = (double *)malloc2(sizeof(double) * num);
    for (int i = 0; i < num; i++) {
        dx[i] = dp->data[i].x;
        dy[i] = dp->data[i].y;
    }

    double aveY = average(dy, num);
    double *devY = (double *)malloc2(sizeof(double) * num);
    deviation(dy, devY, aveY, num);

    double a[] = {a0(dx, dy, num), a1(dx, dy, num), a2(dx, dy, num)};
    double R2 = factor2(dx, dy, devY, a[2], a[1], a[0], num);
    printf("傾き2\t%lf\n", a[2]);
    printf("傾き1\t%lf\n", a[1]);
    printf("切片\t%lf\n", a[0]);
    printf("回帰曲線\ty = %.3lfx^2 + %.3lfx + %.3lf\n", a[2], a[1], a[0]);
    printf("決定係数\t%.3lf\n", R2);

    free(dp);
    free(dx);
    free(dy);
}
