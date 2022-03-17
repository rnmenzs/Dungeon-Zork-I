typedef struct player {
    char name[50];
    int alive;
    int moves;
    int hp;
    int attack1;
    int attack2;
    int attack3;
    int attack4;
    int CA;
}player;

typedef struct enemy{
    int hp;
    int damage;
    int CA;
}enemy;

player jogador;
enemy inimigo;


