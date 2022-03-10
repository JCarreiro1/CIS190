#include <stdio.h>
#include <math.h>

// Prototype definitions for all my functions
void numLength(int, int*);
void sumDigit(int, int, int*);
void largestDig(int, int, int*);
int recNumLength(int);
int recSumDigit(int);
int recLargestDig(int);

// Variables that will be used across multiple functions
int length, sum, largest;

int main(){
    int userNum;

    // Promts user for number until they enter a positive number
    while(1){
        printf("Enter an integer greater than 0: ");
        scanf("%d", &userNum);

        if(userNum > 0){
            break;
        }

        printf("Invalid number. Try again.\n\n");
    }

    // Calling all non-recursive functions
    numLength(userNum, &length);
    sumDigit(userNum, length, &sum);
    largestDig(userNum, length, &largest);

    // Printing all values gotten by non-recursive functions
    printf("\n\nValues found using non-recursive functions:");
    printf("\nLength = %d", length);
    printf("\nSum of digits = %d", sum);
    printf("\nLargest digit = %d", largest);

    // Ressetting all values so that they can be recalculated
    length = 0;
    sum = 0;
    largest = -1;

    // Calling and desplaying values calculated by recursive functions
    printf("\n\nValues found using recursive functions:");
    printf("\nLength = %d", recNumLength(userNum));
    printf("\nSum of digits = %d", recSumDigit(userNum));
    printf("\nLargest digit = %d", recLargestDig(userNum));

    return 0;
}

// Non-recursive method for finding the length of the number
void numLength(int num, int *len){
   *len = ((int)log10(num)) + 1;
}

// Non-recursive method for finding the sum of the digits in the number
void sumDigit(int num, int LEN, int* SUM){
    // Finds each individual digit and adds it to a sum
    for(int i = 1; i <= LEN; i++){
        *SUM += (num%((int)pow(10, i)))/(int)pow(10, i-1);
    }
}

// Non-recursive method for finding the largest digit in the number
void largestDig(int num, int LEN, int *lgst){
    *lgst = -1;
    // Checks each digit to see if it is larger than the current largest digit
    for(int i = 1; i <= LEN; i++){
        if (*lgst < (num%((int)pow(10, i)))/(int)pow(10, i-1)){
            // Replaces current largest digit
            *lgst = (num%((int)pow(10, i)))/(int)pow(10, i-1);
        }
    }
}

// Recursive method for finding the length of the number
int recNumLength(int num){
    // Base case
    if(num == 0){
        return 1;
    }

    // Adds one to the length for each recursive call
    num = num / 10;
    length += 1;
    recNumLength(num);

    return length;
}

// Recursive method for finding the sum of the digits in the number
int recSumDigit(int num){
    // Base case
    if(num == 0){
        return 0;
    }

    // Adds rightmost digit to sum then removes that digit from num. Recursive call comes after
    sum += (num % 10);
    num = num / 10;
    recSumDigit(num);

    return sum;
}

// Recursive method for finding the largest digit in the number
int recLargestDig(int num){
    // Base case
    if(num == 0){
        return 0;
    }

    // Checks if rightmost digit is larger than current largest
    if(largest < (num % 10)){
        // Replaces largest
        largest = (num % 10);
    }
    
    // Removes rightmost digit and then does recursive call
    num = num / 10;
    recLargestDig(num);

    return largest;
}