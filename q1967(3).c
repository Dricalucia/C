#include <stdio.h>

int main()
{
    int i, j, k;
    int G, A, M, C;

    scanf("%d %d %d %d", &G, &A, &M, &C);
    printf("\n");

    int tabelaR[G][A];
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < A; j++)
        {
            scanf("%d", &tabelaR[i][j]);
        }
    }
    printf("\n");

    int tabelaS[A][M];
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &tabelaS[i][j]);
        }
    }
    printf("\n");

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
    int tabContCaracter[G][C];
    int localizacao[2];

    int maior = 0, cont, check = 0;
    for (int i = 0; i < G; i++)
    {
        for (int j = 0; j < C; j++)
        {
            tabelaResult[i][j] = 0;
            for (int k = 0; k < M; k++)
            {
                tabelaResult[i][j] += tabelaAux[i][k] * tabelaT[k][j];
                if (tabelaResult[i][j] > maior)
                {
                    maior = tabelaResult[i][j];
                    localizacao[0] = i;
                    localizacao[1] = j;
                }

                cont = 0;
                check = tabelaResult[i][j];
                while (check != 0)
                {
                    check = check / 10;
                    cont += 1;
                }
                tabContCaracter[i][j] = cont;
            }
        }
    }

    int tamanhoNr, contar, difer;
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < C; j++)
        {
            difer = (tabContCaracter[G][C] - tabContCaracter[localizacao[0]][localizacao[1]]);

            if (j == 0)
            {
                printf("%*d", difer, tabelaResult[i][j]);
            }
            else
            {
                printf(" %*d", difer, tabelaResult[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}