#include <stdio.h>

// Exemplo de função simples -

unsigned int potencia(int a, int b);

int main(void)
{

    int a, b;

    printf("Digite 2 números: ");
    scanf("%d %d", &a, &b);
    printf("%d elevado a %d é igual a %u\n", a, b, potencia(a, b));

    return 0;
}

unsigned int potencia(int a, int b)
{
    unsigned int result = 1;

    if (b < 0)
        return -1; // não implementado

    for (int i = 0; i < b; i++)
        result *= a;

    return result;
}