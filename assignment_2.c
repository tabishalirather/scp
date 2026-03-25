#include <stdio.h>
#include <math.h>

void max_from_columns(int rows, int cols, float* matrix);
void squared_sum_pointers(int rows, int cols, float (*matrix)[cols]);

int main() {
    printf("main is working\n");

    enum DIMS {ROWS=3, COLS=4};
    float matrix[ROWS][COLS]={
        {21,2,1,3},
        {2,-8,20,5},
        {12,3,2,4},
        // {5,2,110}
    };
    max_from_columns(ROWS,COLS, &matrix[0][0]);


    squared_sum_pointers(ROWS, COLS, matrix);
}

void max_from_columns(int rows, int cols, float* matrix) {
    printf("printing  max from each column! \n\n");
    float max_vector[rows];
    // printf("first value of matrix argument is: %f\n", *matrix);
    max_vector[0] = (*matrix);
    // printf("max_vector starting value is: %f\n", max_vector[0]);

        for (int row=0; row<rows; row++){
            for (int col=0; col<cols; col++){
            printf("%0.2f ", *(matrix + (row*cols) + col));
            if (*(matrix + (row*cols) + col) > max_vector[row]) {
                max_vector[row]= *(matrix + (row*cols) + col);
            }
            // printf("max_vector[%d]: %f\n", col, max_vector[col]);
        }
         printf("\n");
         // printf("max element in this col is: %f: \n", max_vector[col]);
    }
    printf("\n");
    printf("Vector of maxs is: \n");
    for (int i=0; i<rows; i++) {
        printf("%0.2f \n", *(max_vector+i));
    }


}

void squared_sum_pointers(int rows, int cols, float (*matrix)[cols]) {
    printf("\nfrom fxn squared_sum_pointers: \n");
    float squared_sum_vector[cols];
    squared_sum_vector[0]=0;
    for (int j=0; j<rows; j++){
        for (int i=0; i<cols; i++)    {
            // printf("%0.2f ", *(matrix +(j*cols)+i));
            printf("%0.2f ", *(*(matrix+j)+i));
            squared_sum_vector[j] += pow(*(*(matrix+j)+i), 2);
        }
        printf("\n");
        // printf("K=%d: %0.4f \n",j, *(squared_sum_vector+j));


    }

    printf("\n");
    float max_value = *(squared_sum_vector);
    int max_index = 0;
    for (int i=0; i<rows; i++) {
        printf("K=%d: %0.4f \n",i, *(squared_sum_vector+i));
        if (*(squared_sum_vector+i)> max_value) {
            max_value = *(squared_sum_vector+i);
            max_index = i;
         }
    }
    printf("\nmax_value=%0.2f has index K=%d", max_value, max_index);
}