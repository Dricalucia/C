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
    int i, j;
    while (status == 1)
    {
        status = 0;
        for (int i = 0; i < ultimo; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (strcmp(estudante[i].cor, estudante[j].cor) > 0)
                {
                    status = 1;
                    aux = estudante[i];
                    estudante[i] = estudante[j];
                    estudante[j] = aux;
                }
                else if ((strcmp(estudante[i].cor, estudante[j].cor) == 0) && (estudante[i].tam < estudante[j].tam))
                {
                    status = 1;
                    aux = estudante[i];
                    estudante[i] = estudante[j];
                    estudante[j] = aux;
                }
                else if ((strcmp(estudante[i].cor, estudante[j].cor) == 0) && (estudante[i].tam == estudante[j].tam) && (strcmp(estudante[i].nome, estudante[j].nome) > 0))
                {
                    status = 1;
                    aux = estudante[i];
                    estudante[i] = estudante[j];
                    estudante[j] = aux;
                }
            }
            ultimo--;
        }
    }
}