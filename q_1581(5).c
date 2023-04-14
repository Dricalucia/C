#include <stdio.h>
#include <string.h>

int main()
{
    int N, K, i, j, ingles;
    char idioma[21], idiomaNativo[21], idiomaConversa[21];

    // n° casos de testes
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {

        // n° de pessoas por teste
        scanf("%d", &K);

        strcpy(idiomaConversa, "");
        // scanf("%*[^\n]c", idiomaNativo);
        ingles = 1;

        // fgets(idiomaNativo, 21, stdin);

        for (j = 1; j < K; j++)
        {
            scanf("%*[^\n]c", idiomaNativo);
            // fgets(idiomaNativo, 21, stdin);
            if (strcmp(idioma, idiomaConversa))
            {
                ingles = 0;
            }
        }

        if (ingles == 1)
        {
            printf("ingles\n");
        }
        else
        {
            printf("%s \n", idiomaNativo);
        }
    }
}
