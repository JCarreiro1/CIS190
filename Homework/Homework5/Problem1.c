/*  Jonathan Carreiro
    Homework 5
    11/10/20*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototype definitions
void populate(int arr[]);
int** createPointerArr();
void sortAsc(int* ptrArr[], int arr[]);
void sortDes(int* ptrArr[], int arr[]);
void display(int* asc[], int* des[], int arr[]);

int main(){
    int array[10];
    // Allocates memory for two arrays of pointers
    int** ascend = createPointerArr();
    int** descend = createPointerArr();

    srand(time(0));

    // Fills array and sorts in Ascending then descending order and prints results
    populate(array);
    sortAsc(ascend, array);
    sortDes(descend, array);
    display(ascend, descend, array);
 
    free(ascend);
    free(descend);

    return 0;
}

/*  This function fills an array with random integers between zero and 100
    This takes in an array as a parameter. This array is the array that will be filled
    There is no return because the array is a pointer so the values are changed directly*/
void populate(int arr[]){
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % (101 - 0) + 0;
    }
}

/*  This function allocates eleven spots in memory for an integer pointer array
    There are no parameters because the function is returning an array
    The return value is an array of integer pointers so that these arrays can be accessed in main*/
int** createPointerArr(){
    int** arr = (int**)malloc(11 * sizeof(int*));
    
    return arr;
}

/*  This function will sort the pointers of a pointer array to point at the values in an integer array in ascending order
    The parameters are an integer pointer array and an integer array.
    The pointer array is the array that will be sorted and the regular array holds the values that will be pointed to
    There is no return value because the pointer array is being changed inside the function*/
void sortAsc(int* ptrArr[], int arr[]){
    // Temp will hold the values of arr so that it can be restored at the end of the function
    int temp[10];
    // These two will hold the smallest value and the index of this value
    int indexSmallest;
    int smallest = 1000;

    // Copies arr into temp
    for(int i = 0; i < 10; i++){
        temp[i] = arr[i];
    }

    // Outer loop will loop for each pointer in the pointer array
    for(int i = 0; i < 10; i++){
        // Inner loop will loop through each value of integer array and find the smallest value
        for(int j = 0; j < 10; j++){
            // If the current value is smaller than the value stored in smallest, this executes.
            if(arr[j] < smallest){
                // Sets new smallest value to the value at the current index of integer array and stores the current index
                smallest = arr[j];
                indexSmallest = j;
            }
        }

        // Sets the pointer at the current index of the outer loop to point at the integer array at indexSmallest
        // Sets value at this index to a number past the maximum bounds of the integer array and resets smallest value
        // The value gets chenged so that it will no longer be the smallest value of the integer array
        ptrArr[i] = &arr[indexSmallest];
        arr[indexSmallest] = 10000;
        smallest = 1000;        
    }

    // Restores values of arr back to what they were at the beginning of the function 
    // (the difference is that the pointer array is now pointing at them in ascending order)
    for(int i = 0; i < 10; i++){
        arr[i] = temp[i];
    }

    // Sets end of pointer array to null to prevent memory leaks
    ptrArr[10] = NULL;
}

/*  This function will sort the pointers of a pointer array to point at the values in an integer array in descending order
    The parameters are an integer pointer array and an integer array.
    The pointer array is the array that will be sorted and the regular array holds the values that will be pointed to
    There is no return value because the pointer array is being changed inside the function*/
void sortDes(int* ptrArr[], int arr[]){
    // Temp will hold the values of arr so that it can be restored at the end of the function
    int temp[10];
    // These two will hold the largest value and the index of this value
    int indexLargest;
    int largest = -1000;

    // Copies arr into temp
    for(int i = 0; i < 10; i++){
        temp[i] = arr[i];
    }

    // Outer loop will loop for each pointer in the pointer array
    for(int i = 0; i < 10; i++){
        // Inner loop will loop through each value of integer array and find the largest value
        for(int j = 0; j < 10; j++){
            // If the current value is larger than the value stored in largest, this executes.
            if(arr[j] > largest){
                // Sets new largest value to the value at the current index of integer array and stores the current index
                largest = arr[j];
                indexLargest = j;
            }
        }

        // Sets the pointer at the current index of the outer loop to point at the integer array at indexLargest
        // Sets value at this index to a number past the minimum bounds of the integer array and resets largest value
        // The value gets chenged so that it will no longer be the largest value of the integer array
        ptrArr[i] = &arr[indexLargest];
        arr[indexLargest] = -10000;
        largest = -1000;        
    }

    // Restores values of arr back to what they were at the beginning of the function 
    // (the difference is that the pointer array is now pointing at them in descending order)
    for(int i = 0; i < 10; i++){
        arr[i] = temp[i];
    }

    // Sets end of pointer array to null to prevent memory leaks
    ptrArr[10] = NULL;
}

/*  This function will print the results of the sorting in a table like format
    The paramters are the two sorted pointer arrays and the integer array. These are ussed to get the values to print in each column
    There is no return value because all output is dobe inside of the function*/
void display(int* asc[], int* des[], int arr[]){
    printf("\tAscending\tOriginal\tDescending\n");

    for(int i = 0; i < 10; i++){
        printf("\t%6d\t\t%5d\t\t%6d\n", *asc[i], arr[i], *des[i]);
    }
}