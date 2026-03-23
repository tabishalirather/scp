#include <stdio.h>
#include <math.h>

void sum_rows(int rows, int cols, double matrix[rows][cols]);
double frob_norm(int rows, int cols, double matrix[rows][cols]);

int main(void) {
    printf("Connected\n");

    // without using enum, it is not allowed to fill the matrix using {} notation, the other fix is to directly specify
    // the dimensions of the matrix like matrix[3][4]; I think this is not elegant.
    enum {ROWS=3, COLS=4};
    double matrix[ROWS][COLS]={
        {1,2,3,-1},
        {3,2,1,-1},
        {4,1,4,-10}
    };
    sum_rows(ROWS, COLS, matrix);


    printf("Q2: Frob Norm\n");
    enum {R = 4, C=4};
    double matrix_frob[R][C] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    double fob_norm_value = frob_norm(R, C, matrix_frob);

    printf("fob_norm is: %f", fob_norm_value);
    return -1;
}


void sum_rows(int rows, int cols, double matrix[rows][cols]){
    printf("print in sum_cols fx\n");
    double summed_rows[rows] = {};
    for (int i=0; i<cols; i++) {
        for (int j=0; j<rows; j++) {
            summed_rows[i] = summed_rows[i]+matrix[j][i];
        }
        printf("Summed rows %d is %f: \n", i, summed_rows[i]);
    }
}

double frob_norm(int rows, int cols, double matrix[rows][cols]) {
    printf("printing in fxn frob norm\n");
    double frob_norm = 0;
    // ideally we should reuse the fxn sum_rows but for the sake of practice, let's rewrite it.
    double summed_rows[rows] = {};
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            summed_rows[i] += pow(matrix[i][j],2);
        }
        printf("summed col %d are: %f \n", i+1, summed_rows[i]);
    }

    double summed_cols=0;
    for (int i=0;i<cols;i++) {
        summed_cols+=summed_rows[i];
    }
    double fob_norm = sqrt(summed_cols);
    return fob_norm;

}
