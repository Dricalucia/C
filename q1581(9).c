#include <stdio.h>
#include <string.h>

int main()
{
    int N, K, i, j, idioma;
    char idiomaNativo[21], idiomaConversa[21];

    // n° casos de testes
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        //  n° de pessoas por teste
        scanf("%d", &K);

        // fgets(idiomaNativo, 21, stdin);
        scanf("%*[^\n]c", &idiomaNativo);

        strcpy(idiomaConversa, idiomaNativo);

        idioma = 0;
        j = 0;

        while ((idiomaNativo[j] != '\n') || (j < 21))
        {
            if (strcmp(idiomaNativo, idiomaConversa) != 0)
            {
                idioma += 1;
            }
            scanf("%*[^\n]c", &idiomaNativo);
            // fgets(idiomaNativo, 21, stdin);
            j += 1;
        }

        if (idioma == 1)
        {
            printf("ingles\n");
        }
        else
        {
            printf("%s\n", idiomaConversa);
        }
    }
}