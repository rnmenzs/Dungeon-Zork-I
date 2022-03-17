#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
#include "./headers/events.h"

void statusBar();

extern int battle;

int main(){
    setlocale(LC_ALL, "Portuguese");

    battle = 0;
    jogador.alive = 1;
    jogador.hp = 2;
    jogador.moves = 0;

    gets(jogador.name);

    char comando[50];

    system("cls");

    do{
        if(jogador.hp <= 0){
            jogador.alive = 0;
        }
        else{

            if( battle == 1){
                combat();
                statusBar(jogador);
            } else {
                // aqui armazena o que foi digitado na variavel char
                getCommand(comando);
                defaultCommandValidator(comando);
                statusBar(jogador);
            }
        }

    } while ( jogador.alive != 0 || comando != 27);

    if(jogador.alive == 0){
        printf("\x1b[2;31;40m---------You Died----------\x1b[0m\n");
    }

    return 0;
}

void statusBar(player jogador){
    printf("\x1b[2;30;47mHP: %i   Nome: ", jogador.hp); 
    puts(jogador.name); 
    printf("\x1b[0m\n");
}