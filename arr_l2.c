#include <stdio.h>
#include <math.h>

double inf_norm(double array_inf_norm[], int size) {
    double max=0;
    printf("size is: %d\n", size);
    for (int index=0; index<size; index++) {
        if (fabs(array_inf_norm[index])>fabs(array_inf_norm[index+1])){
            printf("array_inf_norm_index_[%d] = %f\n", index, array_inf_norm[index]);
            printf("array_inf_norm_index_+1_[%d] = %f\n", index+1, array_inf_norm[index+1]);
            if (fabs(array_inf_norm[index])>max) {
                max = fabs(array_inf_norm[index]);
            }
            printf("max in inf norm fxn is: = %f\n", max);
        }
    }
    return max;
}

double sum_array(double array_to_sum[], int size) {
    // imporntant bit of remember here is that when passing arrays as arguments, they decay into points, so only the pointer(memory address is sent) not the length of the array. So the fxn only really gets accesst to the starting point of the element and consequently its size.


    printf("calling sum_array\n");
    double sum = 0;
    // size of gives you the memory size taken by the variable, not the lenght
    // int size = sizeof(array_to_sum)/sizeof(array_to_sum[0]);
    // print()
    printf("array size is in the fxn: %d\n", size);
    for (int index=0; index<size; index++) {
        printf("array_to_sum[%d] = %f\n", index, array_to_sum[index]);
        sum += array_to_sum[index];
    }

    return sum;
}

double product_array(double array_A[], double array_B[], int size) {
    double sum_product=0;
    // double sum = 0;
    printf("calling product_array\n");

    for (int index=0; index<size; index++) {
        // printf("array_A[%d] = %f\n", index, array_A[index]);
        // printf("array_B[%d] = %f\n", index, array_B[index]);
        sum_product += array_A[index]*array_B[index];
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

    int new_arr[5]={1,2,3,4};
    // This is how you can print an array
    for(int i=0;i<5;i++) {
        // printf("arr[%d] = %d\n", i, new_arr[i]);
    }
    double first_ten[10];
    for(int j=0; j<10; j++) {
        // printf("j is: %d:\n", j);
        double a_ith =  (2*pow(j,2)+1)/(j+3);
        // printf("a_ith is: %.2f:\n", a_ith);
        first_ten[j] = (2*pow(j,2)+1)/(j+3);
        // printf("%d th element of first_ten array is: %.2f:\n",j+1, first_ten[j]);
    }
    // printf("Element of first_ten array is %0.2f:\n", first_ten[0]);
    // printf("3rd value is: %.2f: ", first_ten[2]);
    for (int k=0; k<10; k++) {
        double element_to_print = first_ten[k];
        printf("first_ten[%d] = %0.2f\n", k, element_to_print);
    }

    printf("Exercise 11\n");
    double array_to_sum[4]={1,9,8,6};
    int array_size = sizeof(array_to_sum)/sizeof(array_to_sum[0]);
    double sum = sum_array(array_to_sum,array_size);
    printf("The sum of the array is: %0.0f\n", sum);


    printf("Exercise 12\n");
    double array_A[]={1,2,3,4};
    double array_B[]={5,6,7,8};
    int size_for_product = sizeof(array_A)/sizeof(array_A[0]);
    double product = product_array(array_A,array_B,size_for_product);
    printf("product of array_A and array_B is: %f \n", product);


    printf("Exercise 13\n");
    double arr_inf_norm[]={-1.5, 3.2, -4.8, 2.1};
    int size = sizeof(arr_inf_norm)/sizeof(arr_inf_norm[0]);
    double max_norm = inf_norm(arr_inf_norm,size);
    printf("max_norm = %f\n", max_norm);

    printf("Exercise 14: Hilbert matrix\n");
    int size_hilbert = 10;
    double hilbert_matrix[10][10];
    int test_size = 4;
    double test_matrix[test_size];
    for (int i=1; i<test_size; i++) {
        double entry = 1.0/i;
        printf("i is %.2f\n",entry);
        test_matrix[i]=entry;
    }
    for (int i=0; i<test_size; i++) {
        printf("test_matrix[%d] = %f\n", i, test_matrix[i]);
    }

    return 0;
}