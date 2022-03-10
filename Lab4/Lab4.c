#include <stdio.h>
#include <math.h>

int main(){

    // Obtain user number
    int userNum;
    printf("Enter an Integer: ");
    scanf("%d", &userNum);

    // Create file
    FILE* outfile = fopen("output.txt", "w");

    // Special case if user enters 0
    if (userNum == 0){
            fprintf(outfile, "%d   ", 0);
    }

    // Print all digits of number (count used to increase number of indentations)

    int count = 1;

    for(int j = ((int)log10(userNum)) + 1; j > 0; j--){
        for(int i = 1; i <= j; i++){

            fprintf(outfile, "%d   ", (userNum%((int)pow(10, i)))/(int)pow(10, i-1));
        }

        // Stops from creating extra line after all digits are finished printing
        if(j > 1){
            // Creates new line with proper indentation
            fprintf(outfile, "\n%*s", count * 2, "");
            count += 1;
        }

    }

    count -= 2;

    // Print digits in reverse order
    
    fprintf(outfile, "\n%*s", count * 2, "");

    for(int j = 2; j <= ((int)log10(userNum)) + 1; j++){
        for(int i = j; i > 0; i--){
            fprintf(outfile, "%d   ", (userNum%((int)pow(10, i)))/(int)pow(10, i-1));
        }

        
        // Creates new line with proper indentation
        count -= 1;
        fprintf(outfile, "\n%*s", count * 2, "");
        
    }


    return 0;

}