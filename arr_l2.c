#include <stdio.h>
#include <math.h>
// inf norm of a matrix


// Sum of rows
void print_sum_rows(int rows, int columns, double matrix[rows][columns]) {
    double summed_rows_matrix[rows];
    for (int i=0;i<rows;i++) {
        for (int j = 0; j<columns;j++) {
        summed_rows_matrix[i]+=matrix[i][j];
    }
        printf("summed_rows_matrix[%d]: %0.1f\n", i, summed_rows_matrix[i]);
    }

}


// Sum of 2d matrix

double sum_2d_matrix(int rows, int columns, double matrix[rows][columns]) {
    double sum = 0.0;
    for (int i=0; i<rows;i++) {
        for (int j=0; j<columns;j++) {
            sum+=matrix[i][j];
        }
    }
    return sum;
}



// When passing a multi dim array to a fxn, all but first dimensions must be specified.
void hilbert_matrix_fxn(int size, double matrix[size][size]) {
    printf("calling hilbert matrix works:\n");
    for (int index = 0; index < size; index++) {
        for (int j = 0; j < size; j++) {
                matrix[index][j] = 1.0/((1+j+index));
            printf(" %f ", matrix[index][j]);
        }
        printf("\n");
    }

    double sum = 0;
    sum = sum_2d_matrix(size, size, matrix);
    printf("Sum of the matrix elements is: %f\n", sum);

}

double inf_norm(double array_inf_norm[], int size) {
    double max = 0;
    printf("size is: %d\n", size);
    for (int index = 0; index < size; index++) {
        if (fabs(array_inf_norm[index]) > fabs(array_inf_norm[index + 1])) {
            printf("array_inf_norm_index_[%d] = %f\n", index, array_inf_norm[index]);
            printf("array_inf_norm_index_+1_[%d] = %f\n", index + 1, array_inf_norm[index + 1]);
            if (fabs(array_inf_norm[index]) > max) {
                max = fabs(array_inf_norm[index]);
            }
            // printf("max in inf norm fxn is: = %f\n", max);
        }
    }
    return max;
}

double inf_norm_matrix(int rows, int columns, double matrix[rows][columns]) {
    double summed_rows_matrix[rows]={};
    for (int i=0;i<rows;i++) {
        for (int j = 0; j<columns;j++) {
            summed_rows_matrix[i]+=fabs(matrix[i][j]);
        }
        printf("summed_rows_matrix[%d]: %f\n", i, summed_rows_matrix[i]);
    }
    double inf_norm_value = inf_norm(summed_rows_matrix,  rows);
    return inf_norm_value;

}


double sum_array(double array_to_sum[], int size) {
    // imporntant bit of remember here is that when passing arrays as arguments, they decay into points, so only the pointer(memory address is sent) not the length of the array. So the fxn only really gets accesst to the starting point of the element and consequently its size.


    printf("calling sum_array\n");
    double sum = 0;
    // size of gives you the memory size taken by the variable, not the lenght
    // int size = sizeof(array_to_sum)/sizeof(array_to_sum[0]);
    // print()
    printf("array size is in the fxn: %d\n", size);
    for (int index = 0; index < size; index++) {
        printf("array_to_sum[%d] = %f\n", index, array_to_sum[index]);
        sum += array_to_sum[index];
    }

    return sum;
}

double product_array(double array_A[], double array_B[], int size) {
    double sum_product = 0;
    // double sum = 0;
    printf("calling product_array\n");

    for (int index = 0; index < size; index++) {
        // printf("array_A[%d] = %f\n", index, array_A[index]);
        // printf("array_B[%d] = %f\n", index, array_B[index]);
        sum_product += array_A[index] * array_B[index];
        // printf("product[%d] = %f\n", index, product[index]);
    }
    // for (int index=0; index<size; index++) {
    //     sum += product[index];
    //
    // }
    // printf("sum of array_A and array_B is: %f\n", sum);
    return sum_product;
}


// Exercise 11:
int main(void) {
    printf("Locked and loaded\n");
    int arr[10];
    arr[0] = 5;
    arr[1] = 6;
    arr[2] = arr[0] + arr[1];
    printf("The value of arr[2] is: %d\n", arr[2]);

    int new_arr[5] = {1, 2, 3, 4};
    // This is how you can print an array
    for (int i = 0; i < 5; i++) {
        // printf("arr[%d] = %d\n", i, new_arr[i]);
    }
    double first_ten[10];
    for (int j = 0; j < 10; j++) {
        // printf("j is: %d:\n", j);
        double a_ith = (2 * pow(j, 2) + 1) / (j + 3);
        // printf("a_ith is: %.2f:\n", a_ith);
        first_ten[j] = (2 * pow(j, 2) + 1) / (j + 3);
        // printf("%d th element of first_ten array is: %.2f:\n",j+1, first_ten[j]);
    }
    // printf("Element of first_ten array is %0.2f:\n", first_ten[0]);
    // printf("3rd value is: %.2f: ", first_ten[2]);
    for (int k = 0; k < 10; k++) {
        double element_to_print = first_ten[k];
        printf("first_ten[%d] = %0.2f\n", k, element_to_print);
    }

    printf("Exercise 11\n");
    double array_to_sum[4] = {1, 9, 8, 6};
    int array_size = sizeof(array_to_sum) / sizeof(array_to_sum[0]);
    double sum = sum_array(array_to_sum, array_size);
    printf("The sum of the array is: %0.0f\n", sum);


    printf("Exercise 12\n");
    double array_A[] = {1, 2, 3, 4};
    double array_B[] = {5, 6, 7, 8};
    int size_for_product = sizeof(array_A) / sizeof(array_A[0]);

    double product = product_array(array_A, array_B, size_for_product);
    printf("product of array_A and array_B is: %f \n", product);


    printf("Exercise 13\n");
    double arr_inf_norm[] = {-1.5, 3.2, -4.8, 2.1};
    int size = sizeof(arr_inf_norm) / sizeof(arr_inf_norm[0]);
    double max_norm = inf_norm(arr_inf_norm, size);
    printf("max_norm = %f\n", max_norm);

    printf("Exercise 14: Hilbert matrix\n");
    int size_hilbert = 10;
    double matrix[size_hilbert][size_hilbert];
    hilbert_matrix_fxn(size_hilbert, matrix);



    printf("Exercise 17: \n");
// Simply declaring int rows and columsn doesn't work with this type of initialization as these are not compile type constant, so array is treated as variable length array (VLA)
    enum { ROWS = 3, COLS = 5 };

    double matrix_to_sum[ROWS][COLS] = {
        {1, 1, 2, 3, 4},
        {1, 1, 1, 9, 8},
        {1, 1, 1, 1, 4  }
    };

    print_sum_rows(ROWS, COLS, matrix_to_sum);

    // Exercise 20
    printf("Exercise 20\n");
    enum {r = 4, c = 3};
    double inf_matrix[r][c] =
        {
        {1, -2, 3},
        {-1, 0, 4},
        {2, -3, -1},
        {-4, 1, 2}
        };

    double inf_norm_value = inf_norm_matrix(r, c, inf_matrix);
    printf("inf nomr of the matrix is: %f", inf_norm_value);



    return 0;}
