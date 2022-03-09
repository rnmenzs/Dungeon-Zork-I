#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "./randomevents.h"

#define ENTER 13

char getCommand(char text[]){

    gets(text);

    return 0;
}

char showBanner(char text[]){
    int i;

    for (i = 0; i < strlen(text); i++){
        printf("%c", text[i]);
        Sleep(1);
    }
    return 0;
}

int decision(char text[]){
    char compare[] = "frente";
    if ( strcmp("frente", text) == 0){
        return 1;
    }
}

char way(int decision){
    switch (decision){
    case 1:
        printf("Você andou para frente e ");
        randomNum(1, 10);
        
        break;
    
    default:
        break;
    }
}