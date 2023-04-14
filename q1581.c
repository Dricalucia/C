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
        strcpy(idiomaConversa, "");
        ingles = 0;

        for (j = 0; j < K; j++)
        {
            scanf("%s", idiomaNativo);
            if (j == 0)
            {
                strcpy(idiomaConversa, idiomaNativo);
            }
            else
            {
                if (strcmp(idiomaNativo, idiomaConversa) != 0)
                {
                    ingles = 1;
                }
            }
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
