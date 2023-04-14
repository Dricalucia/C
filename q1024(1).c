#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, j, ind, cont = 0;
    unsigned long tam;
    scanf("%d", &N);
    char mensagem[N][1001], aux[N][1001];

    // erro no replit: Segmentation fault (core dumped)
    while (cont < N)
    {

        // recebe a mensagem
        fgets(mensagem[cont], 1001, stdin);
        tam = strlen(mensagem);

        for (i = 0; i < tam; i++)
        {
            // 1° - desloca 3 posições para a direita
            if ((mensagem[j] >= 'A' && mensagem[j] <= 'Z') || (mensagem[i] >= 'a' && mensagem[i] <= 'z'))
            {
                mensagem[j] = mensagem[j] + 3;
            }
            else
            {
                mensagem[j] = mensagem[j];
            }
        }

        // 2° - invertendo os caracteres
        ind = 0;
        for (j = tam - 1; j >= 0; j--)
        {
            aux[ind] = mensagem[j];
            ind += 1;
        }

        // 3° - desloca, da metade em diante, uma posição da direita para esquerda
        for (j = (tam / 2); (j < tam); j++)
        {
            aux[j] = aux[j] - 1;
        }
        strcpy(mensagem, aux);

        printf("%c\n", mensagem);
        cont += 1;
    }
}