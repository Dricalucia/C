#include <stdio.h>
#include <string.h>

/*Criando a struct */
struct camisetas // definição
{
    char nome[50];
    char cor[15];
    char tam;
};

// void ordNome(struct camisetas estudante[], int N);
void ordTam(struct camisetas estudante[], int N);
void ordCor(struct camisetas estudante[], int N);

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
        // ordNome(estudante, N);
        ordCor(estudante, N);
        ordTam(estudante, N);

        // imprimir struct ordenada
        for (j = 0; j < N; j++)
        {
            printf("%s %c %s\n", estudante[j].cor, estudante[j].tam, estudante[j].nome);
        }
        if (N != 0)
        {
            printf("\n");
        }
        scanf("%d", &N);
    }
    return 0;
}

// ordena a cor
void ordCor(struct camisetas estudante[], int N)
{
    struct camisetas aux;
    int status = 1;
    int ultimo = N - 1;

    while (status == 1)
    {
        status = 0;
        for (int i = 0; i < ultimo; i++)
        {
            if (strcmp(estudante[i].cor, estudante[i + 1].cor) > 0)
            {
                status = 1;
                aux = estudante[i];
                estudante[i] = estudante[i + 1];
                estudante[i + 1] = aux;
            }
        }
        ultimo--;
    }
}

// ordena tamanho
void ordTam(struct camisetas estudante[], int N)
{
    struct camisetas aux;
    int status = 1;
    int ultimo = N - 1;

    while (status == 1)
    {
        status = 0;
        for (int i = 0; i < ultimo; i++)
        {
            // ordena decrescente
            if (strcmp(estudante[i].tam, estudante[i + 1].tam) < 0)
            {
                status = 1;
                aux = estudante[i];
                estudante[i] = estudante[i + 1];
                estudante[i + 1] = aux;
            }
        }
        ultimo--;
    }
}

/*
// ordenar por nome (NÃO ESTA EXECUTANDO CORRETO!)
void ordNome(struct camisetas estudante[], int N)
{
    struct camisetas aux;
    int status = 1;
    int ultimo = N - 1;

    while (status == 1)
    {
        status = 0;
        for (int i = 0; i < ultimo; i++)
        {
            // ordena crescente
            if (strcmp(estudante[i].nome, estudante[i + 1].nome) > 0)
            {
                status = 1;
                aux = estudante[i];
                estudante[i] = estudante[i + 1];
                estudante[i + 1] = aux;
            }
        }
        ultimo--;
    }
}
*/