#include <stdio.h>

int main()
{
    int N, i, menorElemento = 1000, posicaoIndice;
    scanf("%d", &N);

    int X[N];

    for (i = 0; i < N; i++)
    {
        scanf("%d", &X[i]);
    }

    for (i = 0; i < N; i++)
    {
        if (X[i] < menorElemento)
        {
            menorElemento = X[i];
            posicaoIndice = i;
        }
    }

    printf("Menor valor: %d\n", menorElemento);
    printf("Posicao: %d\n", posicaoIndice);
}