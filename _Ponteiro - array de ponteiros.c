#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NOME_MAX 30
#define TAM_MAX 100

/*Código disponível no livro Treinamento em linguagem C de Victorine Viviane, página 276*/

void ordena(char **p, int n);

int main(void)
{

    char nomes[NOME_MAX][TAM_MAX]; // usado para armazenar a entrada do usuário
    char *p[NOME_MAX];             // array de ponteiros para strings
    int n = 0, i;

    while (1)
    {
        printf("Digite nome ou fim para terminar: ");
        fgets(nomes[n], TAM_MAX, stdin);
        // scanf("%[^\n]s",nomes[n]);
        if (strlen(nomes[n]) == 1)
            break;
        p[n] = nomes[n]; // o ponteiro p recebe a string fornecida pelo usuário
        n++;
    }

    printf("\n\nLista Original: \n");
    for (i = 0; i < n; i++)
    { // varrendo o array original
        printf("%s", nomes[i]);
    }
    ordena(p, n); // chamada da função de ordenação
    printf("\n\nLista Ordenada: \n");

    for (i = 0; i < n; i++)
    {
        printf("%s", p[i]); // novo array de ponteiros ordenado
    }

    return 0;
}

void ordena(char **p, int n)
{
    char *temp;
    int i, j;

    for (i = 0; i < n - 1; i++)
    { // linhas de strings
        for (j = i + 1; j < n; j++)
        { // próxima linha de strings
            if (strcmp(p[i], p[j]) > 0)
            { // verifica se a string da linha atual vem depois da próxima na ordem alfabética
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }
}