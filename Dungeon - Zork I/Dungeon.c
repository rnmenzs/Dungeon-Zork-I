#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "./headers/command.h"


int main(){
    setlocale(LC_ALL, "Portuguese");

    int alive = 1;
    char comando[50];

    system("cls");

    do{
        //aqui armazena o que foi digitado na cariavel char
        getCommand(comando);
        //aqui pega o valor do char, checa na função decision que por fim retorna o caminho para o função way
        way(decision(comando));
    } while ( alive != 0 );

    return 0;
}
