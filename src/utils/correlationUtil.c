#include "h/correlationUtil.h"

#include <math.h>

double average(double *a, unsigned num) {
    double sum = 0;
    for (int i = 0; i < num; i++) sum += a[i];

    return sum / num;
}

void deviation(double *a, double *dev, double ave, int num) {
    for (int i = 0; i < num; i++) dev[i] = a[i] - ave;
}

double standardDeviation(double *dev, int num) {
    double sum = 0;
    for (int i = 0; i < num; i++) sum += pow(dev[i], 2);

    return sqrt(sum / num);
}

double coDispersion(double *devX, double *devY, int num) {
    double sum = 0;
    for (int i = 0; i < num; i++) sum += devX[i] * devY[i];

    return sum / num;
}

double correlation(double sx, double sy, double dis) {
    double s = (sx * sy);
    return dis / s;
}
