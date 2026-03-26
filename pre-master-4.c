#include <stdlib.h>
#include <math.h>
#include <stdio.h>
void print_array(int size, double *array);
void print_matrix(int rows, int cols, double *matrix);
void dynamic_array_col(int rows, int cols, double *matrix, double *sum_col_value);
void dynamic_array_row(int rows, int cols, double *matrix, double *sum_col_value);
void sum_col(int rows, int cols, double* matrix, double* sum_col_value);
void sum_rows(int rows, int cols, double* matrix, double* sum_row_value);
void largest_index(int size, double* array);
int main() {
    printf("Printing from main function with return type int");
    //Dynamic memory allocation: Main idea is to assign memory while the program is running, instead of pre-assigning it.
    //Static memory is like booking 10 seats before knowing how many guests are coming.
    // Dynamic memory is like waiting until guests arrive, then arranging exactly as many seats as needed.
    // 1. int arr[5];
    // Type: fixed-size array
    // Size known: at compile time
    // Memory location: usually stack / automatic storage
    // Lifetime: exists only until the block/function ends
    // Freeing: automatic, you do not free it yourself
    //
    // Example:
    // void f() {
    //     int arr[5];
    // } // arr is destroyed here automatically
    // 2. int arr[n];
    // Type: variable length array (VLA), if compiler supports it
    // Size known: at runtime
    // Memory location: usually stack / automatic storage
    // Lifetime: exists only until the block/function ends
    // Freeing: automatic, you do not free it yourself
    //
    // Example:
    // void f(int n) {
    //     int arr[n];
    // } // arr is destroyed here automatically
    //
    // So even though the size is runtime-dependent, it still dies automatically.
    //
    // 3. int *arr = malloc(n * sizeof(int));
    // Type: pointer to dynamically allocated memory
    // Size known: at runtime
    // Memory location: heap
    // Lifetime: exists until you explicitly free it
    // Freeing: manual, you must call free(arr);
    //
    // Example:
    // void f(int n) {
    //     int *arr = malloc(n * sizeof(int));
    //     free(arr);
    // }
    //
    // If you do not free(arr), the memory stays allocated and you get a memory leak.
    //
    // Main difference about lifetime
    // int arr[5]; → dies automatically at end of scope
    // int arr[n]; → dies automatically at end of scope
    // malloc(...) memory → stays alive until free(...)
    // Main difference about freeing
    // fixed array: never use free
    // VLA: never use free
    // malloc memory: must use free
    // Very important rule
    //
    // Only memory obtained from functions like:
    //
    // malloc
    // calloc
    // realloc
    //
    // should be freed with free.
    //
    // Doing this is wrong:
    //
    // int arr[5];
    // free(arr);   // wrong
    //
    // because arr was not allocated with malloc.
    //
    // One-line summary
    // arr[5] and arr[n] are automatic arrays: temporary, self-cleaning
    // malloc gives heap memory: persistent until you clean it manually

    int size_mem = 5;
    double *p = malloc(size_mem * sizeof(int)); //Does not initialize, just reserves the memory.

    printf("\np:%p is the pointer to the first byte of memory length:%d", p, size_mem);
    printf("\nWe use * to access the value at pointer(location) p: %f", *p);
    print_array(size_mem, p);
    free(p);


    double *q = calloc(size_mem, sizeof(int)); //Does not initialize, just reserves the memory.
    *(q)=2;
    *(q+1)=33;
    printf("\nq:%p is the pointer to the first byte of memory length:%d", q, size_mem);
    printf("\nWe use * to access the value at pointer (location) q: %f", *(q+1));
    print_array(size_mem, q);
    free(q);

    //Dynamic matrices using * notation
    int rows = 5;
    int cols = 4;
    double* A = malloc(rows*cols*sizeof(double));
    double* sum_col_value = malloc(cols*sizeof(double));
    double* sum_row_value = malloc(rows*sizeof(double));

    dynamic_array_col(rows, cols, A, sum_col_value);
    dynamic_array_row(rows, cols, A, sum_row_value);


    free(sum_col_value);
    free(sum_row_value);
    free(A);





}




void print_array(int size, double* array) {
    for (int i=0; i<size; i++) {
        printf("%d: %f\n", i, *(array+i));
    }
}

void print_matrix(int rows, int cols, double* matrix) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%f ", *(matrix + i*cols+j));
        }
        printf("\n");
    }
}

void dynamic_array_col(int rows, int cols, double* matrix, double* sum_col_vector) {
    printf("Matrix printed in dynamic_array:\n");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            // printf("%f ", *(matrix + i*cols)+j);
            *(matrix + i*cols + j)= i+j;
        }
        // printf("\n");
    }
    print_matrix(rows, cols, matrix);
    // sum_col(rows, cols, matrix, sum_vector);
    sum_rows(rows, cols, matrix, sum_col_vector);

}

void dynamic_array_row(int rows, int cols, double* matrix, double* sum_row_vector) {
    printf("Matrix printed in dynamic_array:\n");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            // printf("%f ", *(matrix + i*cols)+j);
            *(matrix + i*cols + j)= i+j;
        }
        // printf("\n");
    }
    // *(matrix + 0*cols +0)=777;
    print_matrix(rows, cols, matrix);
    // sum_col(rows, cols, matrix, sum_vector);
    sum_rows(rows, cols, matrix, sum_row_vector);
}

void sum_col(int rows, int cols, double* matrix,  double* sum_col_value){
    printf("call from fxn sum_col\n");
    // double * sum_col_value;
    // sum_col_value = malloc(cols*sizeof(double));
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
        printf("a_(%i, %i) ", i, j);
        *(sum_col_value+j) += *(matrix + i*cols +j);
        //this will first fill up the sum_col_value[0] = matrix[0][0]+matrix[0][1]+matrix[0][2]+matrix[0][3]: Sum of first column!
        //then we get sum_col_value[1] = matrix[0][0]+matrix[1][1]+matrix[1][2]+matrix[1][3]: Sum of second column and so on;
        // printf("%f\n", (*(matrix + i*cols +j)));
    }
        printf("\n");
    }
    printf("Sum of columns is: \n");
    print_array(cols, sum_col_value);
}

void sum_rows(int rows, int cols, double* matrix, double* sum_row_value) {
    printf("printing in sum rows:\n");
    //Swap the loop order i.e. start with cols in the outside loop and then inside have  row loop if you want to sum the rows.
    //If you want to sum the columns, then put rows outside and columns inside
    for (int j=0; j<cols; j++) {
         for (int i=0; i<rows; i++) {
            printf("a_(%i, %i) ", j, i);
            *(sum_row_value+i) += *(matrix + i*cols +j);
            //this will first fill up the sum_col_value[0] = matrix[0][0]+matrix[0][1]+matrix[0][2]+matrix[0][3]: Sum of first column!
            //then we get sum_col_value[1] = matrix[0][0]+matrix[1][1]+matrix[1][2]+matrix[1][3]: Sum of second column and so on;
            // printf("%f\n", (*(matrix + i*cols +j)));
        }
        printf("\n");
    }
    printf("Sum of rows is: \n");
    print_array(rows, sum_row_value);
    largest_index(rows, sum_row_value);

}

void largest_index(int size, double* array) {
    printf("printing in largest_index\n");
    int max_index = 0;
    double *largest_values = malloc(sizeof(double));
    *largest_values = *(array+0);
    for (int i=0; i<size; i++) {
        if (*(array+i) > *(largest_values+0)) {
            *(largest_values) = *(array+i);
            max_index = i;
        }
        // printf("Row with largest value of %f has index %d:\n", *(array+i), i);
    }
    printf("(max_index, max_value)=(%i,%f)", max_index, *largest_values);

}