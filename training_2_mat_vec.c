#include <stdio.h>
void print_matrix(int rows, int cols, double* matrix);
void print_array(int size, double* array);
void mat_vec(int rows, int cols, double* matrix, double* vector_x, double* vector_y);
void compute_vec_b(int rows, int cols, double* sum_rows, double* matrix);
void residual_vector(int rows, int cols, double* vector_b, double* vector_y);

int main(){
    printf("printing from training_2_mat_vec.c -- main\n");
    enum {ROWS=3, COLS=4};
    double matrix_A[ROWS][COLS] =
        {
        {4,2,1,4},
        {6,3,2,3},
        {1,2,7,8}
    };
    double vector_x[COLS] = {7,3,2,7};
    double vector_y[ROWS];
    double vector_b[ROWS];

    mat_vec(ROWS,COLS, &matrix_A[0][0], vector_x, vector_y);
    compute_vec_b(ROWS, COLS,vector_b, &matrix_A[0][0]);


    return -1;

}
void compute_vec_b(int rows, int cols, double* sum_rows, double* matrix) {
    *(sum_rows+0)=0;
    printf("\nfrom compute_sum fxn\n");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            *(sum_rows+j) += *(matrix + i*cols +j);
        }
    }
    print_array(cols, sum_rows);
    // max_index(size, sum_rows);
}

void residual_vector(int rows, int cols, double* vector_b, double* vector_y) {
    printf("printing frm residual_vector");
}


void mat_vec(int rows, int cols, double* matrix, double* vector_x, double* vector_y) {
    printf("printing from mat_vec\n");
    print_matrix(rows, cols, matrix);
    print_array(cols, vector_x);
    // print_array(cols, vector_y);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            // printf("this sia  test print\n");
            // printf("%d", i);
            // *(vector_y+i) = i;
            // printf("this sia  test print");
            // printf("y_[%d]= :(%f*%f)\n",i, *(matrix +i*rows +j) , (*(vector_x+j)));
            *(vector_y+i) += ((*(matrix +i*cols +j) * (*(vector_x+j))));
            // printf("%f \n", *(vector_y));
        }
        // printf("\n");
    }

    printf("printing_vector_\ny");
    print_array(rows, vector_y);

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