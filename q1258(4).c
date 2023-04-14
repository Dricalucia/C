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

        struct camisetas aux;
        int m, o;

        for (int m = 0; m < (N - 1); m++)
        {
            for (int o = m + 1; o < (N - 1); o++)
            {
                if (strncmp(estudante[m].cor, estudante[o].cor, 1) > 0)
                {

                    aux = estudante[m];
                    estudante[m] = estudante[o];
                    estudante[o] = aux;
                }
                else if ((strncmp(estudante[m].cor, estudante[o].cor, 1) == 0) && (strcmp(estudante[m].tam, estudante[o].tam) < 0))
                {

                    aux = estudante[m];
                    estudante[m] = estudante[o];
                    estudante[o] = aux;
                }
                else if ((strncmp(estudante[m].cor, estudante[o].cor, 1) == 0) && (strcmp(estudante[m].tam, estudante[o].tam) == 0) && (strcmp(estudante[m].nome, estudante[o].nome) > 0))
                {
                    aux = estudante[m];
                    estudante[m] = estudante[o];
                    estudante[o] = aux;
                }
            }
        }

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
