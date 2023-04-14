#include <stdio.h>
#include <string.h>

int main()
{

    int N, K;
    scanf("%d", &N);
    char idioma[20], idioma_anterior[20], idioma_falado[20];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &K);
        strcpy(idioma_falado, "");

        for (int l = 0; l < K; l++)
        {
            scanf("%s", idioma);
            // fgets(idioma, 20, stdin);

            if (strcmp(idioma_falado, "ingles") != 0)
            {
                // ao menos um inglês = inglês
                if (strcmp(idioma, "ingles") == 0)
                {
                    strcpy(idioma_falado, "ingles");
                }

                // if (l > 0)
                //{
                //  ao menos um diferente = inglês
                if (strcmp(idioma_anterior, idioma) != 0)
                {
                    strcpy(idioma_falado, "ingles");
                }
                // todos iguais = iguais
                if (strcmp(idioma_anterior, idioma) == 0)
                {
                    strcpy(idioma_falado, idioma);
                }
                //}
            }

            strcpy(idioma_anterior, idioma);
        }
        puts(idioma_falado);
    }

    return 0;
}