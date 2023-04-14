#include <stdio.h>

int main()
{
    double M[12][12];
    int i, j, contador = 0;
    double soma = 0.0;

    char operacao[1];

    scanf("%s", &operacao);

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            scanf("%lf", &M[i][j]);
        }
    }

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (j < i)
            {
                soma += M[i][j];
                contador += 1;
            }
        }
    }

    if (operacao[0] == 'S')
    {
        printf("%.1f\n", soma);
    }
    else if (operacao[0] == 'M')
    {
        printf("%.1f\n", soma / contador);
    }

    return 0;
}