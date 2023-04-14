#include <stdio.h>
#include <string.h>

int main()
{
    int N, K;
    //, i, j;
    // int ingles, x;
    char idiomaNativo[21];
    //, idiomaConversa[21], idioma;
    size_t tam;

    // n° casos de testes
    scanf("%d", &N);
    scanf("%d", &K);

    fgets(idiomaNativo, 21, stdin);
    tam = strlen(idiomaNativo);

    puts(idiomaNativo);
    printf("%lu\n", tam);
}