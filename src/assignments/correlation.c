#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/h/correlationUtil.h"
#include "../utils/h/malloc2.h"
#include "../utils/h/openFile.h"
#include "../utils/h/readData.h"

int main(int argc, char **argv) {
    FILE *fp = openFile(argc, argv);
    Data *dp = readData(fp);
    unsigned num = dp->num;

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

    double sx = standardDeviation(devX, num);
    double sy = standardDeviation(devY, num);
    double dis = coDispersion(devX, devY, num);

    double r = correlation(sx, sy, dis);
    printf("平均\t%.3lf, %.3lf\n", aveX, aveY);
    printf("標準偏差\t%.3lf, %.3lf\n", sx, sy);
    printf("共分散\t%.3lf\n", dis);
    printf("相関係数\t%.3lf\n", r);

    free(dp);
    free(dx);
    free(dy);
    free(devX);
    free(devY);

    return 0;
}
