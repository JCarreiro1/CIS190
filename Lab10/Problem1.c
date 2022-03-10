#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate(int arr[]);

int main(){
    int array[10];

    srand(time(0));

    populate(array);

    for(int i = 0; i < 10; i++){
        printf("%d\n", array[i]);
    }

    return 0;
}

void populate(int arr[]){
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % (101 - 0) + 0;
    }
}