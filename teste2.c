#include <stdio.h>
int main()
{
    int i, j, l, N, meioM, inicio, fim;
    scanf("%d", &N);
    while (N != 0)
    {
        if (N == 0)
            break;

        int M[N][N];

        meioM = N / 2;

        if (N % 2 == 1)
        {
            meioM++;
        }

        inicio = 0;
        fim = N - 1;

        for (l = 1; l <= meioM; l++)
        {
            for (i = inicio; i <= fim; i++)
            {
                for (j = inicio; j <= fim; j++)
                {
                    M[i][j] = l;
                }
            }

            inicio++;
            fim--;
        }
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (j == 0)
                    printf("%3d", M[i][j]);
                else
                    printf(" %3d", M[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d", &N);
    }
    return 0;

    // operacao matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                C[i][j] = +A[i][k] * B[k][j];
            }
        }
    }
}