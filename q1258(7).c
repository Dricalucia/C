#include <stdio.h>
#include <string.h>

/*Criando a struct */
struct camisetas // definição
{
    char nome[50];
    char cor[15];
    char tam;
};

void ordCor(struct camisetas estudante[], int N);
void ordTam(struct camisetas estudante[], int N);
void ordNome(struct camisetas estudante[], int N);

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

        ordCor(estudante, N);
        ordTam(estudante, N);
        ordNome(estudante, N);

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

void ordCor(struct camisetas estudante[], int N)
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (tolower(estudante[j].cor[0]) > tolower(estudante[j + 1].cor[0]))
            {
                struct camisetas temp = estudante[j];
                estudante[j] = estudante[j + 1];
                estudante[j + 1] = temp;
            }
        }
    }
}

void ordTam(struct camisetas estudante[], int N)
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if ((tolower(estudante[j].cor[0]) == tolower(estudante[j + 1].cor[0])) && (tolower(estudante[j].tam) < tolower(estudante[j + 1].tam)))
            {
                struct camisetas temp = estudante[j];
                estudante[j] = estudante[j + 1];
                estudante[j + 1] = temp;
            }
        }
    }
}

void ordNome(struct camisetas estudante[], int N)
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if ((tolower(estudante[j].cor[0]) == tolower(estudante[j + 1].cor[0])) && (tolower(estudante[j].tam) == tolower(estudante[j + 1].tam)))
            {
                if (strcmp(estudante[j].nome, estudante[j + 1].nome) > 0)
                {
                    {
                        struct camisetas temp = estudante[j];
                        estudante[j] = estudante[j + 1];
                        estudante[j + 1] = temp;
                    }
                }
            }
        }
    }
}