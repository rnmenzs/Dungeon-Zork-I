#include <stdio.h>
#include <stdlib.h>
#include "./structs.h"
#include "./commands/defaultCommand.h"
#include "./commands/combatCommand.h"

void randomRooms(int num);
void randomEvent(int num);
int randomInt(int lower, int upper);
void way(int decision);
void combatWay(int decision);
void combat();
void defaultCommandValidator();
void combatCommandValidator(char text[]);

int battle = 0;
int lastRoom = -1;
int countAttack2 = 1;

void way(int decision){    
    switch (decision){
        case 0:
            printf("\n\n frente - para andar para frente\n"
                   " --ajuda - para ver a lista de comandos\n\n"
            );
            break;
        case 1:
            printf("Você segue o caminho a sua frente ");
            randomRooms(randomInt(1, 2));
            break;
        case 2:
            printf("Você segue o caminho da direita ");
            randomRooms(randomInt(1, 2));
            break;
        case 3:
            printf("Você segue o caminho da esquerda ");
            randomRooms(randomInt(1, 2));
            break;
        default:
            printf("Comando inválido. Digite um comando válido ou --ajuda caso precise de ver a lista de comandos.\n\n");
            break;
    }
}

void defaultCommandValidator(char text[]){
    int comandoValido;
    do{
        if (lastRoom == 1 && strcmp("frente", text) == 0){
            printf("Você deu de cara com a parede.\nQue tal tentar ir para direito ou para esqueda");
            getCommand(text);
            comandoValido = 0;
        } else {
            comandoValido = 1;
        }  

    }while (comandoValido != 1);
    
    way(defaultCommand(text));
}

void combatWay(int decision){
    int hitRate;
    switch (decision){
        case 0:
            printf("\n\n attack 1 - para atacar\n"
                   " --ajuda - para ver a lista de comandos\n\n"
            );
            break;
        case 1:
            hitRate = randomInt(1, 20);
            if(hitRate <= inimigo.CA ){
                jogador.attack1 = randomInt(1, 2);
                inimigo.hp -= jogador.attack1;
            } else {
                printf("e você errou o ataque");
            }
            printf("dano: %i, hp inimigo: %i\n", jogador.attack1, inimigo.hp);
            break;
        case 2:
            hitRate = randomInt(1, 20);
            if(hitRate <= inimigo.CA ){
                jogador.attack1 = randomInt(1, 6);
                inimigo.hp -= jogador.attack1;
            } else {
                printf("e você errou o ataque");
            }
            printf("dano: %i, hp inimigo: %i\n", jogador.attack1, inimigo.hp);
            break;
        default:
            printf("Comando inválido. Digite um comando válido ou --ajuda caso precise de ver a lista de comandos.\n\n");
            break;
    }
}

void combat(){
    char comando[50];
    int fighting = 1;

    do {

        if(inimigo.hp <= 0){
            printf("\n You win the combat");
            fighting = 0;
        }
        
        if(jogador.hp <= 0){
            fighting = 0;
        }

        if(fighting != 0){
            getCombatCommand(comando);
            combatCommandValidator(comando);
        }
    } while ( fighting != 0);

    battle = 0;

    return;
}

int randomInt(int lower, int upper){
    int num;
    
    num = (rand() %(upper - lower + 1)) + lower;

    return num;
}

void randomRooms(int num){
    switch (num){
        case 1:
            printf("e você se encontrar em uma bifurcação. Você pode seguir pela direita \nou pela esquerda.\n\n");
            lastRoom = 1;
            break;
        case 2:
            printf("você chega em uma sala ");
            randomEvent(randomInt(1, 2)); 
            break;
        default:
            break;
    }
}

void randomEvent(int num){
    switch (num){
        case 1:
            printf("e nela você pode observar um bau no canto direito da sala\n\n");
            break;
        case 2:
            printf("e encontra um esqueleto\n\n");
            inimigo.damage = randomInt(1, 3);
            inimigo.hp = 10;
            inimigo.CA = 10;
            battle = 1;
            break;
        default:
            break;
    }
}
