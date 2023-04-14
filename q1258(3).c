#include <stdio.h>
#include <string.h>

/*
RESPOSTA DO BEECROWD:
Accepted

*/

/*Criando a struct */
struct camisetas // definição
{
    char nome[50];
    char cor[15];
    char tam;
};

void ordena(struct camisetas estudante[], int N);

int main()
{
    int N, i, j;

    /*Criando a variável estudante que será do tipo struct camisetas */
    struct camisetas estudante[60];

    scanf("%d", &N);
    getchar();

    while (N != 0)
    {
        for (i = 0; i < N; i++)
        {
            /* recebendo os dados */
            scanf(" %[^\n]", estudante[i].nome);
            scanf("%s %c", estudante[i].cor, &estudante[i].tam);
        }

        /* ordenar struct por (ordem exibição):
        - cor (ordem ascendente)
        - tamanho (ordem descendente) e
        - nome (ordem ascendente)
        */

        ordena(estudante, N);

        // imprimir struct ordenada
        for (j = 0; j < N; j++)
        {
            printf("%s %c %s\n", estudante[j].cor, estudante[j].tam, estudante[j].nome);
        }

        scanf("%d", &N);
        if (N != 0)
        {
            printf("\n");
        }
    }
    return 0;
}

void ordena(struct camisetas estudante[], int N)
{
    int j;
    for (int i = 1; (i < N); i++)
    {
        j = i - 1;
        struct camisetas aux = estudante[i];
        while (j >= 0 && strcmp(estudante[j].nome, aux.nome) > 0)
        {
            estudante[j + 1] = estudante[j];
            j--;
        }
        estudante[j + 1] = aux;
    }

    for (int i = 1; (i < N); i++)
    {
        j = i - 1;
        struct camisetas aux = estudante[i];
        while (j >= 0 && strcmp(estudante[j].cor, aux.cor) > 0)
        {
            estudante[j + 1] = estudante[j];
            j--;
        }
        estudante[j + 1] = aux;
    }

    for (int i = 1; (i < N); i++)
    {
        j = i - 1;
        struct camisetas aux = estudante[i];

        while (j >= 0 && estudante[j].tam < aux.tam)
        {
            estudante[j + 1] = estudante[j];
            j--;
        }
        estudante[j + 1] = aux;
    }
}