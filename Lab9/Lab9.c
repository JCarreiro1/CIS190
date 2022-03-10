#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkType(char data[]);

int main(){
    // Buffer array that will take user input as a string
    char buffer[32] = {0};
    // Variables that will count how many indices each data type has (length is how long each string is for the string data type)
    int intCount = 0, doubleCount = 0, charCount = 0, strCount = 0, strLength = 0;
    // Arrays for each data type
    int* dataI = NULL;
    double* dataD = NULL;
    char* dataC = NULL;
    // 2D array of variable size for strings
    char** dataS = (char **)calloc(strCount + 1, sizeof(char*));

    // Will prompt user until they enter in 'q' or 'Q'
    while(1){
        printf("\nEnter your data (or enter \"q\" to quit): ");
        scanf("%s", buffer);

        // Checks if input was q or Q
        if((buffer[0] == 81 || buffer[0] == 113) && buffer[1] == 0){
            break;
        }


        // Gets the length of each string entered into buffer
        for(strLength = 0; strLength < 32; strLength++){
            if(buffer[strLength] == 0){
                break;
            }
        }

        // If 1 is returned then data is an int
        if(checkType(buffer) == 1){
            // Resizes array to be one index larger than it was previously, reformats and adds data in buffer to array, increments index counter
            dataI = (int*)realloc(dataI, sizeof(int) * (intCount + 1));
            sscanf(buffer, "%d", &dataI[intCount]);
            intCount++;
        }
        // If 2 is returned then data is a double
        else if(checkType(buffer) == 2){
            // Resizes array to be one index larger than it was previously, reformats and adds data in buffer to array, increments index counter
            dataD = (double*)realloc(dataD, sizeof(double) * (doubleCount + 1));
            sscanf(buffer, "%lf", &dataD[doubleCount]);
            doubleCount++;
        }
        // If 3 is returned then data is a char
        else if(checkType(buffer) == 3){
            // Resizes array to be one index larger than it was previously, reformats and adds data in buffer to array, increments index counter
            dataC = (char*)realloc(dataC, sizeof(char) * (charCount + 1));
            sscanf(buffer, "%c", &dataC[charCount]);
            charCount++;
        }
        // If none of the above are met then data is a string
        else{
            // Resizes the amount of rows to be one larger than previous, sets length of new row to be equal to length of string
            dataS = (char**)realloc(dataS, (strCount + 1) * sizeof(char*));
            dataS[strCount] = (char*)calloc(strLength, sizeof(char));
            // Copies string into new row, sets ending row to point to NULL (I think this is for preventing memory leaks), increments row counter
            strcpy(dataS[strCount], buffer);
            dataS[strCount + 1] = NULL;
            strCount++;
        }

        printf("\nInteger List: ");

        // Prints every index in the int array
        for(int i = 0; i < intCount; i++){
            printf("%d ", dataI[i]);
        }

        // Prints every index in the double array
        printf("\nDouble List: ");

        for(int i = 0; i < doubleCount; i++){
            printf("%0.2lf ", dataD[i]);
        }

        printf("\nCharacter List: ");

        // Prints every index in the char array
        for(int i = 0; i < charCount; i++){
            printf("%c ", dataC[i]);
        }

        printf("\nString List: ");

        // Prints every index in the string array
        for(int i = 0; i < strCount; i++){
            printf("%s ", dataS[i]);
        }

        printf("\n");
    }

    free(dataI);
    free(dataD);
    free(dataC);
    free(dataS);

    return 0;
}

/*  This function will determine that data entered by the user
    The parameter is a character array that will represent the user's input
    The return value is an integer that will signify the data type of the data entered*/
int checkType(char data[]){
    // Type will be used to signify the data type, dot count will bw used to see how many "." there are,
    // i is used for the loop and to determine if a string
    // type 1 = int, 2 = double, 3 = char, 4 = string
    int type = 0;
    int dotcount = 0;
    int i;

    // Checks if there is only one element and if its a character; immediatly returns if true
    if(data[1] == 0 && (data[0] < 48 || data[0] > 57)){
        type = 3;
        return type;
    }

    // Fixes weird bug where a single digit int would be counted as a double
    if(data[1] == 0 && (data[0] >= 48 && data[0] <= 57)){
        return 1;
    }
    
    // Loop that verifies each index in the data array
    for(i = 0; i < 32; i++){
        // if the character is null, continue to next iteration (important that i reaches 32 if only digits are entered)
        if(data[i] == 0){
            continue;
        }

        // If element is a digit or a dot, continue. if not, exit because data cannot be int or double
        if((data[i] >= 48 && data[i] <= 57) || data[i] == 46){
            // if element is dot and there are no other dots, continue. otherwise, exit (more than one dot is a string)
            if(dotcount <= 1 && data[i] == 46){
                // Makes sure dot is not the end of array. if so, exit because dot is period (therefore data is string)
                if(data[i + 1] == 0){
                    break;
                }
                dotcount++;
            }
            else if(dotcount > 1){
                break;
            }
        }
        else{
            break;
        }
    }

    // If loop fully executed and there are no dots: int
    if(i == 32 && dotcount == 0){
        type = 1;
    }
    // If loop fully executed and there are is exactly one dot (not at the end): double
    else if(i == 32 && dotcount == 1){
        type = 2;
    }
    // Everything else: string
    else{
        type = 4;
    }

    return type;
}