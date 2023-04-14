#include <stdio.h>
#include <string.h>
#include <ctype.h>

// int ordena(int num[]);

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

        int maiorfreq = 0;
        // qtdfreq = 0;

        fgets(texto, 201, stdin);

        // Converte para minúsculas e conta a frequencia (ok)
        for (j = 0; texto[j] != '\n'; j++)
        {
            letra = tolower(texto[j]);
            if (letra >= 'a' && letra <= 'z')
            {
                contLetras[letra - 'a'] += 1;
            }

            // encontra a maior frequencia
            if (contLetras[letra - 'a'] > maiorfreq)
            {
                maiorfreq = contLetras[j];
            }
        }

        // TESTAR A PARTIR DAQUI!

        // conta a qtde letras do texto
        for (j = 0; j < 26; j++)
        {

            if (contLetras[j] != 0)
            {
                contv += 1;
            }
        }

        int frequencia[2][contv];
        // int auxm[2][contv];
        int indm = 0;

        for (j = 0; j < 26; j++)
        {

            // Insere numa matriz o indice da letra e qtde frequencia
            if (contLetras[j] != 0)
            {
                frequencia[0][indm] = j - 'a';
                frequencia[1][indm] = contLetras[j];
                indm += 1;
            }
        }

        // ordenar vetor
        // ordena(frequencia);

        // conta as letras que fazem parte do texto
        for (j = 0; j < 26; j++)
        {
            if (contLetras[j] != 0)
            {
                contv += 1;
            }
        }

        // cria uma matriz com as letras que foram contadas no texto
        /*
        int frequencia[2][contv] = {0}; // usando matriz
        int x = 0
            // imprima uma linha contendo a(s) letra(s) que mais ocorreu
        for (j = 0; j < 26; j++)
        {
            if (contLetras[j] != 0)
            {
                frequencia[0][x] += letra;
                frequencia[1][letra - 'a'] = contLetras[j];
            }
        }
        */

i        printf("\n");
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
/*
c:72:16: warning: passing argument 1 of 'ordena' from incompatible pointer type [-Wincompatible-pointer-types]
     ordena(frequencia);
int ordena(int matriz[])
{

    int i, j, aux;
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (numero > numero[j])
            {
                aux = numero;
                numero = numero[j];
                numero[j] = aux;
            }
        }
    }
    printf("\nOrdenado com sucesso!");

}
*/