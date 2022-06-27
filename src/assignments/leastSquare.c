#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/h/correlationUtil.h"
#include "../utils/h/leastSquareUtil.h"
#include "../utils/h/malloc2.h"
#include "../utils/h/openFile.h"
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

    double aveX = average(dx, num);
    double aveY = average(dy, num);

    double *devX = (double *)malloc2(sizeof(double) * num);
    double *devY = (double *)malloc2(sizeof(double) * num);
    deviation(dx, devX, aveX, num);
    deviation(dy, devY, aveY, num);

    double coDis = coDispersion(devX, devY, num);
    double disX = coDispersion(devX, devX, num);

    double a = coefficient(coDis, disX);
    double b = segment(aveX, aveY, a);
    double R2 = factor(dx, dy, devY, a, b, num);
    printf("傾き\t%.3lf\n", a);
    printf("切片\t%.3lf\n", b);
    printf("回帰曲線\ty = %.3lfx + %.3lf\n", a, b);
    printf("決定係数\t%.3lf\n", R2);

    free(dp);
    free(dx);
    free(dy);
    free(devX);
    free(devY);

    return 0;
}
