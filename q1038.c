#include <stdio.h>

int main()
{

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */

    int codigo, quantidade;
    float valorConta;

    scanf("%i", &codigo);
    scanf("%i", &quantidade);

    if (codigo == 1)
    {
        valorConta = quantidade * 4.00;
    }
    else if (codigo == 2)
    {
        valorConta = quantidade * 4.50;
    }
    else if (codigo == 3)
    {
        valorConta = quantidade * 5.00;
    }
    else if (codigo == 4)
    {
        valorConta = quantidade * 2.00;
    }
    else
    {
        valorConta = quantidade * 1.50;
    }

    printf("Total: R$ %.2f\n", valorConta);

    return 0;
}