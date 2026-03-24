#include <stdio.h>
// CONTENT: POINTERS, ARRAYS, MATRICES

int sum_with_pointers(int array[], int size);
int scalar_prod_arr_pointers(int array_A[], int array_[], int size);

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
    printf("sum using pointers is: %d \n", sum_using_pointers);

    int array_A[5] = {1,1,1,1,1};
    int array_B[5] = {2,2,2,2,2};
    int size_array_scalar_prod = sizeof(array_A)/sizeof(array_A[0]);
    int scalar_prod_arr_pointers_value = scalar_prod_arr_pointers(array_A, array_B, size_array_scalar_prod);
    printf("scalar_prod_arr_pointers_value: %d\n", scalar_prod_arr_pointers_value);
    return -1;


}

int sum_with_pointers(int array[], int size){
    int sum = 0;
    int* address = array;
    printf("address is: %p \n", *address);


    for (int i=0; i<size; i++) {
        printf("element at %d is %d: \n", i, *(array+i));
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