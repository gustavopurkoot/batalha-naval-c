#include <stdio.h>
#define TAMANHO 10
#define AGUA 0
#define NAVIO 1
#define TIRO_AGUA 2
#define TIRO_ACERTO 3

void imprimirtabuleiro(int tabuleiro1[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            printf("%d ", tabuleiro1[i][j]);
        }
        printf("\n");
    }
}

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO])
{
    int tamanhosNavios[5] = {5, 4, 3, 3, 2};
    int quantidadeNavios = sizeof(tamanhosNavios) / sizeof(tamanhosNavios[0]);

    for (int i = 0; i < quantidadeNavios; i++)
    {
        int linha, coluna;
        char orientacao;
        int valido;

        do
        {
            valido = 1;

            printf("Digite a linha para o navio de tamanho %d: ", tamanhosNavios[i]);
            scanf("%d", &linha);

            printf("Digite a coluna para o navio de tamanho %d: ", tamanhosNavios[i]);
            scanf("%d", &coluna);

            printf("Digite a orientação (V para vertical, H para horizontal): ");
            scanf(" %c", &orientacao);

            if (linha < 0 || linha >= TAMANHO ||
                coluna < 0 || coluna >= TAMANHO)
            {
                printf("ERRO: Posição inválida!\n");
                valido = 0;
                continue;
            }

            if (orientacao == 'V')
            {
                if (linha + tamanhosNavios[i] > TAMANHO)
                {
                    printf("ERRO: Navio ultrapassa tabuleiro!\n");
                    valido = 0;
                }
                if (valido)
                {
                    for (int k = 0; k < tamanhosNavios[i]; k++)
                    {
                        if (tabuleiro[linha + k][coluna] == NAVIO)
                        {
                            printf("ERRO: Posição já ocupada por outro navio!\n");
                            valido = 0;
                            break;
                        }
                    }
                }
                if (valido)
                {
                    for (int k = 0; k < tamanhosNavios[i]; k++)
                    {
                        tabuleiro[linha + k][coluna] = NAVIO;
                    }
                }
            }
            else if (orientacao == 'H')
            {
                if (coluna + tamanhosNavios[i] > TAMANHO)
                {
                    printf("ERRO: Navio ultrapassa tabuleiro!\n");
                    valido = 0;
                }
                if (valido)
                {
                    for (int k = 0; k < tamanhosNavios[i]; k++)
                    {
                        if (tabuleiro[linha][coluna + k] == NAVIO)
                        {
                            printf("ERRO: Posição já ocupada por outro navio!\n");
                            valido = 0;
                            break;
                        }
                    }
                }
                if (valido)
                {
                    for (int k = 0; k < tamanhosNavios[i]; k++)
                    {
                        tabuleiro[linha][coluna + k] = NAVIO;
                    }
                }
            }
            else
            {
                printf("Opção Inválida!");
                valido = 0;
            }
        } while (!valido);
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
    posicionarNavios(tabuleiroJogador1);
    imprimirtabuleiro(tabuleiroJogador1);

    imprimirtabuleiro(tabuleiroJogador2);
    posicionarNavios(tabuleiroJogador2);
    imprimirtabuleiro(tabuleiroJogador2);

    

    return 0;
}