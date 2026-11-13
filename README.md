# Dungeon - Zork I

Um jogo de aventura em texto, inspirado em *Zork I*, feito em C para o terminal do Windows. Você explora uma masmorra escolhendo caminhos, encontra salas aleatórias e enfrenta inimigos em combates por turnos com rolagem de dados estilo RPG.

```
==========================================================
=  ====  ====  =========  ================================
...
```

## Como funciona

- **Exploração:** a cada comando você segue por um caminho e cai em um evento aleatório: uma bifurcação, uma sala com ossos, baús já saqueados ou um esqueleto.
- **Bifurcações:** ao chegar em uma, não dá para ir para frente (você bate na parede). É preciso escolher direita ou esquerda.
- **Combate:** ao encontrar um inimigo o jogo entra em modo de batalha. Você e o inimigo se alternam. O ataque acerta se um d20 for maior ou igual à Classe de Armadura (CA) do alvo.
- **Fim de jogo:** quando o HP chega a 0 aparece `You Died`.

### Atributos iniciais

| | HP | CA |
|---|---|---|
| Jogador | 20 | 10 |
| Esqueleto | 10 | 10 |

### Ataques

| Comando | Ataque | Dano |
|---|---|---|
| `ataque 1` | Cortar | 1d4 |
| `ataque 2` | Estocar | 1d6 |

O esqueleto causa 1d5 de dano por golpe.

## Comandos

**Exploração**

| Comando | Ação |
|---|---|
| `frente` | Segue em frente |
| `direita` | Segue pela direita |
| `esquerda` | Segue pela esquerda |
| `--ajuda` | Lista os comandos |

**Combate**

| Comando | Ação |
|---|---|
| `ataque 1` | Corte lateral |
| `ataque 2` | Estocada |
| `--ajuda` | Lista os comandos |

A barra de status mostra seu HP, nome e o número de movimentos.

## Como compilar e jogar

Requisitos: Windows e um compilador C (por exemplo MinGW/GCC), pois o jogo usa `windows.h`.

```bash
cd "Dungeon - Zork I"
gcc Dungeon.c -o Dungeon.exe
./Dungeon.exe
```

Também há um `Dungeon.exe` já compilado na pasta do projeto. Use um terminal com suporte a cores ANSI (Windows Terminal ou Windows 10+).

## Estrutura do projeto

```
Dungeon - Zork I/
├── Dungeon.c                    # main, loop do jogo e banner inicial
└── headers/
    ├── structs.h                # structs do jogador e do inimigo
    ├── events.h                 # salas, eventos aleatórios, combate e status
    └── commands/
        ├── defaultCommand.h     # comandos de exploração
        └── combatCommand.h      # comandos de combate
```

## Autor

[rnmenzs](https://github.com/rnmenzs)
