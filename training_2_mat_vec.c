#include <stdio.h>
void print_matrix(int rows, int cols, double* matrix);
void print_array(int size, double* array);
void mat_vec(int rows, int cols, double* matrix, double* vector_x, double* vector_y);
int main(){
    printf("printing from training_2_mat_vec.c -- main\n");
    enum {ROWS=3, COLS=3};
    double matrix_A[ROWS][COLS] =
        {
        {4,2,1},
        {6,3,2},
        {1,2,7}
    };
    double vector_x[COLS] = {7,3,2};
    double vector_y[COLS];

    mat_vec(ROWS,COLS, &matrix_A[0][0], vector_x, vector_y);


    return -1;

}

void mat_vec(int rows, int cols, double* matrix, double* vector_x, double* vector_y) {
    printf("printing from mat_vec\n");
    print_matrix(rows, cols, matrix);
    print_array(cols, vector_x);
    for (int i=3; i<rows; i++) {
        for (int j=3; j<cols; j++) {
            // *(vector_y+i) = i;
            printf("y_[%d]= :(%f*%f)\n",i, *(matrix +i*rows +j) , (*(vector_x+j)));
            *(vector_y+i) += ((*(matrix +i*rows +j) * (*(vector_x+i))));
        }
        printf("\n");
    }
    print_array(cols, vector_y);

}

void print_matrix(int rows, int cols, double* matrix) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%0.2f ", *(matrix + i*cols+j));
        }
        printf("\n");
    }
}

void print_array(int size, double* array) {
    for (int i=0; i<size; i++) {
        printf("vec[%d]:%0.2f \n",i, *(array+i));
    }
    printf("\n");
}