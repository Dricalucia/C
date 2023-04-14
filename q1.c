#include <stdio.h>

/*
Escreva um algoritmo para mostrar na tela se cada número N,
digitado pelo usuário é par ou ímpar. O algoritmo também deverá
mostrar na tela a soma de todos os números pares, a soma de todos os números ímpares,
a porcentagem de números pares e a porcentagem de números ímpares digitados.
O algoritmo deverá encerrar sua execução caso o usuário digite um número menor que zero.
*/

int main()
{

    int N;
    int somapar = 0;
    int somaimpar = 0;
    float porcentagemi = 1;
    float porcentagemp = 1;

    do
    {
        printf("\n Digite um número qualquer: ");
        scanf("%d", &N);

        if (N % 2 == 0)
        {
            printf("\n Número escolhido é par!");
            somapar += N;
        }

        else
        {
            printf("\n Número escolhido é ímpar");
            somaimpar += N;
        }

        printf("\n Soma total de ímpares é %d e soma total de pares é %d\n", somaimpar, somapar);

        porcentagemp = (somapar / (somapar + somaimpar)) * 100;
        porcentagemi = (somaimpar / (somapar + somaimpar)) * 100;

        printf("\n Porcentagem de pares é: %f", porcentagemp);
        printf("\n Porcentagem de ímpares é: %f\n", porcentagemi);

    } while (N >= 0);

    return 0;
}