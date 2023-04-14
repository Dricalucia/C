#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, j;

    while (scanf("%d %d", &N, &M) != EOF)
    {
        // Primeiro, criando a matriz com ponteiros
        int **matriz = (int **)calloc(N, sizeof(int *));

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
                    // verifica se a célula da esquerda existe
                    if (j > 0)
                    {
                        soma += matriz[i][j - 1];
                    }
                    // verifica se a célula da direita existe
                    if (j < M - 1)
                    {
                        soma += matriz[i][j + 1];
                    }
                    // verifica se a célula de acima existe
                    if (i > 0)
                    {
                        soma += matriz[i - 1][j];
                    }
                    // verifica se a célula abaixo existe
                    if (i < N - 1)
                    {
                        soma += matriz[i + 1][j];
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
