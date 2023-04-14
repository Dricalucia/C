#include <stdio.h>

int main()
{
    int i, j, k;
    int G, A, M, C;
    float soma;

    scanf("%d %d %d %d", &G, &A, &M, &C);

    printf("\n");
    // TABELA 1
    int tabelaR[G][A];
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < A; j++)
        {
            scanf("%d", &tabelaR[i][j]);
        }
    }

    printf("\n");
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < A; j++)
        {
            printf("%d\t", tabelaR[i][j]);
        }
        printf("\n");
    }

    // TABELA 2
    int tabelaS[A][M];
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &tabelaS[i][j]);
        }
    }

    for (i = 0; i < A; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d\t", tabelaS[i][j]);
        }
        printf("\n");
    }

    // TABELA 3
    int tabelaT[M][C];
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < C; j++)
        {
            scanf("%d", &tabelaT[i][j]);
        }
    }

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("%d\t", tabelaT[i][j]);
        }
        printf("\n");
    }

    // AUX = R x S
    // A matriz tera a mesma qtde linhas da 1a tabela e a mesma qtd colunas da 2 tabela

    int tabelaAux[G][M]; // Qtd linhas 1a tabela e qtd colunas da 2a tabela
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

    printf("\n");
    printf("Tabela Auxiliar \n");
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d\t", tabelaAux[i][j]);
        }
        printf("\n");
    }

    // MATRIZ Resultado
    // Esta matriz irá realizar a operação da matrix aulixar com a segunda matriz

    int tabelaResult[G][C]; // Qtd linhas 1a tabela e qtd colunas da 2a tabela
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

    // achar o maior valor da matriz
    int maior = 0;
    int li = 0, cj = 0, cont = 0;
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (tabelaResult[i][j] > maior)
            {
                maior = tabelaResult[i][j];
                while (maior != 0)
                {
                    maior = maior / 10;
                    cont += 1;
                }
            }
        }
    }

    int tamanhoNr, contar, difer;

    printf("\n");
    printf("Tabela Resultado \n");
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < C; j++)
        {
            contar = 0;
            tamanhoNr = tabelaResult[i][j];
            while (tamanhoNr != 0)
            {
                tamanhoNr = tamanhoNr / 10;
                contar += 1;
            }
            difer = contar - cont;
            // difer += 1;
            printf("%*d", difer, tabelaResult[i][j]);
        }
        printf("\n");
    }
}
