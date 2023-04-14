#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto[1000];
    int frequencia[26] = {0};
    int i, letra;

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
