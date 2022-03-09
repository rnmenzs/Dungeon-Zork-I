#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "./headers/command.h"

#define ENTER 13

int main(){
    setlocale(LC_ALL, "Portuguese");

    char comando[50];

    system("cls");
    getCommand(comando);
    way(decision(comando));
}
