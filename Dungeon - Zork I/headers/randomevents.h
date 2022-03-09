#include <stdio.h>
#include <stdlib.h>

//Esse script é voltado as funções de geração de mapa e eventos aleatórios

char randomRooms(int num);
char randomEvent(int num);
int randomNum(int lower, int upper);


// Essa função gera uma "sala" aleatória (pode ser uma sala ou um corredor)
// que recebe um valor int para entrar em uma "sala"
char randomRooms(int num){
    switch (num){
        case 1:
            printf("você se encontrar em uma bifurcação. Você pode seguir pela direita \nou pela esquerda.\n\n");
            break;
        case 2:
            printf("você chega em uma sala ");
            randomEvent(randomNum(1, 2)); // Aqui ele está chamando a função de eventos aleatórios
                                          // e para gerar a aleatoriedade ele chama o função de numeros aleatórios
            break;
        default:
            break;
    }
    return 0;
}

// Essa função como foi citado antes é a função de eventos aleatórios
// que recebe um valor int para entrar em um evento
char randomEvent(int num){
    switch (num){
        case 1:
            printf("e nela você pode observar um bau no canto direito da sala\n\n");
            break;
        case 2:
            printf("e encontra um esqueleto\n\n");
            break;
        default:
            break;
    }
    return 0;
}

// Essa função como foi citado antes é a função de numeros aleatórios
// que recebe dois valor int como os limites para gerar o numero aleatório
int randomNum(int lower, int upper){
    int i;
    int num;

    for (i = 0; i < 1; i++){
        num = (rand() %(upper - lower + 1)) + lower;
    }

    return num;
}