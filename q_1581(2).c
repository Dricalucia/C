#include <stdio.h>
#include <string.h>

int main()
{
    int N, K, i, j, ingles;
    char idiomaNativo[21], idiomaConversa[21];

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &K);

        // scanf("%*[^\n]%*c");
        //%*[^\n]verifica tudo até um \n
        // scanf(" %s", atual);
        scanf("%s", idiomaNativo);

        ingles = 0;

        for (j = 0; j < K; j++)
        {
            if (j == 0)
            {
                strcpy(idiomaConversa, idiomaNativo);
            }
            else
            {
                if (strcmp(idiomaNativo, idiomaConversa) != 0 && ingles == 0)
                {
                    strcpy(idiomaConversa, idiomaNativo);
                    // ingles = 1;
                }
                else
                {
                    strcpy(idiomaConversa, idiomaNativo);
                }
            }
            scanf(" %s", idiomaNativo);
        }
        puts(idiomaConversa);

        /*
        if (ingles == 1)
        {
            printf("ingles\n");
        }
        else
        {
            printf("%s\n", idiomaConversa);
        }
        */
    }
}
