typedef struct {
    int column;
    int row;
    double **rows;
} Matrix;

Matrix *allocateMatrix(int column, int row);
void printMatrix(Matrix *m);
void makeCoefficientMatrix(double *dx, double *dy, int floor, Matrix *m, unsigned num);
void solveCoefficientMatrix(Matrix *m, double *ans);
