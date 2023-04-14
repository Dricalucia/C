#include <stdio.h>
#include <string.h>

struct dados
{
    char nome[50];
    char sobrenome[50];
    char cidade[50];
};

void ordena(struct dados pessoa[], int tamanho)
{
    struct dados temp;
    int i, j;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if (strcmp(pessoa[i].nome, pessoa[j].nome) > 0)
            {
                temp = pessoa[i];
                pessoa[i] = pessoa[j];
                pessoa[j] = temp;
            }
            else if (strcmp(pessoa[i].nome, pessoa[j].nome) == 0)
            {
                if (strcmp(pessoa[i].sobrenome, pessoa[j].sobrenome) < 0)
                {
                    temp = pessoa[i];
                    pessoa[i] = pessoa[j];
                    pessoa[j] = temp;
                }
                else if (strcmp(pessoa[i].sobrenome, pessoa[j].sobrenome) == 0)
                {
                    if (strcmp(pessoa[i].cidade, pessoa[j].cidade) > 0)
                    {
                        temp = pessoa[i];
                        pessoa[i] = pessoa[j];
                        pessoa[j] = temp;
                    }
                }
            }
        }
    }
}

int main()
{
    struct dados pessoa[3];
    int i;

    // Entrada de dados
    for (i = 0; i < 3; i++)
    {
        printf("Digite o nome da %dª pessoa: ", i + 1);
        scanf("%s", pessoa[i].nome);
        printf("Digite o sobrenome da %dª pessoa: ", i + 1);
        scanf("%s", pessoa[i].sobrenome);
        printf("Digite a cidade da %dª pessoa: ", i + 1);
        scanf("%s", pessoa[i].cidade);
        printf("\n");
    }

    // Ordenação dos dados
    ordena(pessoa, 3);

    // Saída dos dados ordenados
    printf("Dados ordenados:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s %s, %s\n", pessoa[i].nome, pessoa[i].sobrenome, pessoa[i].cidade);
    }

    return 0;
}
