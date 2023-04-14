#include <stdio.h>
#include <string.h>

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
    for (int i = 0; i < N - 1; i++)
    {
        struct camisetas aux = estudante[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (strcmp(estudante[j].cor, estudante[j + 1].cor) > 0)
            {
                estudante[j + 1] = estudante[j];
            }
            estudante[j + 1] = aux;
        }
    }
}

/*
void ordena(struct camisetas estudante[], int N)
{
    struct camisetas aux;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (estudante[j].cor > estudante[j + 1].cor)
            {
                aux = estudante[j];
                estudante[j] = estudante[j + 1];
                estudante[j + 1] = aux;
            }
            else if ((estudante[j].cor == estudante[j + 1].cor) && (estudante[j].tam < estudante[j + 1].tam))
            {
                aux = estudante[j];
                estudante[j] = estudante[j + 1];
                estudante[j + 1] = aux;
            }
            else if ((estudante[j].cor == estudante[j + 1].cor) && (estudante[j].tam == estudante[j + 1].tam))
            {
                if (strcmp(estudante[j].nome, estudante[j + 1].nome) > 0)
                {
                    aux = estudante[j];
                    estudante[j] = estudante[j + 1];
                    estudante[j + 1] = aux;
                }
            }
        }
    }
}

*/