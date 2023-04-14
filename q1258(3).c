#include <stdio.h>
#include <string.h>

/*Criando a struct */
struct camisetas // definição
{
    char nome[50];
    char cor[15];
    char tam;
};

void ordenar(struct camisetas estudante[], int N);

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

        ordenar(estudante, N);

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

void ordenar(struct camisetas estudante[], int N)
{
    struct camisetas aux;
    int status = 1, ultimo = N - 1;
    int m, o;

    while (status == 1)
    {
        status = 0;

        for (int m = 0; m < ultimo; m++)
        {
            for (int o = m + 1; o < ultimo; o++)
            {
                if (strcmp(estudante[m].cor, estudante[o].cor) > 0)
                {
                    status = 1;
                    aux = estudante[m];
                    estudante[m] = estudante[o];
                    estudante[o] = aux;
                }
                else if ((strcmp(estudante[m].cor, estudante[o].cor) == 0) && (strcmp(estudante[m].tam, estudante[o].tam) < 0))
                {
                    status = 1;
                    aux = estudante[m];
                    estudante[m] = estudante[o];
                    estudante[o] = aux;
                }
                else if ((strcmp(estudante[m].cor, estudante[o].cor) == 0) && (strcmp(estudante[m].tam, estudante[o].tam) == 0) && (strcmp(estudante[m].nome, estudante[o].nome) > 0))
                {
                    status = 1;
                    aux = estudante[m];
                    estudante[m] = estudante[o];
                    estudante[o] = aux;
                }
            }
            ultimo--;
        }
    }
}
