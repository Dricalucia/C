#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int N, i, j, letra;
    char texto[201];

    // quantidade de casos de teste.
    scanf("%d", &N);
    getchar();
    i = 0;
    while (i < N)
    {
        int contv = 0;
        int contLetras[26] = {0};
        // int frequencia[2][26] = {0}; // usando matriz
        int maiorfreq = 0;

        // fgets(texto, sizeof(texto), stdin);
        fgets(texto, 201, stdin);

        // Converte para minúsculas
        for (j = 0; texto[j] != '\n'; j++)
        {
            letra = tolower(texto[j]);
            if (letra >= 'a' && letra <= 'z')
            {
                // frequencia[0][letra - 'a'] += letra;
                // frequencia[1][letra - 'a'] += 1;
                contLetras[letra - 'a'] += 1;
            }
        }

        for (j = 0; j < 26; j++)
        {
            // encontra a maior frequencia
            if (contLetras[j] > maiorfreq)
            {
                maiorfreq = contLetras[j];
            }

            if (contLetras[j] != 0)
            {
                contv += 1;
            }
        }

        // cria vetor só com as letras que tiveram frequencia
        int auxLetras[contv];
        for (j = 0; j < 26; j++)
        {
            if (contLetras[j] != 0)
            {
                auxLetras[i] = contLetras[j];
            }
        }
        for (j = 0; j < contv; j++)
        {
        }

        // se o valor do vetor contLetras for igual maiorfrequencia
        // ordenar o vetor com base na maiorfrequencia
        // criar um vetor auxiliar

        printf("%d\n", maiorfreq);

        for (j = 0; j < 26; j++)
        {
            if (contLetras[j] != 0)
            {
                printf(" %c-%d", j + 'a', contLetras[j]);
            }
        }

        printf("\n");
        for (j = 0; j < 26; j++)
        {
            if (contLetras[j] != 0)
            {
                printf(" [%c]-[%d]", j + 'a', frequencia[1][j]);
            }
        }

        printf("\n");
        // ordenar o contador pela maior ocorrencia

        // se todas as ocorrencias forem iguais, imprimir as letras em ordem alfabética).
        i += 1;
    }
}