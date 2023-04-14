#include <stdio.h>

int main()
{

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */

    int id, horas;
    float valor;
    float salario;

    scanf("%i", &id);
    scanf("%i", &horas);
    scanf("%f", &valor);

    salario = horas * valor;
    printf("NUMBER = %d\n", id);
    printf("SALARY = U$ %.2f\n", salario);

    return 0;
}