#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void make_vandermode(int size, double* matrix, double* vector, double* sum_rows_vec);
void print_matrix(int rows, int cols, double* matrix);
void compute_sum(int size, double* vector, double* matrix);
void print_array(int size, double* array);
void max_index(int size, double* array);



int main() {
    printf("Printing form pre-master 1\n");
    int rows=3;
    int  cols=3;
    int size = 4;

    double* vec_x = malloc(size * sizeof(double));
    *(vec_x+0) = 0.4;
    *(vec_x+1) = 0.7;
    *(vec_x+2) = 0.3;
    *(vec_x+3) = 0.2;


    double* vandermode = malloc(size*size*sizeof(double));
    double* sum_rows_vec = malloc(size*sizeof(double));

    make_vandermode(size,vandermode, vec_x, sum_rows_vec);



    free(vandermode);
    free(vec_x);
    free(sum_rows_vec);

}

void max_index(int size, double* array) {
    printf("printing from max_index fxn\n");
    double max_value = *(array+0);
    int max_index = 0;
    for (int i=0; i<size; i++) {
        if (*(array+i)>max_value) {
            max_value=*(array+i);
            max_index=i;
        }
    }
    printf("Index k  of maximum of sum_vector is %d with max_value %f", max_index, *(array+max_index));
}

void compute_sum(int size, double* sum_rows, double* matrix) {
    *(sum_rows+0)=0;
    printf("\nfrom compute_sum fxn\n");
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            *(sum_rows+j) += *(matrix + i*size +j);
        }
    }
    print_array(size, sum_rows);
    max_index(size, sum_rows);
}

void make_vandermode(int size, double* matrix, double* vector, double* sum_rows_vec) {
    printf("Printing from make_vandermode\n");
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            // printf("(%i,%i)\n", i,j);
            *(matrix + i*size+j) = pow(*(vector+j),i);
            // printf("%f ", *(vector+j));
        }
        // printf("\n");
    }
    // printf("%f\n",*(matrix + 1*size + 3));
    print_matrix(size, size, matrix);
    compute_sum(size, sum_rows_vec, matrix);
}


void print_matrix(int rows, int cols, double* matrix) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%f ", *(matrix + i*cols+j));
        }
        printf("\n");
    }
}

void print_array(int size, double* array) {
    for (int i=0; i<size; i++) {
        printf("vec[%d]:%f \n",i, *(array+i));
    }
    printf("\n");
}