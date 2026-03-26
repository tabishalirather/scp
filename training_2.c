#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void init_matrix(int size, double* matrix, double* vector, double* sum_vector);
void print_array(int size, double* array);
void print_matrix(int rows, int cols, double* matrix);
void compute_sum(int size, double* matrix, double* vector);
void min_index(int size, double* sum_vector);

int main() {
    printf("printing in training-2\n");
    int size = 3;
    double* mat_A = malloc(size*size*sizeof(double));
    double* vec_x = malloc(size*sizeof(double));
    *(vec_x+0)=0.2;
    *(vec_x+1)=0.3;
    *(vec_x+2)=0.4;
    double* sum_vector = malloc(size*sizeof(double));
    init_matrix(size, mat_A, vec_x, sum_vector);



    free(mat_A);
    free(vec_x);
    free(sum_vector);
}
void min_index(int size, double* sum_vector) {
    printf("print from min_index\n");
    double min_value = *(sum_vector+0);
    int min_index = 0;

    for (int i=0; i<size; i++) {
        if (*(sum_vector+i)<min_value) {
            min_value=*(sum_vector+i);
            min_index=i;
        }
    }
    // print_array(size,sum_vector);
    printf("Index k of min_value %f is: %d", min_value, min_index);
}

void init_matrix(int size, double* matrix, double* vector, double* sum_vector) {
    printf("printing in init_matrix\n");
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("a_(%d,%d) ",i,j);
            // printf("%f ", *(vector+i));
                *(matrix + i*size +j) = *(vector+j)/(i+1);
        }
        printf("\n");
    }
    print_matrix(size,size,matrix);
    compute_sum(size, matrix, sum_vector);
}


void compute_sum(int size, double* matrix, double* sum_vector) {
    printf("printing in compute_sum\n");
    // double sum_value=0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
        *(sum_vector+i) += fabs(*(matrix +i*size +j));
    }
    }
    print_array(size,sum_vector);
    min_index(size,sum_vector);


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