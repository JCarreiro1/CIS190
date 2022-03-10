#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototype definitions
int readFile(void);
void createFile(void);
void findSmallest(void);
void printResults(int, int, int, int);


// We had a conversation and you said that global variables are ok
// Static counter that will increment each time readFile is called (helps read one extra line each time)
static int count = 1;
// Variables to store the two smallest integers and the amount of times they show up
int small1, small2, repeat1, repeat2;

int main(){
    srand(time(0));

    createFile();

    findSmallest();

    // // Used for testing so that I dont have to reopen output.txt every time
    // printf("Contents of output.txt\n");
    // for (int i = 0; i < 20; i++){
    //     printf("\n%d", readFile());
    // }

    printResults(small1, small2, repeat1, repeat2);

    return 0;
}

/*  Function that reads the file that created by createFile.
    Will read nothing/previous version of output.txt if called first.
    Takes no input because all the data needed is being read from a file.
    Returns the most recent integer read from the file.*/
int readFile(void){
    int num;
    
    FILE* infile = fopen("output.txt", "r");

    // Reads file "count" times and rewrites num each time (most recent num will be returned)
    for(int i = 0; i < count; i++){
        fscanf(infile, "%d", &num);
    }
    
    count++;

    fclose(infile);

    return num;
}

/*  Function that creates a file.
    Takes no parameters because there are none needed.
    Has no returns because everything is printed to a file.*/
void createFile(){
    FILE* outfile = fopen("output.txt", "w");

    // Fills file with 20 random numbers between 0 and 100
    for(int i = 0; i < 20; i++){
        fprintf(outfile, "%d\n", rand() % (100 - 0) + 0);
    }

    fclose(outfile);
}

/*  Function that finds the two smallest numbers in the file and how many times they repeat.
    This function takes no parameters because all values are changed directly thorugh global variables.
    This function has no return because the values are changed within the function and do not need to be returned.*/
void findSmallest(){
    // temp will hold the current value from the file, swap will keep small1 so that it can be moved to small 2
    int temp, swap;

    // Initializing small1 and small2 to unreachable values so they are guaranteed to be overwritten
    small1 = 1000;
    small2 = 1000;
    repeat1 = 1;
    repeat2 = 1;

    // Loops through entire file
    for(int i = 0; i < 20; i ++){
        temp = readFile();

        // Changes small1 to temp if it is smaller than small1 but not the same as small2
        if(temp < small1 && temp != small2){
            // Changes small1 to temp and small2 to small1 while resetting the repeat counters
            swap = small1;
            small1 = temp;
            small2 = swap;
            repeat1 = 1;
            repeat2 = 1;
        }
        // Increments repeat counter for small1 if there is a repeat
        else if (temp == small1 && temp != small2){
            repeat1++;
        }

        // Changes small2 to temp if it is smaller than small2 but not the same as small1
        if(temp < small2 && temp != small1){
            small2 = temp;
            repeat2 = 1;
        }
        // Increments repeat counter for small2 if there is a repeat
        else if (temp == small2 && temp != small1){
            repeat2++;
        }
    }
}


/*  This function will print the results .
    The inputs will be the variables holding two smallest integers and the amount of times that they show up.
    There are noreturns on this function because the results are being printed directly.*/
void printResults(int s1, int s2, int r1, int r2){
    // Output for user
    printf("\nThe two smallest numbers are %d and %d\n", s1, s2);
    printf("%d shows up %d time(s) and %d shows up %d time(s)\n", s1, r1, s2, r2);
}