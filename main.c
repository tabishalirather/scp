#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    double result;

    result = pow(cos(x), 2) + 2*M_PI*cos(pow(y,2));
    return result;
}

double f_peicewise(double x) {

    double result;
    if (x<=0) {
        result = 1+x;
    } else {
        result = 1-x;
    }

    return result;

}

int sum_n_ints(int n) {
    int sum = 0;
    sum = n*(n-1)/2;
    return sum;
}

int sum_n_ints_loop(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += i;
    }
    return sum;
}


double machine_precision() {
    double epsilon = 1;
    while (1+epsilon != 1) {
        epsilon = epsilon/2;
    }
    return epsilon;
}



void main(void) {
    int numA, numB, numC;
    numA=6;
    numB=numA++;
    numC=++numA;

    printf("The value of numB is %d and that of numC is %d\n", numB, numC);



    // Exercise 3
    printf("Exercise 3\n");
    float a = 0.512;
    float b = 3.252;
    float c = 4.1;

    double result = (a+b)*(c+1) - 4;
    printf("The result is: %.2f.\n", result);
    // return 0;

    // EXERCISE 4
    printf("Exercise 4\n");
    float small_num = 1e-2;
    double result_from_math_h;
    result_from_math_h = cos(small_num+M_PI)+1;
    printf("The result is: %.16f.\n", result_from_math_h);


    // EXERCISE 5
    printf("Exercise 5\n");
    double sqrt_num = 2.5;
    double small_sqrt_num = 1e-20;
    double sqrt_result = sqrt(pow(sqrt_num,2)+small_sqrt_num)-sqrt_num;
    printf("The result is: %.16f.\n", sqrt_result);
    printf("To note 10^(-20) is less than machine precision, so not considered in this calculation");


    // EXERCISE 6
    printf("Exercise 6\n");
    printf("f(-pi,pi): %.5f\n", f(-M_PI,M_PI));
    printf("f(-pi,pi): %.5f\n", f(0,M_PI/2));
    printf("f(-pi,pi): %.5f\n", f(-M_PI,2*M_PI));


    // EXERCISE 7
    printf("Exercise 7\n");
    printf("f(0) is: %f\n", f_peicewise(-2));
    printf("f(0) is: %f\n", f_peicewise(0));
    printf("f(0) is: %f\n", f_peicewise(3));

    // EXERCISE 8
    printf("Exercise 8\n");
    printf("Sum till n = 10 is: %d\n", sum_n_ints(10));
    printf("Sum till n = 20 is: %d\n", sum_n_ints(20));
    printf("Sum till n = 30 is: %d\n", sum_n_ints(30));

    printf("--------------------------------------------\n");
    printf("Sum till n = 10 is: %d\n", sum_n_ints_loop(10));
    printf("Sum till n = 20 is: %d\n", sum_n_ints_loop(20));
    printf("Sum till n = 30 is: %d\n", sum_n_ints_loop(30));

    printf("Exercise 9\n");
    printf("Machine precision is: %e", machine_precision());

}
