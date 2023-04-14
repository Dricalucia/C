#include <stdio.h>
#include <stdlib.h>

/*
uma matriz de N linhas e M colunas
Cada célula da matriz contém um pão de queijo ou o número de pães de queijo
que existem nas celulas adjacentes a ela. Uma célula é adjacente a outra se
estiver imediatamente à esquerda, à direita, acima ou abaixo da célula. Note
que, se não contiver um pão de queijo, uma célula deve obrigatoriamente conter
um número entre 0 e 4, inclusive
*/

// int funcao1(int **matriz);

int main()
{
    int N, M, i, j;

    while (scanf("%d %d", &N, &M) != EOF)
    {
        // Primeiro, criando a matriz com ponteiros
        int **matriz = (int **)calloc(N, sizeof(int));

        /* Segundo criar um array de ponteiros para cada linha */
        for (i = 0; i < N; i++)
        {
            matriz[i] = (int *)calloc(M, sizeof(int));
        }

        /* entrada dos dados da matriz */
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }

        /* saída dos dados */

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                /* Se uma posição contém um pão de queijo, imprima 9 para ela */
                if (matriz[i][j] == 1)
                {
                    printf("9");
                }
                else
                {
                    /* imprima o número cuja posição deve conter (contem o n° 9). */
                    int soma = 0;
                    if (i == 0 && j == 0)
                    {
                        // soma += funcao1(**matriz, i, j);
                        if (matriz[i][j + 1] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i + 1][j] == 1)
                        {
                            soma += 1;
                        }
                    }
                    else if (i == 0 && (j > 0 || j == M - 1))
                    {
                        if (matriz[i][j + 1] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i][j - 1] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i + 1][j] == 1)
                        {
                            soma += 1;
                        }
                    }
                    else if (i == N && j == M) // verifica a ultima posição da matriz
                    {
                        if (matriz[i][j - 1] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i - 1][j] == 1)
                        {
                            soma += 1;
                        }
                    }
                    else if (i == N && (j > 0 || j == M - 1))
                    {
                        if (matriz[i - 1][j] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i][j + 1] == 1)
                        {
                            soma += 1;
                        }
                    }
                    else if ((i > 0 || i == N - 1) && (j > 0 || j == M - 1))
                    {
                        if (matriz[i][j - 1] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i - 1][j] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i + 1][j] == 1)
                        {
                            soma += 1;
                        }
                    }
                    else if ((i > 0 && i < N - 1) && (j > 0 && j < M - 1))
                    {
                        if (matriz[i][j + 1] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i][j - 1] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i - 1][j] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i + 1][j] == 1)
                        {
                            soma += 1;
                        }
                    }
                    printf("%d", soma);
                }
            }
            printf("\n");
        }

        /* Libera memoria da matriz*/
        for (i = 0; i < N; i++)
        {
            free(matriz[i]);
        }
        free(matriz);
    }
    return 0;
}

/*
int funcao1(int **matriz, int x, int y)
{
    soma = 0;
    if (matriz[i][j + 1] == 1)
    {
        soma += 1;
    }
    if (matriz[i + 1][j] == 1)
    {
        soma += 1;
    }
    return soma;
}

int funcao2(int **matriz, int x, int y)
{
    int soma = 0;

    if (matriz[x][y + 1] == 1)
    {
        soma += 1;
    }
    if (matriz[x][y - 1] == 1)
    {
        soma += 1;
    }
  return soma;
}
*/