#include <stdio.h>
#include <string.h>

int main()
{
    int N, K, i, j;
    char idiomaNativo[21], idiomaConversa[21];
    // char idioma;
    // size_t tam;

    // n° casos de testes
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        // n° de pessoas por teste
        scanf("%d", &K);
        strcpy(idiomaConversa, "");

        for (j = 0; j < K; j++)
        {
            // scanf("%s\n", &idioma);
            fgets(idiomaNativo, 21, stdin);

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
            }
                }
        printf("%s\n", idiomaConversa);
    }
}