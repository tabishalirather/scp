#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// CONTENT: POINTERS, ARRAYS, MATRICES

int sum_with_pointers(int *array, int size);
int scalar_prod_arr_pointers(int *array_A, int *array_B, int size);
float inf_norm_pointers(float *array, int size);
float norm_euclid_pointers(float *array, int size);
float matrix_sum_pointers(int rows, int columns, float array[rows][columns]);

int main() {
    printf("main from premaster-3");

    // Pointer: A variable that stores the memory address
    int num = 3;
    int* address = &num;
    int value_at_address = *address;


    printf("value in num is: %d\n", num);
    printf("Address of variable num is: %p,\n", address);
    printf("value at location address is: %d\n", value_at_address);

    // So the idea is if we have a memory location say "loc", then doing *loc gives us the value stored at this location in the memory.
    // Now pointers and array: the literal name of an array is actually a pointer to the first element of the array. Example below:
    printf("-------------------------------------------------------------------------\n");
    int array[4] = {999,2,3,4};
    int *pointer_to_arr = array; //this value should be first the first element of the array.
    // int * mem_address_arr = &array;
    printf("first element of the array is: %d\n", *pointer_to_arr);

    // The above is equivalent to saying:
    int* address_arr = &array[0]; //stores the first element
    printf("Specified element of the array with address and value is: %p, %d: \n", address_arr, *address_arr);
    // Now pointers can move in memory. that means, so you can literally add n to the current memory location to get to the next memory location and then using pointer notation * to access the value at that location.
    printf("Addres and value of n+1th element is: %p, %d \n", address_arr+1, *(address_arr+1));
    printf("Addres and value of n+1th element is: %p, %d \n", address_arr+2, *(address_arr+2));
    // SO we can say arr[i] just defined *(arr+i) with "arr" pointing to the location of the first element in the array and then we can iterate to go the next elements.
    int test_arr[] = {3,5,2,1,-77,999};
    int index = 4;
    printf("usual array notation, specific element is at %d is %d:\n", index, test_arr[index]);
    printf("usual pointer notation, specific element is at %d is %d:\n", index, *(test_arr+index));


    int array_for_sum[4]={-2,-1,0,1};
    int size= sizeof(array_for_sum)/sizeof(array_for_sum[0]);
    int sum_using_pointers = sum_with_pointers(array, size);
    printf("sum using pointers is as given: %d \n", sum_using_pointers);

    int array_A[5] = {1,1,1,1,1};
    int array_B[5] = {2,2,2,2,2};
    int size_array_scalar_prod = sizeof(array_A)/sizeof(array_A[0]);
    int scalar_prod_arr_pointers_value = scalar_prod_arr_pointers(array_A, array_B, size_array_scalar_prod);
    printf("scalar_prod_arr_pointers_value is: %d\n", scalar_prod_arr_pointers_value);

    float inf_norm_arr[4]={5,2.2,-32,2};
    size = sizeof(inf_norm_arr)/sizeof(inf_norm_arr[0]);
    float inf_norm_value = inf_norm_pointers(inf_norm_arr, size);
    printf("inf_norm is: %f \n", inf_norm_value);


    float euclid_norm_arr[4]= {1,2,3,5};
    size = sizeof(euclid_norm_arr)/sizeof(euclid_norm_arr[0]);
    float euclid_norm_value = norm_euclid_pointers(euclid_norm_arr, size);
    printf("Euclidean norm for given array is: %.4f\n", euclid_norm_value);

    printf("---------------- \n");
    printf("Pointers and matrices\n");
    int test_matrix[3][3] = {{1,2,3},{3,2,1}, {3,6,1}};
    // int* test_matrix_addr = &test_matrix[3][3];
    printf("printed using pointers: %d \n", *(*(test_matrix+2)+1)); // this should print test: test_matrix[2][1]===i.e 6
    printf("Another way of acces is row-major order: %d \n", *((int *)test_matrix + (0*3) +0)); //*(matrix + (row_num * number_of_columns) + column_number);
    float matrix_sum_value=0;
    enum  ENUM {ROWS= 3, COLS= 3};
    float matrtx_for_sum_pointer[ROWS][COLS] = {{1,2,3.24}, {3,4,5},{5,6,7}};
    float matrix_sum_pointer_value = matrix_sum_pointers(ROWS, COLS, matrtx_for_sum_pointer);
    printf("matrix_sum using pointers is: %0.4f \n", matrix_sum_pointer_value);


    return -1;
}

float matrix_sum_pointers(int rows, int columns, float array[rows][columns]) {  //to note, matrix does not decay to pointer type rather it decays to datatype* [4] type.
    printf("--------------------------------------------------\n");
    float matrix_sum=0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            matrix_sum += *(*(array+i)+j);
        }
    }

    return matrix_sum;
}

float norm_euclid_pointers(float *array, int size) {
    printf("--------------------------------\n");
    float euclid_norm = 0;
    for (int i=0; i<size; i++) {
        euclid_norm += pow((*(array+i)),2);
    }
    euclid_norm = sqrt(euclid_norm);


    return euclid_norm;
}



int sum_with_pointers(int array[], int size){
    int sum = 0;
    int* address = array;
    printf("address is: %p \n", *address);


    for (int i=0; i<size; i++) {
        printf("element at %d is: %d \n", i, *(array+i));
    }
    for (int i=0; i<size; i++) {
        sum+=*(array+i);
    }

    return sum;
}

int scalar_prod_arr_pointers(int array_A[], int array_B[], int size) {
    int scalar_prod = 0;
    for (int i=0; i<size; i++) {
        scalar_prod += *(array_A+i) * *(array_B+i);
    }

    return scalar_prod;
}
float inf_norm_pointers(float *array, int size) {
    printf("-------------------------------------------------\n");
    float inf_norm_value = fabs(*array);
    for (int i=0; i<size; i++) {
        if (fabs(*(array+i))>fabs(inf_norm_value)) {
            inf_norm_value=fabs(*(array+i));
            // printf("max value %f is at index i %d \n:", abs(array[i]), i);
        }
    }
    return fabs(inf_norm_value);
}