#include <stdio.h>
#include <math.h>

double findA(int);
double findB(int);
double findC(int);

/*  Calculates a value for a based on the value for n.
    Takes in the value of n as a parameter so that the proper calculations can be made.
    returns a double to be stored in a for the calculation of y.*/
double findA(int N){
    int sum = 0;
    int prod = 1;
    double A;

    // Runs a sum of products nested loop structure if n is less than 3
    if(N < 3){
        for(int i = 1; i <= N; i++){
            prod = 1;
            for(int j = 1; j <= i; j++){
                prod *= (j + (1 / i));
            }

            sum += prod;
        }

        A = (double)sum;
    }
    // Runs a summation loop if n is between 3 (inclusive) and 20 (exclusive)
    else if (N >= 3 && N < 20){
        for(int i = 1; i <= N; i++){
            sum += i * 2;
        }

        A = (double)sum + 5;
    }
    // Sets a to square root n if n is 20+
    else{
        A = sqrt((double)N);
    }

    return A;
}

/*  Calculates a value for b based on the value for n.
    Takes in the value of n as a parameter so that the proper calculations can be made.
    returns a double to be stored in b for the calculation of y.*/
double findB(int N){
    double B;

    // Compares value of n to cases 1-45 and executes arithmetic accordingly
    switch(N){
        case 1:
            
        case 2:
            
        case 3:
            
        // Sets b to sqrt of n if n is < 5
        case 4:
            B = sqrt((double)N);
            break;
        case 5:
            
        case 6:

        case 7:

        case 8:

        case 9:

        case 10:

        case 11:

        case 12:

        case 13:

        case 14:

        case 15:

        case 16:

        case 17:

        case 18:

        case 19:

        case 20:

        case 21:

        case 22:

        case 23:

        // Sets b to (n - 1) * (n + 2) if n is between 5 (inclusive) and 25 (exclusive)
        case 24:
            B = (N - 1) * (N + 2);
            break;
        case 25:

        case 26:

        case 27:

        case 28:

        case 29:

        case 30:

        case 31:

        case 32:

        case 33:

        case 34:

        case 35:

        case 36:

        case 37:

        case 38:

        case 39:

        case 40:

        case 41:

        case 42:

        case 43:

        // Sets b equal to the floor of n if n is between 25 (inclusive) and 45 (exclusive)
        case 44:
            B = floor((double)N);
            break;
        // Sets b to n if n is 45+
        default:
            B = (double)N;
            break;
    }

    return B;
}

/*  Calculates a value for c based on the value for n.
    Takes in the value of n as a parameter so that the proper calculations can be made.
    returns a double to be stored in c for the calculation of y.*/
double findC(int N){
    double C;

    // Assigns c to n + cos(n) if n is 1 or 2
    if(N <= 2){
        C = N + cos((double)N);
    }

    // Assigns c to n - 3 if n is between 3 (inclusive) and 5 (inclusive)
    if(N >= 3 && N <= 5){
        C = N - 3;
    }

    // Assigns c to n * 2 if n is 5+
    if(N > 5){
        C = N * 2;
    }

    return C;
}

int main(){
    // Variables that will be used for the equation
    double a, b, c, y;
    int n;

    // Get users n value until it is greater than zero
    while(1){
        printf("Enter an integer value that is greater than zero: ");
        scanf("%d", &n);

        if(n > 0){
            break;
        }

        printf("Invalid number. Try again.\n\n");
    }
    

    // Get values for a, b, and c
    a = findA(n);
    b = findB(n);
    c = findC(n);

    // Display values for a, b, and, c
    printf("a = %0.2lf\n", a);
    printf("b = %0.2lf\n", b);
    printf("c = %0.2lf\n", c);

    // Use obtained values to calculate y
    y = a - b * (-c);

    // Display y
    printf("y = %0.2lf\n", y);

    return 0;
}