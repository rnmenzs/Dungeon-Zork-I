#include <stdio.h>
#include <stdlib.h>

//Esse script é voltado as funções de comandos

void getCommand(char text[]);
int defaultCommand(char text[]);

// Essa função está pegando o que foi digitado e armazenando na variavel do tipo char
void getCommand(char text[]){
    gets(text);
}

// essa função pega o valor char que foi armazenado e verifica se entra em algum comando
// para passar para a função way
int defaultCommand(char text[]){
    if ( strcmp("--ajuda", text) == 0){
        return 0;
    }
 
    if ( strcmp("frente", text) == 0){
        return 1;
    }

    if ( strcmp("direita", text) == 0){
        return 2;
    }

    if ( strcmp("esquerda", text) == 0){
        return 3;
    }
    return -1;
}

// essa função pega o valor fornecido pela função acima e entra em um caso
// se o comando não entrar em nada ele vai para o default
