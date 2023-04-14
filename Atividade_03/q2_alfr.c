#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int N, i, j, letra;
    char texto[201];

    scanf("%d", &N);
    getchar();
    i = 0;
    while (i < N)
    {
        int contv = 0;
        int contLetras[26] = {0};
        int maiorfreq = 0;

        fgets(texto, 201, stdin);

        // Converte para minúsculas
        for (j = 0; texto[j] != '\n'; j++)
        {
            letra = tolower(texto[j]);
            // conta a frequencia das letras no texto
            if (letra >= 'a' && letra <= 'z')
            {
                contLetras[letra - 'a'] += 1;
            }
        }

        // encontra a maior frequencia
        for (j = 0; j < 26; j++)
        {
            if (contLetras[j] > maiorfreq)
            {
                maiorfreq = contLetras[j];
            }

            if (contLetras[j] != 0)
            {
                contv += 1;
            }
        }

        int auxLetras[contv];
        int indAux = 0;
        for (j = 0; j < 26; j++)
        {
            if (contLetras[j] == maiorfreq)
            {
                auxLetras[indAux] = j + 'a';
                indAux += 1;
            }
        }

        // ordenar o vetor
        int l, m, o, temp, tam;
        tam = indAux;

        for (int m = 0; m < (tam - 1); m++)
        {
            for (int o = m + 1; o < (tam - 1); o++)
            {
                if (auxLetras[m] > auxLetras[o])
                {
                    temp = auxLetras[m];
                    auxLetras[m] = auxLetras[o];
                    auxLetras[o] = temp;
                }
            }
        }
        for (l = 0; l < tam; l++)
        {
            printf("%c", auxLetras[l]);
        }
        printf("\n");
        i += 1;
    }
}
