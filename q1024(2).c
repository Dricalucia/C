#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, j, ind, cont = 0;
    char mensagem[1001], aux[1001];
    unsigned long tam;

    scanf("%d", &N);

    // erro no replit: Segmentation fault (core dumped)
    while (cont < N)
    {
        // recebe a mensagem
        fgets(mensagem, 1001, stdin);
        tam = strlen(mensagem);
        printf("%lu", tam);

        for (i = 0; i < tam; i++)
        {
            // 1° - desloca 3 posições para a direita
            if ((mensagem[i] >= 'A' && mensagem[j] <= 'Z') || (mensagem[i] >= 'a' && mensagem[i] <= 'z'))
            {
                mensagem[i] = mensagem[i] + 3;
            }
            else
            {
                mensagem[i] = mensagem[i];
            }
        }
        // ate aqui esta correto
        mensagem[j] = "\0";

        // 2° - invertendo os caracteres
        ind = 0;
        for (j = tam - 1; j >= 0; j--)
        {
            aux[ind] = mensagem[j];
            ind += 1;
        }
        aux[ind] = "\0";
        printf("%s", aux);

        // 3° - desloca, da metade em diante, uma posição da direita para esquerda
        for (j = (tam / 2) - 1; (j < tam); j++)
        {
            aux[j] = aux[j] - 1;
        }
        strcpy(mensagem, aux);

        printf("%s\n", mensagem);
        cont += 1;
    }
}