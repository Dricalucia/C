#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k;
    int G, A, M, C;

    scanf("%d %d %d %d", &G, &A, &M, &C);

    int tabelaR[G][A];
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < A; j++)
        {
            scanf("%d", &tabelaR[i][j]);
        }
    }

    int tabelaS[A][M];
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &tabelaS[i][j]);
        }
    }

    int tabelaT[M][C];
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < C; j++)
        {
            scanf("%d", &tabelaT[i][j]);
        }
    }
    printf("\n");

    int tabelaAux[G][M];
    for (int i = 0; i < G; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tabelaAux[i][j] = 0;
            for (int k = 0; k < A; k++)
            {
                tabelaAux[i][j] += tabelaR[i][k] * tabelaS[k][j];
            }
        }
    }

    int tabelaResult[G][C];
    for (int i = 0; i < G; i++)
    {
        for (int j = 0; j < C; j++)
        {
            tabelaResult[i][j] = 0;
            for (int k = 0; k < M; k++)
            {
                tabelaResult[i][j] += tabelaAux[i][k] * tabelaT[k][j];
            }
        }
    }

    // o tamanho do vetor sera a mesma qtde da matriz resultado
    // Ira comparar cada coluna para identificar o maior valor e inserir no vtor

    int maiorNumero[C];
    for (int j = 0; j < C; j++)
    {
        for (int i = 0; i < G; i++)
        {
            if (tabelaResult[i][j] > maiorNumero[j])
            {
                maiorNumero[j] = tabelaResult[i][j];
            }
        }
    }

    int ybase10;

    for (i = 0; i < G; i++)
    {
        for (j = 0; j < C; j++)
        {
            ybase10 = (int)log10(maiorNumero[j] + 1);

            if (j == 0)
            {
                printf("%*d", ybase10, tabelaResult[i][j]);
            }
            else
            {
                printf(" %*d", ybase10, tabelaResult[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}