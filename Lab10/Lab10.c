#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkType(char data[]);

typedef struct intNode{
    int value;
    struct intNode* next;
} intNode;

typedef struct doubleNode{
    double value;
    struct doubleNode* next;
} doubleNode;

typedef struct charNode{
    char value;
    struct charNode* next;
} charNode;

typedef struct strNode{
    char value[32];
    struct strNode* next;
} strNode;

int main(){
    // Buffer array that will take user input as a string
    char buffer[32] = {0};
    // Creates head and tail for each link list of the different data types
    intNode* Ihead = NULL;
    intNode** Itail = &Ihead;
    doubleNode* Dhead = NULL;
    doubleNode** Dtail = &Dhead;
    charNode* Chead = NULL;
    charNode** Ctail = &Chead;
    strNode* Shead = NULL;
    strNode** Stail = &Shead;

    while(1){
        printf("\nEnter your data (or enter \"q\" to quit): ");
        scanf("%s", buffer);

        // Checks if input was q or Q
        if((buffer[0] == 81 || buffer[0] == 113) && buffer[1] == 0){
            break;
        }

        // If 1 is returned then data is an int
        if(checkType(buffer) == 1){
            // Creates new node of integer linked list
            intNode* newNode = (intNode*)malloc(sizeof(intNode));
            sscanf(buffer, "%d", &newNode->value);
            newNode->next = NULL;
            *Itail = newNode;
            Itail = &newNode->next;
        }// If 2 is returned then data is a double
        else if(checkType(buffer) == 2){
            // Creates new node of double linked list
            doubleNode* newNode = (doubleNode*)malloc(sizeof(doubleNode));
            sscanf(buffer, "%lf", &newNode->value);
            newNode->next = NULL;
            *Dtail = newNode;
            Dtail = &newNode->next;
        }
        // If 3 is returned then data is a char
        else if(checkType(buffer) == 3){
            // Creates new node of character linked list
            charNode* newNode = (charNode*)malloc(sizeof(charNode));
            sscanf(buffer, "%c", &newNode->value);
            newNode->next = NULL;
            *Ctail = newNode;
            Ctail = &newNode->next;
        }
        // If none of the above are met then data is a string
        else{
            // Creates new node of string linked list
            strNode* newNode = (strNode*)malloc(sizeof(strNode));
            strcpy(newNode->value, buffer);
            newNode->next = NULL;
            *Stail = newNode;
            Stail = &newNode->next;
        }

        printf("\nInteger List: ");

        // Creates traversal pointer for integer linked list
        intNode* Itrav = Ihead;
        // Prints all the data in each node of the int linked list
        while(Itrav != NULL){
            printf("%d ", Itrav->value);
            Itrav = Itrav->next;
        }

        printf("\nDouble List: ");

        // Creates traversal pointer for double linked list
        doubleNode* Dtrav = Dhead;
        // Prints all the data in each node of the double linked list
        while(Dtrav != NULL){
            printf("%0.2lf ", Dtrav->value);
            Dtrav = Dtrav->next;
        }

        printf("\nCharacter List: ");

        // Creates traversal pointer for character linked list
        charNode* Ctrav = Chead;
        // Prints all the data in each node of the char linked list
        while(Ctrav != NULL){
            printf("%c ", Ctrav->value);
            Ctrav = Ctrav->next;
        }

        printf("\nString List: ");

        // Creates traversal pointer for string linked list
        strNode* Strav = Shead;
        // Prints all the data in each node of the str linked list
        while(Strav != NULL){
            printf("%s ", Strav->value);
            Strav = Strav->next;
        }

        printf("\n");

    }

    

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