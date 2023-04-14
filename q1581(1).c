#include <stdio.h>
#include <string.h>

int main()
{
    int N, K, i, j, x;
    char idiomaNativo[21], idiomaConversa[21];

    // n° casos de testes
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        // n° de pessoas por teste
        scanf("%d", &K);
        strcpy(idiomaConversa, "");
        scanf("%s", idiomaNativo);

        // fgets(idiomaNativo, 21, stdin);

        for (j = 0; j < K; j++)
        {
            if (j == 0)
            {
                strcpy(idiomaConversa, idiomaNativo);
            }
            else
            {
                if (strcmp(idiomaNativo, idiomaConversa) == 0)
                {
                    strcpy(idiomaConversa, idiomaNativo);
                }
                else
                {
                    strcpy(idiomaConversa, "ingles");
                }
                fgets(idiomaNativo, 21, stdin);
            }
        }
        printf("%s \n", idiomaConversa);
    }
}