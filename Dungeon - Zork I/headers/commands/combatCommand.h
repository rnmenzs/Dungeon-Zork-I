#include <stdio.h>
#include <stdlib.h>

void getCombatCommand(char text[]);
int combatCommand(char text[]);

void getCombatCommand(char text[]){
    gets(text);
}

int combatCommand(char text[]){
    if ( strcmp("--ajuda", text) == 0){
        return 0;
    }
 
    if ( strcmp("ataque 1", text) == 0){
        return 1;
    }

    if ( strcmp("ataque 2", text) == 0){
        return 2;
    }

    if ( strcmp("ataque 3", text) == 0){
        return 3;
    }

    if ( strcmp("ataque 4", text) == 0){
        return 4;
    }

    return -1;
}