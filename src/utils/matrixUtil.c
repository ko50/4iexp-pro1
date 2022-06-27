#include "h/matrixUtil.h"

#include <stdio.h>
#include <stdlib.h>

#include "h/malloc2.h"
#include "h/polygonUtil.h"

Matrix *allocateMatrix(int column, int row) {
    int rowSize = sizeof(double) * row, matrixSize = rowSize * column;
    double **rows = (double **)malloc2(matrixSize);

    double *r;
    for (int i = 0; i < column; i++) {
        r = (double *)malloc2(rowSize);
        for (int j = 0; j < row; j++) r[j] = 0;

        rows[i] = r;
    }

    Matrix _m = {column, row, rows};
    Matrix *m = (Matrix *)malloc2((sizeof(int) * 2) + matrixSize);

    *m = _m;
    free(rows);

    return m;
}

void printMatrix(Matrix *m) {
    for (int i = 0; i < m->column; i++) {
        for (int j = 0; j < m->row; j++) printf("%40.3lf ", m->rows[i][j]);
        printf("\n");
    }
}

void makeCoefficientMatrix(double *dx, double *dy, int floor, Matrix *m,
                           unsigned num) {
    double lhs;  // Left Hand Side → LHS
    int i, j;

    for (i = 0; i < m->column; i++) {
        lhs = sumOfPowAnd(dx, dy, i, num);
        m->rows[i][0] = lhs;

        for (j = 1; j < m->row; j++) m->rows[i][j] = sumOfPow(dx, j + i, num);
    }
}

void solveCoefficientMatrix(Matrix *m, double *ans) {
    int i, j, k, l;
    int col = m->column, row = m->row;
    double tmp;

    for (i = 0; i < col; i++) {
        double *row1 = m->rows[i];
        tmp = row1[i];

        for (j = i; j < row; j++) m->rows[i][j] = row1[j] / tmp;

        for (k = i + 1; k < col; k++) {
            double *row2 = m->rows[k];
            for (l = i; l < row; l++) m->rows[k][l] -= row1[l] * row2[l];
        }
    }

    for (i = col - 1; i > 0; i--) {
        double *row1 = m->rows[i];
        for (j = i - 1; j >= 0; j--) {
            double *row2 = m->rows[j];
            for (k = row - 1; k >= i; k--) m->rows[j][k] -= row1[k] * row2[i];
        }
    }

    for (int i = 0; i < col; i++) ans[i] = m->rows[i][row - 1];
}
