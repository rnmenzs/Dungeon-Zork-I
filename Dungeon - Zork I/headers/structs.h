

typedef struct player {
    char name[50];
    int alive;
    struct attack{
        int damage;
    }ataque1, ataque2;
    int hp;
    int CA;
}player;

typedef struct enemy{
    int hp;
    struct attackEnemy{
        char name [50];
        char description[50];
        int damage;
    }ataque1, ataque2;
    int CA;
}enemy;


player jogador;
enemy inimigo;


