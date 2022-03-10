#include <stdio.h>

// Imports functions from customString.c and prototype definitions from customString.h
#include "customString.h"

int main(){
    char stringA[100] = {0};
    char stringB[100] = {0};

    // Gets user words and stores them in character arrays stringA and stringB
    printf("Enter your first word: ");
    scanf("%s", stringA);

    printf("Enter your second word: ");
    scanf("%s", stringB);

    // Calling of imported functions
    compareCS(stringA, stringB);

    reverse(stringA);

    compareNCS(stringA, stringB);

    return 0;
}