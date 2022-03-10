/*  Jonathan Carreiro
    Homework 3
    10/28/20*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createDay(int selection[], int day);

// Array size of hotel prices
#define SIZE 8

int main(){
    srand(time(0));

    int hotels[SIZE] = {214, 149, 157, 104, 121, 127, 128, 101};

    printf("\n");

    createDay(hotels, 1);

    return 0;
}

/*  This function creates a travel plan for each day out of a total three days. Each travel id barred from going over $400
    The parameters of this function are used to keep track of the current selection of unused hotels and the current day
    There is no return type because all output is done from inside the function*/
void createDay(int selection[], int day){
    // Variables that generate an index of the array, keep track of the total money spent for the day, and keep track of how many hotels have been used
    int loc = rand() % SIZE;
    int dayTotal = 0;
    static int zeroCount = 0;

    // Base case that will exit recursive function if the day is 4 or greater
    if(day >= 4){
        return;
    }

    printf("Travel %d: ", day);

    // The pair of either 148 and 127 or 148 and 128 wont allow for a third hotel so I prevent those combos by pairing 127 and 128 on the first day
    if(day == 1){
            printf("$%d ", selection[6]);
            dayTotal += selection[6];
            selection[6] = 0;
            printf("$%d ", selection[5]);
            dayTotal += selection[5];
            selection[5] = 0;
            zeroCount += 2;
    }

    // Infinite loop that will end once the day is completely booked
    while(1){
        // Checks that value at current index to make sure that it isnt zero and wont go over 400 when added to the total
        if(dayTotal + selection[loc] <= 400 && selection[loc] != 0){
            /*  Prevents values 214 and 157 from showing up on any day except for day 3 in order to ensure that all values are used
                Any day that has 214 will only print two values and if 149 and 157 get paired on the same day then that day will only have two values
                This will result in a 2-2-3 which is only 7 hotels printed out of 8
                This conditional solves that problem */
            if(day != 3 && selection[loc] < 150){
                // Prints out value at index, adds it to dayTotal, sets it to zero, and increments zeroCount
                printf("$%d ", selection[loc]);
                dayTotal += selection[loc];
                selection[loc] = 0;
                zeroCount++;
            } else if(day == 3){
                // Prints out value at index, adds it to dayTotal, sets it to zero, and increments zeroCount
                // Values here should inly be 214 and 157 since they are they only two left
                printf("$%d ", selection[loc]);
                dayTotal += selection[loc];
                selection[loc] = 0;
                zeroCount++;
            }
        }

        // If total is >= 300 then no other hotels can be added
        if(dayTotal >= 300){
            break;
        }

        // If zeroCount == the size of the array, then every hotel has been used
        if(zeroCount >= SIZE){
            return;
        }

        loc = rand() % SIZE;
    }

    printf("\n");

    // Recursiva call that advences day and passes array with some values changed to zero
    createDay(selection, ++day);
    
    return;
}