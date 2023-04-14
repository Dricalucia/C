#include <stdio.h>
#include <string.h>

int main()
{
    int N, K, i, j, ingles;
    char idiomaNativo[21], idiomaConversa[21];
    unsigned long int tam;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &K);
        strcpy(idiomaConversa, "");

        scanf("%s", idiomaNativo);
        // fgets(idiomaNativo, 21, stdin);

        tam = strlen(idiomaNativo);
        ingles = 0;
        printf("%lu \n", tam);

        for (j = 0; j < K; j++)
        {
            if (strcmp(idiomaNativo, idiomaConversa) != 0)
            {
                ingles = 1;
            }
            else
            {
                strcpy(idiomaConversa, idiomaNativo);
            }
            scanf(" %s", idiomaNativo);
        }

        if (ingles == 1)
        {
            printf("ingles\n");
        }
        else
        {
            printf("%s\n", idiomaConversa);
        }
    }
}
