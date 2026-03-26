#include <stdio.h>

void print_matrix(int rows, int cols, double* matrix);
void print_array(int size, double* array);
int check_diagonal(int rows, int cols, double* matrix);
void forward_sub(int rows, int cols, int flag, double* matrix, double* vector_rhs, double* vector_lhs);

int main() {
    printf("Printing in training_1_fwd_sub\n");
    enum {ROWS=3, COLS=3};
    double matrix_l[ROWS][COLS] ={
        {5,0,0},
        {1,2,0},
        {3,4,1}
    };

    double vec_b[ROWS] = {5,5,16};
    double vec_x[ROWS];
    print_matrix(ROWS, COLS, &matrix_l[0][0]);
    print_array(ROWS, vec_b);
    int flag_valid_matrix_value = check_diagonal(ROWS, COLS, &matrix_l[0][0]);
    printf("flag_valid_matrix_value: %d \n", flag_valid_matrix_value);

    forward_sub(ROWS, COLS,flag_valid_matrix_value,  &matrix_l[0][0], vec_b, vec_x);

}
void forward_sub(int rows, int cols,  int flag, double* matrix, double* vector_b, double* vector_x) {
    printf("\nprinting from forward sub\n");
    double temp_sum = 0;
    if (1==flag) {
        printf("valid matrix..computing soln\n");
        *(vector_x+0) = *(vector_b+0)/(*(matrix + 0*cols + 0));
        // *(vector_x+1) = (*(vector_b+1) - (*(matrix +1*rows + 0)*(*vector_x+0)))/(*(matrix + 1*cols + 1));
        // printf("outside the loop *(vector_x+0): %f\n", *(vector_x));
        // printf("outside the loop *(vector_x+1): %f\n", *(vector_x+1));

        for (int i=1; i<rows; i++) {
            temp_sum=0;
            for (int j=0; j<i; j++) {
                temp_sum += *(matrix +i*cols +j)* (*(vector_x + j));
                // printf("l_[%d][%d] * x_[%d]+ = %0.2f * %0.2f\n", i+1,j+1, j+1, *(matrix +i*cols +j), *(vector_x + j));
                // printf("temp_sum is:%f \n ", temp_sum);
                // printf("b_[%d]-temp_sum/(l_ii): (%f - %f )/%f\n", i+1, *(vector_b+i), temp_sum, *(matrix +i*cols +i));
                *(vector_x+i) = ((*(vector_b+i)-(temp_sum))/(*(matrix + i*cols + i)));
                // printf("*(vector_x+%d) is:%f \n",i, *(vector_x+i));
            }
            printf("\n");
        }
        printf("Solution vector_x is: \n");
        print_array(rows, vector_x);
    }
}

int check_diagonal(int rows, int cols, double* matrix) {
    printf("printing in check_diagonal\n");
    int flag_valid_matrix=1;
    for (int i=0; i<rows; i++) {
            if(*(matrix +i*cols + i) == 0) {
                printf("a_(%d,%d)=", i,i);
                printf("%0.2f ", *(matrix +i*cols + i));
                printf("Atleast one diagonal element is zero; give different matrix\n");
                flag_valid_matrix=-1;
                return flag_valid_matrix;
        }
    }
    return flag_valid_matrix;

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

