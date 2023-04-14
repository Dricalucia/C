int main()
{

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
    int X, Y, i, soma = 0;
    printf("Digite o valor de X \n");
    scanf("%d", &X);
    printf("Digite o valor de Y \n");
    scanf("%d", &Y);

    if (Y < X)
    {
        for (i = (X - 1); i > Y; i--)
        {
            if (i % 2 != 0)
            {
                soma += i;
            }
        }
    }
    else
    {
        for (i = (X + 1); i < Y; i++)
        {
            if (i % 2 != 0)
            {
                soma += i;
            }
        }
    }
    printf("soma %d \n", soma);
    return 0;
}