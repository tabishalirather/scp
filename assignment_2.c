#include <stdio.h>
#include <math.h>

void max_from_columns(int rows, int cols, float* matrix);

int main() {
    printf("main is working\n");

    enum DIMS {ROWS=3, COLS=3};
    float matrix[ROWS][COLS]={{30,200,1000}, {2,-8,20}, {122,3,22}};
    max_from_columns(ROWS,COLS, &matrix[0][0]);
}

void max_from_columns(int rows, int cols, float* matrix) {
    printf("printing  max from each column! \n\n");
    float max_vector[cols];
    // printf("first value of matrix argument is: %f\n", *matrix);
    max_vector[0] = (*matrix);
    // printf("max_vector starting value is: %f\n", max_vector[0]);
     for (int col=0; col<cols; col++){
        for (int row=0; row<rows; row++)    {
            printf("%0.2f ", *(matrix + (col*cols) + row));
            if (*(matrix + (col*cols) + row) > max_vector[col]) {
                max_vector[col]= *(matrix + (col*cols) + row);

            }
            // printf("max_vector[%d]: %f\n", col, max_vector[col]);
        }
         printf("\n");
         // printf("max element in this col is: %f: \n", max_vector[col]);
    }
    printf("\n");
    printf("Vector of maxs is: \n");
    for (int i=0; i<cols; i++) {
        printf("%0.2f ", *(max_vector+i));
    }


}