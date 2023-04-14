#include <stdio.h>
#include <string.h>

int main()
{
    int casos;

    scanf("%d\n", &casos);

    for (int i = 0; i < casos; i++)
    {
        int pessoas;
        scanf("%d\n", &pessoas);
        int contador = 0;
        char idioma[pessoas][22];

        for (int j = 0; j < pessoas; j++)
        {
            scanf("%s", idioma[j]);
        }

        for (int k = 0; k < pessoas - 1; k++)
        {
            if (strcmp(idioma[k], idioma[k + 1]) != 0)
            {
                contador++;
            }
        }

        if (contador > 0)
        {
            printf("ingles\n");
        }
        else
        {
            printf("%s\n", idioma[0]);
        }
    }
}