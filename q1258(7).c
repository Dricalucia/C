#include <stdio.h>
#include <string.h>

// ate tres ordena correto, o teste com 9 não

/*Criando a struct */
struct camisetas // definição
{
    char nome[50];
    char cor[15];
    char tam;
};

// void ordenar(struct camisetas estudante[], int N);
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

        // ordenar(estudante, N);

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
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (tolower(estudante[i].cor) > tolower(estudante[j].cor))
            {
                struct camisetas temp = estudante[i];
                estudante[i] = estudante[j];
                estudante[j] = temp;
            }
        }
    }
}

void ordTam(struct camisetas estudante[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if ((tolower(estudante[i].cor) == tolower(estudante[j].cor)) && (tolower(estudante[i].tam) < tolower(estudante[j].tam)))
            {
                struct camisetas temp = estudante[i];
                estudante[i] = estudante[j];
                estudante[j] = temp;
            }
        }
    }
}

void ordNome(struct camisetas estudante[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if ((estudante[i].tam == estudante[j].tam) && (estudante[i].tam > estudante[j].tam))
            {
                struct camisetas temp = estudante[i];
                estudante[i] = estudante[j];
                estudante[j] = temp;
            }
        }
    }
}

/*
void ordenar(struct camisetas estudante[], int N)
{
    struct camisetas temp;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (estudante[i].cor > estudante[j].cor)
            {
                temp = estudante[i];
                estudante[i] = estudante[j];
                estudante[j] = temp;
            }
            else if (estudante[i].cor == estudante[j].cor)
            {
                if (estudante[i].tam < estudante[j].tam)
                {
                    temp = estudante[i];
                    estudante[i] = estudante[j];
                    estudante[j] = temp;
                }
                else if (estudante[i].tam == estudante[j].tam)
                {
                    if (strcmp(estudante[i].nome, estudante[j].nome) > 0)
                    {
                        temp = estudante[i];
                        estudante[i] = estudante[j];
                        estudante[j] = temp;
                    }
                }
            }
        }
    }
}
*/