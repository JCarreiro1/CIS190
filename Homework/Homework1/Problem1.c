/*  Jonathan Carreiro
    Homework 1
    10/2/20*/

#include <stdio.h>
#include <math.h>

int main(){

    // Value the will store the users integer
    int userNum;

    // Creates infinite loop until user enters a number within bounds
    while(1){
        printf("Enter an Integer between 1 and 15462: ");
        scanf("%d", &userNum);

        // Makes sure users number is in bounds
        if(userNum >= 1 && userNum <= 15462){
            // Keeps track of how many indentations are needed
            int indent = 1;

            // Code for part 1 of problem 1
            for(int j = ((int)log10(userNum)) + 2; j > 0; j--){
                for(int i = 1; i <= j; i++){
                    printf("%d   ", (userNum % ((int)pow(10, j))) / (int)pow(10, j-1));
                }

                // Stops from creating extra line after all digits are finished printing
                if(j > 1){
                    // Creates new line with proper indentation (keeping right allignemt)
                    printf("\n%*s", indent * 4, "");
                    indent += 1;
                }
            }

            // Buffer line
            printf("\n\n");

            // Code for part 2 of problem 1

            // Loops as many times as there are digits
            for(int i = 1; i <= ((int)log10(userNum)) + 1; i++){
                // Takes all the digits (starting with the rightmost) and prints them. Removes one digit from the right after each iteration
                // Only 6  cases because highest bound is only 5 digits
                switch(i){
                    case 1:
                        // Prevents unnessecary zeroes by making sure there are enough digits (happens in each case)
                        if(1 <= ((int)log10(userNum)) + 1){
                            printf("%d   ", (userNum % ((int)pow(10, 1))) / (int)pow(10, 0));
                        }
                    case 2:
                        if(2 <= ((int)log10(userNum)) + 1){
                            printf("%d   ", (userNum % ((int)pow(10, 2))) / (int)pow(10, 1));
                        }
                    case 3:
                        if(3 <= ((int)log10(userNum)) + 1){
                            printf("%d   ", (userNum % ((int)pow(10, 3))) / (int)pow(10, 2));
                        }
                    case 4:
                        if(4 <= ((int)log10(userNum)) + 1){
                            printf("%d   ", (userNum % ((int)pow(10, 4))) / (int)pow(10, 3));
                        }
                    case 5:
                        if(5 <= ((int)log10(userNum)) + 1){
                            printf("%d   ", (userNum % ((int)pow(10, 5))) / (int)pow(10, 4));
                        }
                    case 6:
                        // No check here because there always must be a zero at the end of each line
                        printf("%d   \n", (userNum % ((int)pow(10, 6))) / (int)pow(10, 5));

                    }   
                }

            // Creates line that is just 0 at the end
            printf("%d", 0);

            
            // Ends infinite loop
            break;
        }
        else{
            // Gives warning and continues loop
            printf("That number is out of bounds. Try again.\n\n");
            continue;
        }
    }

    return 0;
}