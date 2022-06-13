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
void enemyMovement();
void statusBar(player jogador);

int battle = 0;
int lastRoom = -1;
int moves = 0;

void statusBar(player jogador)
{
    printf("\x1b[2;30;47mHP: %i   Nome: %s   Movimentos: %i\x1b[0m \n\n", jogador.hp, jogador.name, moves);
}

void way(int decision)
{
    switch (decision)
    {
    case 0:
        printf("\n\n --ajuda - para ver a lista de comandos\n"
               " frente - para andar para frente\n"
               " direita - para andar para direita\n"
               " esquerda - para andar para esquerda\n\n");
        break;
    case 1:
        printf("Você segue o caminho a sua frente ");
        randomRooms(randomInt(1, 2));
        moves++;
        break;
    case 2:
        printf("Você segue o caminho da direita ");
        randomRooms(randomInt(1, 2));
        moves++;
        break;
    case 3:
        printf("Você segue o caminho da esquerda ");
        randomRooms(randomInt(1, 2));
        moves++;
        break;
    default:
        printf("Comando inválido. Digite um comando válido ou --ajuda caso precise de ver a lista de comandos.\n\n");
        break;
    }
}

void defaultCommandValidator(char text[])
{
    int comandoValido;
    do
    {
        if (lastRoom == 1 && strcmp("frente", text) == 0)
        {
            printf("Você deu de cara com a parede.\nQue tal tentar ir para direita ou para esquerda\n");
            getCommand(text);
            comandoValido = 0;
        }
        else
        {
            comandoValido = 1;
        }

    } while (comandoValido != 1);

    way(defaultCommand(text));
}

void combatWay(int decision)
{
    int hitRate;
    switch (decision)
    {
    case 0:
        printf("\n\n --ajuda - para ver a lista de comandos\n"
               " attack 1 - para usar o ataque 'Cortar'\n"
               " attack 2 - para usar o ataque 'Estocar'\n\n");
        break;
    case 1:
        hitRate = randomInt(1, 20);
        printf("Você vai em direção ao inimigo, levantando sua espada\npara desferir um corte lateral\n");
        if (hitRate >= inimigo.CA)
        {
            jogador.ataque1.damage = randomInt(1, 4);
            inimigo.hp -= jogador.ataque1.damage;
            printf("Acertou!!! Dano: %i, Hp do Inimigo: %i\n", jogador.ataque1.damage, inimigo.hp);
        }
        else
        {
            printf("e você errou o ataque.\n");
        }

        break;
    case 2:
        printf("Você corre em direção ao oponente, se preparando para a estocada\n");
        hitRate = randomInt(1, 20);
        if (hitRate >= inimigo.CA)
        {
            jogador.ataque2.damage = randomInt(1, 6);
            inimigo.hp -= jogador.ataque2.damage;
            printf("Acertou!!! Dano: %i, Hp do Inimigo: %i\n", jogador.ataque2.damage, inimigo.hp);
        }
        else
        {
            printf("e você errou o ataque.\n");
        }

        break;
    default:
        printf("Comando inválido. Digite um comando válido ou --ajuda caso precise de ver a lista de comandos.\n\n");
        break;
    }
}

void combat()
{
    char comando[50];
    int fighting = 1;


    do
    {

       

        if (jogador.hp <= 0)
        {
            fighting = 0;
            jogador.alive = 0;
        }
        

        if (fighting != 0)
        {
            getCombatCommand(comando);
            combatWay(combatCommand(comando));
            
            if (inimigo.hp > 0 && (combatCommand(comando) != -1 || combatCommand(comando) != 0))
            {
                enemyMovement(1);
            } else {
                printf("\n You win the combat\n"); 
                fighting = 0;
            }         
            statusBar(jogador);
        }
        
    } while (fighting != 0);

    battle = 0;
}

void enemyMovement(int decision)
{
    int hitRate;
    switch (decision)
    {
    case 1:
        hitRate = randomInt(1, 20);

        if (hitRate >= jogador.CA)
        {
            inimigo.ataque1.damage = randomInt(1, 5);
            jogador.hp -= inimigo.ataque1.damage;
            printf("\nO inimigo corre em sua direção e \nAcertou! Dano: %i\n", inimigo.ataque1.damage);
        } else {
            printf("\nO inimigo tenta te acertar com um golpe, porém erra.\n");
        }
            break;
        default:
            break;
    }
}

int randomInt(int lower, int upper)
{
    int num;

    num = (rand() % (upper - lower + 1)) + lower;

    return num;
}

void randomRooms(int num)
{
    switch (num)
    {
    case 1:
        printf("Você se encontrar em uma bifurcação. Você pode seguir pela direita \nou pela esquerda.\n\n");
        randomEvent(randomInt(-1, 0));
        lastRoom = 1;
        break;
    case 2:
        lastRoom = -1;
        printf("Você chega em uma sala ");
        randomEvent(randomInt(0, 2));
        break;
    default:
        break;
    }
}

void randomEvent(int num)
{
    switch (num)
    {

    case 0:
        printf("e encontra um esqueleto\n\n");
        inimigo.hp = 10;
        inimigo.CA = 10;
        battle = 1;
        break;
    case 1:
        printf("e nela você pode observar algumas pilhas de ossos\n\n");
        break;
    case 2:
        printf("e nela você pode observar alguns baús que já foram saqueados\nBoa sorte na proxima.\n\n");
        break;
    default:
        break;
    }
}
