#include <stdio.h>

/*  This function will compare each charecter in two different strings and print 1 if theyre the same, 0 if not
    The two parameters are the character arrays (strings) to be compared
    There is no return because all output is being printed*/
void compareCS(char A[], char B[]){
    printf("\nString 1 = %s\n", A);
    printf("String 2 = %s\n", B);

    for(int i = 0; i < 100; i++){
        // Makes sure that the null terminators arent compared
        if(A[i] != 0 || B[i] != 0)
        {
            // If characters are equal, print 1. otherwise, print 0
            if(A[i] == B[i]){
                printf("%d ", 1);
            }
            else{
                printf("%d ", 0);
            }
        }
    }

    printf("\n");
}

/*  This function will take each character in a given string and reverse their order
    The parameter is the character array (string) to be reversed
    There is no return because all output is being printed*/
void reverse(char str[]){
    char rev[100] = {0};

    printf("\nReversed String = ", rev);

    // Starts at last index of string that was passed in and copies it to first location of output array rev
    for(int i = 99; i >= 0; i--){
        // Only copies if character isnt null
        if(str[i] != 0){
            rev[99 - i] = str[i];
            // Prints character after copying it
            printf("%c", rev[99 - i]);
        }
    }
}

/*  This function will compare each charecter in two different strings and print 1 if theyre the same (regardless of case), 0 if not
    The two parameters are the character arrays (strings) to be compared
    There is no output because all output is being printed*/
void compareNCS(char A[], char B[]){
    printf("\n\nString 1 = %s\n", A);
    printf("String 2 = %s\n", B);

    for(int i = 0; i < 100; i++){
        // Makes sure that the null terminators arent compared
        if(A[i] != 0 || B[i] != 0)
        {
            // If characters are equal, print 1. otherwise, print 0
            // Uses bitmask of 32 (since capital and lowercase are only different in the 32s place) and logical or so that case doesnt matter
            if((A[i] | 32) == (B[i] | 32)){
                printf("%d ", 1);
            }
            else{
                printf("%d ", 0);
            }
        }
    }

    printf("\n");
}