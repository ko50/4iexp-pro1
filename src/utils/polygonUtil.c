#include "h/polygonUtil.h"

#include <math.h>

double sumOfPow(double* a, int index, unsigned num) {
    double sum = 0;
    for (int i = 0; i < num; i++) sum += pow(a[i], index);

    return sum;
}

double sumOfPowAnd(double* dx, double* dy, int index, unsigned num) {
    double sum = 0;
    for (int i = 0; i < num; i++) sum += pow(dx[i], index) * dy[i];

    return sum;
}

double A(double* dx, unsigned num) {
    double x0 = num;
    double x1 = sumOfPow(dx, 1, num);
    double x2 = sumOfPow(dx, 2, num);
    double x3 = sumOfPow(dx, 3, num);
    double x4 = sumOfPow(dx, 4, num);

    return (2 * x1 * x2 * x3) + (x0 * x2 * x4) - (x1 * x1 * x4) -
           (x0 * x3 * x3) - (x2 * x2 * x2);
}

double a0(double* dx, double* dy, unsigned num) {
    double x0 = num;
    double x1 = sumOfPow(dx, 1, num);
    double x2 = sumOfPow(dx, 2, num);
    double x3 = sumOfPow(dx, 3, num);
    double x4 = sumOfPow(dx, 4, num);

    double xy0 = sumOfPowAnd(dx, dy, 0, num);
    double xy1 = sumOfPowAnd(dx, dy, 1, num);
    double xy2 = sumOfPowAnd(dx, dy, 2, num);

    double a = A(dx, num);
    double tmp = (x2 * x2 * xy2) - (x1 * x3 * xy2) + (x1 * x4 * xy1) -
                 (x2 * x3 * xy1) + (x3 * x3 * xy0) - (x2 * x4 * xy0);

    return -tmp / a;
}

double a1(double* dx, double* dy, unsigned num) {
    double x0 = num;
    double x1 = sumOfPow(dx, 1, num);
    double x2 = sumOfPow(dx, 2, num);
    double x3 = sumOfPow(dx, 3, num);
    double x4 = sumOfPow(dx, 4, num);

    double xy0 = sumOfPowAnd(dx, dy, 0, num);
    double xy1 = sumOfPowAnd(dx, dy, 1, num);
    double xy2 = sumOfPowAnd(dx, dy, 2, num);

    double a = A(dx, num);
    double tmp = (x1 * x2 * xy2) - (x0 * x3 * xy2) + (x0 * x4 * xy1) -
                 (x2 * x2 * xy1) + (x2 * x3 * xy0) - (x1 * x4 * xy0);

    return tmp / a;
}

double a2(double* dx, double* dy, unsigned num) {
    double x0 = num;
    double x1 = sumOfPow(dx, 1, num);
    double x2 = sumOfPow(dx, 2, num);
    double x3 = sumOfPow(dx, 3, num);
    double x4 = sumOfPow(dx, 4, num);

    double xy0 = sumOfPowAnd(dx, dy, 0, num);
    double xy1 = sumOfPowAnd(dx, dy, 1, num);
    double xy2 = sumOfPowAnd(dx, dy, 2, num);

    double a = A(dx, num);
    double tmp = (x0 * x2 * xy2) - (x1 * x1 * xy2) + (x1 * x2 * xy1) -
                 (x0 * x3 * xy1) + (x1 * x3 * xy0) - (x2 * x2 * xy0);

    return tmp / a;
}

double factor2(double* dx, double* dy, double* devY, double a, double b,
               double c, unsigned num) {
    double y, sum1 = 0, sum2 = 0;
    for (int i = 0; i < num; i++) {
        y = (a * pow(dx[i], 2)) + (b * dx[i]) + c;

        sum1 += pow(dy[i] - y, 2);
        sum2 += pow(devY[i], 2);
    }

    return 1 - (sum1 / sum2);
}
