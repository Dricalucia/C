#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, j, k, cont = 0, tamanho;
    char mensagem[1001], auxiliar;
    size_t tam;

    scanf("%d\n", &N);

    while (cont < N)
    {
        // recebe a mensagem
        fgets(mensagem, 1001, stdin);
        tam = strlen(mensagem) - 1;

        for (i = 0; i < tam; i++)
        {
            // 1° - desloca 3 posições para a direita
            if ((mensagem[i] >= 'A' && mensagem[i] <= 'Z') || (mensagem[i] >= 'a' && mensagem[i] <= 'z'))
            {
                mensagem[i] = mensagem[i] + 3;
            }
            else
            {
                mensagem[i] = mensagem[i];
            }
        }

        // 2° - invertendo os caracteres
        for (i = 0, j = (tam - 1); i < (tam / 2); i++, j--)
        {
            auxiliar = mensagem[i];
            mensagem[i] = mensagem[j];
            mensagem[j] = auxiliar;
        }

        // 3° - desloca, da metade em diante, uma posição da direita para esquerda
        for (k = (tam / 2); (k < tam); k++)
        {
            mensagem[k] = mensagem[k] - 1;
        }
        printf("%s", mensagem);
        cont += 1;
    }
}
