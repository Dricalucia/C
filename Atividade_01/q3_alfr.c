#include <stdio.h>
int main()
{
    int i, j, k, N, meioM, inicio, fim;
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

        for (k = 1; k <= meioM; k++)
        {
            for (i = inicio; i <= fim; i++)
            {
                for (j = inicio; j <= fim; j++)
                {
                    M[i][j] = k;
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
}