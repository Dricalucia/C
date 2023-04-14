#include <stdio.h>
#include <string.h>

/*Criando a struct */
struct camisetas // definição
{
    char nome[50];
    char cor[15];
    char tam;
};

int main()
{
    int N, i, j;

    /*Criando a variável estudante que será do tipo struct camisetas */
    struct camisetas estudante[60];

    scanf("%d", &N);

    while (N != 0)
    {
        if (N == 0)
        {
            break;
        }

        for (i = 0; i < N; i++)
        {
            /* recebendo os dados */
            scanf(" %[^\n]", estudante[i].nome);
            // scanf("%s", &(estudante[i].nome));
            scanf("%s %c", estudante[i].cor, &estudante[i].tam);
        }

        /* ordenar struct por:
        - cor (ordem ascendente)
        - tamanho (ordem descendente) e
        - nome (ordem ascendente)

        */

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
