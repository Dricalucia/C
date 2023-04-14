#include <stdio.h>
#include <string.h>

//BEECROWD WRONG ANSWER (0%)


/*Criando a struct */
struct camisetas // definição
{
    char nome[50];
    char cor[10];
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
    int i, j;

    //  while (status == 1)
    //  {
    status = 0;
    for (int i = 0; i < ultimo; i++)
    {
        if (strncmp(estudante[i].cor, estudante[i + 1].cor, 1) > 0)
        {
            status = 1;
            struct camisetas aux = estudante[i];
            estudante[i] = estudante[i + 1];
            estudante[i + 1] = aux;
        }
        else if ((strncmp(estudante[i].cor, estudante[i + 1].cor, 1) == 0) && (strcmp(estudante[i].tam, estudante[i + 1].tam) < 0))
        {
            status = 1;
            struct camisetas aux = estudante[i];
            estudante[i] = estudante[j];
            estudante[j] = aux;
        }
        else if ((strcmp(estudante[i].cor, estudante[i + 1].cor) == 0) && (strcmp(estudante[i].tam, estudante[i + 1].tam) == 0) && (strcmp(estudante[i].nome, estudante[i + 1].nome) > 0))
        {
            status = 1;
            struct camisetas aux = estudante[i];
            estudante[i] = estudante[i + 1];
            estudante[i + 1] = aux;
            ;
        }

        //           ultimo--;
        //       }
    }
}
