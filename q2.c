#include <stdio.h>

/*
Codifique, compile e execute um programa em C que receba o salário-base
de um funcionário, calcule e mostre o salário a receber, sabendo-se que
esse funcionário tem gratificação de 5% sobre o salário-base, e paga
imposto de 7% sobre o salário-base.
*/

int main()
{
    float salario, s1, s2, final;

    printf("Digite o salario: ");
    scanf("%f", &salario);

    s1 = (salario * 0.07) / 100;
    s2 = (salario * 0.05) / 100;
    final = s2 - s1;

    printf("O salario com desconto: %f", final);

    return 0;
}