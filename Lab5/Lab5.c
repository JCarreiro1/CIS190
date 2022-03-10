#include <stdio.h>
#include <math.h>

void findA(int*, int*);
void findB(int*, int*);
void findC(int*, int*);

// Calculates a value for a based on the value for n
void findA(int *A, int *N){
    // Variables to keep track of total sum and total product
    int sum = 0;
    int prod = 1;

    // Runs a sum of products nested loop structure if n is less than 5
    if(*N < 5){
        for(int i = 1; i <= *N; i++){
            prod = 1;
            for(int j = 1; j <= i; j++){
                prod *= (j + i);
            }

            sum += prod;
        }

        *A = sum;
    }

    // Runs a total sum loop if n is between 5 (inclusive) and 10 (non inclusive)
    if(*N >= 5 && *N < 10){
        for(int i = 1; i <= *N; i++){
            sum += (i + 2);
        }

        *A = sum;
    }

    // Assigns a to n * 34 if n is greater than or equal to 10
    if(*N >= 10){
        *A = *N * 34;
    }

    return;
}

// Calculates a value for b based on the value for n
void findB(int *B, int *N){
    // Runs arithmetic in if statement if n is less than 10
    if(*N < 10){
        *B = *N + 1;
    }
    // Otherwise, this arithmetic will execute
    else{
        *B = (*N + 1) * (*N + 2);
    }

    return;
}

// Calculates a value for c based on the value for n
void findC(int *C, int *N){
    // Compares value of n to cases 1-5 and executes arithmetic accordingly
    switch(*N){
        case 1:
            
        case 2:
            *C = 2 * *N;
            break;
        case 3:
            
        case 4:
            
        case 5:
            *C = pow(*N, 2);
            break;
        // Executes if no other case is triggered
        default:
            *C = *N - 1;
            
    }

    return;
}

int main(){
    // Variables that will be used for the equation
    int a, b, c, n;
    float y;

    // Get users n value
    printf("Enter an integer value: ");
    scanf("%d", &n);

    // Get values for a, b, and c
    findA(&a, &n);
    findB(&b, &n);
    findC(&c, &n);

    // Display values for a, b, and, c
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    // Use obtained values to calculate y
    y = a * ((float)b / (float)c) - a * b + c;

    // Display y
    printf("y = %f\n", y);

    return 0;
}