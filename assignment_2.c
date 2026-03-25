#include <stdio.h>
#include <math.h>

void max_from_columns(int rows, int cols, float* matrix);
void squared_sum_pointers(int rows, int cols, float (*matrix)[cols]);
void print_and_max_index(int size, float (*array));
void print_array(int size, float (*array));

int main(){
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

// Q1
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
    print_array(rows, max_vector);
}

// Q2
void squared_sum_pointers(int rows, int cols, float (*matrix)[cols]) {
    printf("\nfrom fxn squared_sum_pointers: \n");
    float squared_sum_vector[cols];
    squared_sum_vector[0]=0;
    for (int j=0; j<rows; j++){
        for (int i=0; i<cols; i++)    {
            printf("%0.2f ", *(*(matrix+j)+i));
            squared_sum_vector[j] += pow(*(*(matrix+j)+i), 2);
        }
        printf("\n");
    }
    printf("\n");
    print_and_max_index(rows, squared_sum_vector);
}


// helpder_fxn
void print_and_max_index(int size, float (*array)) {
    float max_value = *(array);
    int max_index = 0;
    for (int i=0; i<size; i++) {
        printf("K=%d: %0.4f \n",i, *(array+i));
        if (*(array+i)> max_value) {
            max_value = *(array+i);
            max_index = i;
        }
    }
    printf("\nmax_value=%0.2f has index K=%d", max_value, max_index);
}

// helper_fxn
void print_array(int size, float (*array)) {
    for (int i=0; i<size; i++) {
        printf("%0.2f \n", *(array+i));
        // printf("K=%d: %0.4f \n",i, *(array+i));
    }

}