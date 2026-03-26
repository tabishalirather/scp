#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int rows, int cols, double* matrix);
void print_array(int size, double* array);
void allocate_matrix(int rows, int cols, double* matrix_A, double* vector_x);
void computer_vector_b(int rows, int cols, double* matrix_A, double* vector_b);
void compute_euclidean_norm(int rows, double* vector_b, double* euclidean_norm_value);
void is_diagonally_dominant(int rows, int cols, double* matrix, double* diagonal_vector, double* non_diagonal_vector);
int give_random_int(int max, int min);
void random_matrix(int max, int min, int rows, int cols, double* matrix);
void compare_vectors(int rows, double* vector_first, double* vector_second);

int main() {
    printf("Print from main traiing-3.c\n");
    int rows = 4;
    int cols = 4;
    double* vector_x = malloc(rows*sizeof(double));
    *(vector_x+0)=3;
    *(vector_x+1)=5;
    *(vector_x+2)=2;
    *(vector_x+3)=3;
    print_array(rows, vector_x);

    double* matrix_A = malloc(rows*cols*sizeof(double));
    allocate_matrix(rows, cols, matrix_A, vector_x);

    double* vector_b = malloc(rows*sizeof(double));
    computer_vector_b(rows, cols, matrix_A, vector_b);

    double* euclidean_norm_value= malloc(1*sizeof(double));
    compute_euclidean_norm(rows, vector_b, euclidean_norm_value);

    double* matrix_rand = malloc(rows*cols*sizeof(double));
    random_matrix(60,1, rows, cols, matrix_rand);

    double* diagonal_vector = malloc(rows*sizeof(double));

    double* non_diagonal_vector = malloc(rows*sizeof(double));
    is_diagonally_dominant(rows, cols, matrix_rand, diagonal_vector, non_diagonal_vector);

    free(matrix_A);
    free(vector_x);
    free(vector_b);
    free(euclidean_norm_value);
    free(matrix_rand);
    free(diagonal_vector);
    free(non_diagonal_vector);


    return -1;
}


void compare_vectors(int rows, double* vector_first, double* vector_second) {
    printf("printing from compare_vectors\n");
    int flag = 0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<rows; j++) {
            // printf("from first: %f \n", *(vector_first+i));
            //
            // printf("from second: %f \n", *(vector_second+j));
            if (*(vector_first+i) < *(vector_second+j)) {
                flag++;
                // printf("first>second: (%f > %f)\n", *(vector_first+i), *(vector_second+j));
                // printf("matrix not diagonally dominant");
                printf("first>second: (%f < %f)\n", *(vector_first+i), *(vector_second+j));
                // break;
            }else {
                // printf("matrix is diagonally dominant");
                printf("first>second: (%f > %f)\n", *(vector_first+i), *(vector_second+j));
            }
        }
        printf("\n");
    }
    if (flag!=0) {
        printf("Flag is: %d\n", flag);
        printf("matrix not diagonally dominant");
    } else {
        printf("Flag is: %d\n", flag);
        printf("matrix is diagonally dominant");
    }

}


void is_diagonally_dominant(int rows, int cols, double* matrix, double* diagonal_vector, double* non_diagonal_vector) {
    printf("\nprinting from is_diagonally dominant\n");
    print_matrix(rows, cols, matrix);
    // double non_diagonal_sum=0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (i!=j) {
                printf("a_(%d,%d)", i, j);
                *(non_diagonal_vector+i) += *(matrix +i*cols +j);
            }else if (i==j) {
                *(diagonal_vector+i)= (*(matrix +i*cols +j));
            }
        }
        printf("\n");
    }
    printf("Diagonal vector is: \n");
    print_array(rows, diagonal_vector);

    printf("Non-diagonal vector is: \n");
    print_array(rows, non_diagonal_vector);
    compare_vectors(rows, diagonal_vector, non_diagonal_vector);
    // printf("non_diagonal_sum is: %f", non_diagonal_sum);
}




void compute_euclidean_norm(int rows, double* vector_b, double* euclidean_norm_value) {
    printf("printing from euclidean_norm\n");
    for (int i=0; i<rows; i++) {
        *(euclidean_norm_value) += pow((*(vector_b+i)),2);
    }
    *(euclidean_norm_value) = sqrt(*(euclidean_norm_value));
    printf("vector_b norm: %f\n", *euclidean_norm_value);
}



void computer_vector_b(int rows, int cols, double* matrix_A, double* vector_b) {
    printf("printing in compute_vector_b:\n");
    printf("Vector: \n");
    *(vector_b+0) = 0;
    for (int i=0; i<rows;i++) {
        for (int j=0; j<cols; j++) {
            *(vector_b+i) += pow(*(matrix_A +i*cols +j),2);
        }
    }
    print_array(rows, vector_b);
}



void allocate_matrix(int rows, int cols, double* matrix_A, double* vector_x) {
    printf("printing from allocate_matrix\n");
    printf("Matrix: \n");
    for (int i=0; i<rows;i++) {
        for (int j=0; j<cols; j++) {
            if (i==j) {
                *(matrix_A +i*cols +j) = 1;
        }else if (i!=j) {
            *(matrix_A +i*cols +j) = *(vector_x+j);
        }
        }
        // printf("\n");
    }
    print_matrix(rows, cols, matrix_A);
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

int give_random_int(int max, int min) {
    srand(time(NULL));
    int result = (rand() % (max- min)) + min;
    printf("random int is: %d\n", result);
    return result;
}

void random_matrix(int max, int min, int rows, int cols, double* matrix) {
    for (int i=0; i<rows; i++) {
        int rand_int = give_random_int(max, min+i)*(i/2+1);
        for (int j=0; j<cols; j++) {
            if (i!=j) {
            *(matrix + i*cols +j) = give_random_int(max+j, min+i)*(i+2*j+1)/rand_int;
            }else if (i==j){
                *(matrix + i*cols +j) = 26*give_random_int(max+j, min+i)*(i+2*j+1)/rand_int;
            }
        }
    }
    print_matrix(rows, cols, matrix);
}