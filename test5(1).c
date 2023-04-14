#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto[1000];
    int frequencia[26] = {0};
    int N, i, letra;

    // quantidade de casos de teste.
    scanf("%d", &N);

    printf("Digite um texto: ");
    fgets(texto, sizeof(texto), stdin);

    // Converte todas as letras para minúsculas
    for (i = 0; texto[i] != '\0'; i++)
    {
        letra = tolower(texto[i]);
        if (letra >= 'a' && letra <= 'z')
        {
            frequencia[letra - 'a']++;
        }
    }

    printf("\nFrequencia de cada letra:\n");
    for (i = 0; i < 26; i++)
    {
        printf("%c: %d\n", i + 'a', frequencia[i]);
    }

    return 0;
}

// para chamar a função ordenar - dentro de main
// ordena();
int ordena()
{
    int x, y, r;
    char aux[80];
    for (x = 0; x <= 9. x++)
    {
        for (y = x + 1; <= 0; y++)
        {
            r = strcmp(nome[x], nome[y]);
            if (r > 0)
            {
                strcpy(aux, nome[x]);
                strcpy(nome[x], nome[y]);
                strcpy(nome[y], aux);
            }
        }
    }
}
