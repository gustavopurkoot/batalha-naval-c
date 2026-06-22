#include <stdio.h>
#define TAMANHO 10
#define AGUA 0
#define NAVIO 1
#define TIRO_AGUA 1
#define TIRO_ACERTO 2

void imprimirtabuleiro(int tabuleiro1[TAMANHO][TAMANHO])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro1[i][j]);
        }
        printf("\n");
    }
}

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO])
{
    int tamanhosNavios[5] = {5, 4, 3, 3, 2};
    int quantidadeNavios = sizeof(tamanhosNavios) / sizeof(tamanhosNavios[0]); 

    for(int i = 0; i <quantidadeNavios; i++){
        int linha, coluna;
        char orientacao;

        printf("Digite a linha para o navio de tamanho %d: ", tamanhosNavios[i]);
        scanf("%d", &linha);

        printf("Digite a coluna para o navio de tamanho %d: ", tamanhosNavios[i]);
        scanf("%d", &coluna);

        printf("Digite a orientação (H para horizontal, V para vertical): ");
        scanf(" %c", &orientacao);
    }
}


int main()
{
    int tabuleiroJogador1[TAMANHO][TAMANHO];
    int tirosJogador1[TAMANHO][TAMANHO];

    int tabuleiroJogador2[TAMANHO][TAMANHO];
    int tirosJogador2[TAMANHO][TAMANHO];

    inicializarTabuleiro(tabuleiroJogador1);
    inicializarTabuleiro(tirosJogador1);
    inicializarTabuleiro(tabuleiroJogador2);
    inicializarTabuleiro(tirosJogador2);

    imprimirtabuleiro(tabuleiroJogador1);
    

    return 0;
}