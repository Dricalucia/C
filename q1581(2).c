#include <stdio.h>
#include <string.h>

int main()
{
    int N, K, i, j, ingles, x;
    char idiomaNativo[21], idiomaConversa[21], idioma;

    // n° casos de testes
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        //  n° de pessoas por teste
        scanf("%d", &K);
        ingles = 0;

        for (j = 0; j < K; j++)
        {
            idioma = getchar();
            while (idioma != '\n')
            {
                idiomaNativo[i] = idioma;
                x++;
                idioma = getchar();
            }
            idiomaNativo[i] = '\0';
            printf("idiomaN: %s\n", idiomaNativo);

            if (j == 0)
            {
                printf("j == 0\n");
                strcpy(idiomaConversa, idiomaNativo);
            }
            else
            {
                printf("j > 0\n");
                if (strcmp(idiomaNativo, idiomaConversa) != 0)
                {
                    ingles += 1;
                }
            }
        }
        if (ingles == 1)
        {
            printf("ingles\n");
        }
        else
        {
            puts(idiomaConversa);
        }
    }
}