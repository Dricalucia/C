#include <stdio.h>

int rafael(int x, int y);
int beto(int x, int y);
int carlos(int x, int y);

int main()
{

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */

    int N, i, x, y;
    int calcRafael, calcBeto, calcCarlos;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);

        calcRafael = rafael(x, y);
        calcBeto = beto(x, y);
        calcCarlos = carlos(x, y);

        if (calcRafael > calcBeto && calcRafael > calcCarlos)
        {
            printf("Rafael ganhou\n");
        }
        else if (calcBeto > calcRafael && calcBeto > calcCarlos)
        {
            printf("Beto ganhou\n");
        }
        else
        {
            printf("Carlos ganhou\n");
        }
    }
    return 0;
}

int rafael(int x, int y)
{
    int calculoR = 0;
    calculoR = (3 * x) * (3 * x) + (y * y); // a função math pow() p/ potencia

    return calculoR;
}

int beto(int x, int y)
{
    int calculoB = 0;
    calculoB = 2 * (x * x) + (5 * y) * (5 * y);

    return calculoB;
}

int carlos(int x, int y)
{
    int calculoC = 0;
    calculoC = -100 * x + (y * y * y);

    return calculoC;
}