/*  Jonathan Carreiro
    Homework 4
    11/10/20*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rows;

double weightCalc(double arr[][rows], int curRow, int curIndex);

int main(){
    srand(time(0));

    printf("How many rows are in the pyramid? ");
    scanf("%d", &rows);

    // Uses the variable amount of people to create an array
    double weights[rows][rows];
    // Will be used to create a variable amount of spaces for printing each row
    int tabs = rows;

    // Fills array with random numbers in between 50 and 150
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < rows; j++){
            if(j <= i){
                weights[i][j] = (double)(rand() % (115) + 60) * 100 / (RAND_MAX % (100) + 50);
            }
            else{
                weights[i][j] = 0;
            }
        }
    }

    printf("\nEach person's own weight:\n");



    // Prints out the weights in a pyramid shape
    for(int i = 0; i < rows; i++){
        // Creates the spacing for each row
        printf("%*s", tabs * 3, "");
        for(int j = 0; j < rows; j++){
            if(weights[i][j] != 0)
            {
                printf("%0.2lf  ", weights[i][j]);
            }
        }
        
        printf("\n");
        tabs--;
    }

    // Resets the tab count for printing of second pyramid
    tabs = rows;

    printf("\n\nWeight on each person's knees:\n");

    // Finds the weight on the knees for each corresponding element in the original array and prints them in a pyramid
    for(int i = 0; i < rows; i++){
        printf("%*s", tabs * 3, "");
        for(int j = 0; j <= i; j++){
            printf("%0.2lf  ", weightCalc(weights, i, j));
        }

        printf("\n");
        tabs--;
    }

    return 0;
}

/*  This recursive function will find out the weight on the knees of the person (element) entered in
    The parameters are the original array so that I have access to all weights, the current row, and the current index so I can keep track of my position
    The return value is the weight on the knees of the coordinates entered (represented as a double)*/
double weightCalc(double weights[][rows], int curRow, int curIndex){
    // Checks if at the top of the pyramid
    // Returns weight of person on top if true
    if(curRow == 0 & curIndex == 0){
        return weights[curRow][curIndex];
    }
    // Checks if at the left edge of the pyramid
    // Returns weight at current position plus half the weight of person to top right if true
    else if(curRow >= 1 && curIndex == 0){
        return weights[curRow][curIndex] + (weightCalc(weights, curRow - 1, curIndex) / 2);
    }
    // Checks if at the right edge of the pyramid
    // Returns weight at current position plus half the weight of person to top left if true
    else if(curRow >= 1 && curIndex == curRow){
        return weights[curRow][curIndex] + (weightCalc(weights, curRow - 1, curIndex - 1) / 2);
    }
    // If anywhere else, returns weight at current position plus half the weight of person to top right and half the weight of the person to the top left
    else{
        return weights[curRow][curIndex] + (weightCalc(weights, curRow - 1, curIndex) / 2) + (weightCalc(weights, curRow - 1, curIndex - 1) / 2);
    }
}