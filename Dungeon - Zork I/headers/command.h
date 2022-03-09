#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "./randomevents.h"

//Esse script é voltado as funções de comandos

char getCommand(char text[]);
int decision(char text[]);
char way(int decision);

// Essa função está pegando o que foi digitado e armazenando na variavel do tipo char
char getCommand(char text[]){

    gets(text);

    return 0;
}

// essa função pega o valor char que foi armazenado e verifica se entra em algum comando
// para passar para a função way
int decision(char text[]){
    if ( strcmp("--ajuda", text) == 0){
        return 0;
    }
 
    
    if ( strcmp("frente", text) == 0){
        return 1;
    }

    return -1;
}

// essa função pega o valor fornecido pela função acima e entra em um caso
// se o comando não entrar em nada ele vai para o default
char way(int decision){
    switch (decision){
        case 0:
            printf("\n\n frente - para andar para frente\n"
                   " --ajuda - para ver a lista de comandos"
            );
            break;
        case 1:
            printf("Você andou para frente e ");
            randomRooms(randomNum(1, 2));
            break;
        default:
            printf("Comando inválido. Digite um comando válido ou --ajuda caso precise de ver a lista de comandos.\n\n");
            break;
    }
    return 0;
}