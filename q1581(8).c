#include <stdio.h>
#include <string.h>

int main()
{
    int N, K, i, j;
    char idiomaNativo[21];

    // n° casos de testes
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        //  n° de pessoas por teste
        scanf("%d", &K);
        // ingles = 0;
        scanf("%s", idiomaNativo);

        for (j = 0; j < 21; j++)
        {
            printf("%c ", idiomaNativo);
        }
        puts(idiomaNativo);
    }
}