#include <stdio.h>
#include <string.h>
#include <ctype.h>

// int ordena(int vetFreq[], int tam);

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
        // int frequencia;
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
        // printf("%d\n", maiorfreq);

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

        // ordenar o vetor auxLetras
        // imprimir vetor

        // frequencia = ordena(auxLetras, (indAux - 1));

        // ordenar o vetor
        int l, m, o, temp, tam;
        tam = indAux;

        // for (l = 0; l < tam; l++)
        //{
        //     printf("%c", auxLetras[l]);
        // }

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

/*
int ordena(int vetFreq[], int tam)
{
    int aux;
    int l, m, n;

    // ordenar o vetor
    int temp = 0;
    for (int m = 0; m < (tam - 1); m++)
    {
        for (int n = m + 1; m < tam)
            ; n++)
        {
            if (vetFreq[m] > vetorResultado[n])
            {
                temp = vetorResultado[m];
                vetorResultado[m] = vetorResultado[n];
                vetorResultado[n] = temp;
            }
        }
    }

    for (l = 0; l < tam; l++)
    {
        printf(" %c", vetorResultado[l]);
    }

    return;
}
*/
