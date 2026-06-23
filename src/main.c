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
                        printf("------------------------------\n");
                        imprimirtabuleiro(tabuleiro);
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
                        printf("------------------------------\n");
                        imprimirtabuleiro(tabuleiro);
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

int processarTiro(int tabuleiroNavios[TAMANHO][TAMANHO], int tabuleiroTiros[TAMANHO][TAMANHO], int linha, int coluna)
{

    if (tabuleiroNavios[linha][coluna] == NAVIO)
    {
        tabuleiroTiros[linha][coluna] = TIRO_ACERTO;
        return 1;
    }
    else
    {
        tabuleiroTiros[linha][coluna] = TIRO_AGUA;
        return 0;
    }
}

void lerTiro(int tabuleiroTiros[TAMANHO][TAMANHO], int *linha, int *coluna)
{
    int valido;

    do
    {
        valido = 1;

        printf("Digite linha e coluna do tiro: ");
        scanf("%d %d", linha, coluna);

        if (*linha < 0 || *linha >= TAMANHO || *coluna < 0 || *coluna >= TAMANHO)
        {
            printf("ERRO: Posição fora do tabuleiro!\n");
            valido = 0;
        }
        else if (tabuleiroTiros[*linha][*coluna] != AGUA)
        {
            printf("ERRO: Você já atirou nessa posição!\n");
            valido = 0;
        }
    } while (!valido);
}

int aindaTemNavios(int tabuleiro[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            if (tabuleiro[i][j] == NAVIO)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int linha, coluna;
    int resultado;

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

    imprimirtabuleiro(tabuleiroJogador2);
    posicionarNavios(tabuleiroJogador2);

    do
    {
        printf("JOGADOR 1:\n\n");
        imprimirtabuleiro(tirosJogador1);
        lerTiro(tirosJogador1, &linha, &coluna);

        resultado = processarTiro(tabuleiroJogador2, tirosJogador1, linha, coluna);

        if (resultado)
            printf("Acertou!\n");
        else
            printf("Água!\n");

        if (!aindaTemNavios(tabuleiroJogador2))
        {
            printf("Jogador 1 venceu!\n");
            break;
        }

        printf("JOGADOR 2:\n\n");
        imprimirtabuleiro(tirosJogador2);
        lerTiro(tirosJogador2, &linha, &coluna);

        resultado = processarTiro(tabuleiroJogador1, tirosJogador2, linha, coluna);

        if (resultado)
            printf("Acertou!\n");
        else
            printf("Água!\n");

        if (!aindaTemNavios(tabuleiroJogador1))
        {
            printf("Jogador 2 venceu!\n");
            break;
        }

    } while (1);

    return 0;
}