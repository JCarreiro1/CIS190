#include <stdio.h>
#include <string.h>

int main(){
    char user[32] = {0};
    char pog[32] = "kevin";
    char POG[32] = "KEVIN";

    printf("\nEnter User: ");
    scanf("%s", user);

    if(strcmp(user, pog) == 0){
        printf("Kevin is pog\n");
    }else if(strcmp(user, POG) == 0){
        printf("KEVINNNNNNNNNN, WAZZZUUUUUUUUUUUUUUUPP!!!!!!!!!\n");
    }else{
        printf("%s is stinky\n", user);
    }
    
}