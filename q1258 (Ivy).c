#include <stdio.h>
#include <string.h>

struct Camisa
{
    char nome[100];
    char cor[20];
    char tamanho;
};

int main()
{
    int N;

    struct Camisa camisas[60];

    scanf("%d", &N);
    while (1)
    {

        if (N == 0)
            break;

        for (int i = 0; i < N; i++)
        {

            scanf(" %[^\n]", camisas[i].nome);
            scanf("%s %c", camisas[i].cor, &camisas[i].tamanho);
        }

        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (camisas[i].cor[0] > camisas[j].cor[0])
                {
                    struct Camisa temp = camisas[i];
                    camisas[i] = camisas[j];
                    camisas[j] = temp;
                }
                else if (camisas[i].cor[0] == camisas[j].cor[0] && camisas[i].tamanho < camisas[j].tamanho)
                {
                    struct Camisa temp = camisas[i];
                    camisas[i] = camisas[j];
                    camisas[j] = temp;
                }
                else if (camisas[i].cor[0] == camisas[j].cor[0] && camisas[i].tamanho == camisas[j].tamanho)
                {
                    for (int k = 0; k < strlen(camisas[i].nome); k++)
                    {
                        if (camisas[i].nome[k] > camisas[j].nome[k])
                        {
                            struct Camisa temp = camisas[i];
                            camisas[i] = camisas[j];
                            camisas[j] = temp;
                            break;
                        }
                        else if (camisas[i].nome[k] < camisas[j].nome[k])
                        {
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            printf("%s %c %s\n", camisas[i].cor, camisas[i].tamanho, camisas[i].nome);
        }

        scanf("%d", &N);
        if (N != 0)
        {
            printf("\n");
        }
    }

    return 0;
}