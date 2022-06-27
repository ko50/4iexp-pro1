#include "h/leastSquareUtil.h"

#include <math.h>

double coefficient(double coDis, double disX) { return coDis / disX; }

double segment(double aveX, double aveY, double a) { return aveY - (a * aveX); }

double factor(double *dx, double *dy, double *devY, double a, double b,
              unsigned num) {
    double y, sum1 = 0, sum2 = 0;
    for (int i = 0; i < num; i++) {
        y = (a * dx[i]) + b;

        sum1 += pow(dy[i] - y, 2);
        sum2 += pow(devY[i], 2);
    }

    return 1 - (sum1 / sum2);
}
