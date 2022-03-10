/*  Jonathan Carreiro
    Homework 1
    10/3/20*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Variables that will hold the random number and each digit from left to right
    int randNum, digit1, digit2, digit3;
    
    // Variables that will hold the user number and each digit from left to right
    int userGuess, Udigit1, Udigit2, Udigit3;

    srand(time(0));

    printf("Generating Number...\n");

    // Randomly generates numbers until one is generated that meets requirements
    while(1){
        randNum = rand();
    
        // Makes sure number is 3 digits (100-110 are discarded as they have a zero in them)
        if(randNum > 110 && randNum <= 999){
            // Stores each digit in its corresponding variable (1 being leftmost and 3 being rightmost)
            digit1 = (randNum % ((int)pow(10, 3))) / (int)pow(10, 2);
            digit2 = (randNum % ((int)pow(10, 2))) / (int)pow(10, 1);
            digit3 = (randNum % ((int)pow(10, 1))) / (int)pow(10, 0);

            // Makes sure there are no zeroes in number
            if(digit2 != 0 && digit3 != 0){
                // Makes sure that at least two digits are the same
                if((digit1 == digit2) || (digit1 == digit3) || (digit2 == digit3)){
                    printf("Done!\n\n");
                    break;
                }
            }
        }
    }

    // Provides important info for the user
    printf("Info:\nYou must guess a randomly generated number\n");
    printf("At least one digit will appear twice\nYou have 10 guesses\n");
    printf("Hit = Number is correct and in the correct position\nMatch = Number is correct but position is incorrect\n\n");

    // Prompts user 10 times for their guesses
    for(int i = 1; i <= 11; i++){
        if(i<11){
              // Makes sure user number is valid
            while(1){

                printf("This is guess %d\nWhat is your guess? (Number must be three digits with no zeroes): ", i);
                scanf("%d", &userGuess);

                // Makes sure number is 3 digits (100-110 are discarded as they have a zero in them)
                if(userGuess > 110 && userGuess <= 999){
                    // Stores each digit in its corresponding variable (1 being leftmost and 3 being rightmost)
                    Udigit1 = (userGuess % ((int)pow(10, 3))) / (int)pow(10, 2);
                    Udigit2 = (userGuess % ((int)pow(10, 2))) / (int)pow(10, 1);
                    Udigit3 = (userGuess % ((int)pow(10, 1))) / (int)pow(10, 0);

                    // Makes sure there are no zeroes in number
                    if(Udigit1 != 0 && Udigit2 != 0 && Udigit3 != 0){
                        break;
                    }
                }

                printf("Invalid guess, try again.\n\n");
            }

            // Automatically exits loop if user is correct
            if(userGuess == randNum){
                printf("%d in position one is a hit!\n", Udigit1);
                printf("%d in position two is a hit!\n", Udigit2);
                printf("%d in position three is a hit!\n\n", Udigit3);
                printf("Congratulations, you successfully guessed %d!\n", randNum);
                break;
            }
            else{
                // Compares user digit1 to digit1 of the random number & displays hit if hit, match if match
                if(Udigit1 == digit1){
                    printf("%d in position one is a hit!\n", Udigit1);
                }
                // Prevents redundant info when entering multiple of the same # (No displaying hit when you already know its a match)
                else if((Udigit1 == digit2 && Udigit2 != digit2) || (Udigit1 == digit3 && Udigit3 != digit3)){
                    printf("%d is a match!\n", Udigit1);
                }

                // Compares user digit2 to digit2 of the random number & displays hit if hit, match if match
                if(Udigit2 == digit2){
                    printf("%d in posotion two is a hit!\n", Udigit2);
                }
                // Prevents redundant info when entering multiple of the same # (No displaying hit when you already know its a match)
                else if((Udigit2 == digit1 && Udigit1 != digit1) || (Udigit2 == digit3 && Udigit3 != digit3)){
                    printf("%d is a match!\n", Udigit2);
                }

                // Compares user digit3 to digit3 of the random number & displays hit if hit, match if match
                if(Udigit3 == digit3){
                    printf("%d in position three is a hit!\n", Udigit2);
                }
                // Prevents redundant info when entering multiple of the same # (No displaying hit when you already know its a match)
                else if((Udigit3 == digit1 && Udigit1 != digit1) || (Udigit3 == digit2 && Udigit2 != digit2)){
                    printf("%d is a match!\n", Udigit3);
                }
            }

            // Buffer lines
            printf("\n\n");
        }
        else{
            printf("You failed to guess %d", randNum);
        }
    }

    return 0;
}