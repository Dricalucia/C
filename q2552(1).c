#include <stdio.h>
#include <stdlib.h>

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
                        if (matriz[i][j + 1] == 1)
                        {
                            soma += 1;
                        }
                        if (matriz[i + 1][j] == 1)
                        {
                            soma += 1;
                        }
                    }
                    else if (i == 0 && (j > 0 && j < M - 1))
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
                    else if (i == N && (j > 0 || j == M))
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
                    else if ((i > 0 && i < N - 1) && (j == 0 && j < M - 1))
                    {
                        if (matriz[i][j + 1] == 1)
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
                    else
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